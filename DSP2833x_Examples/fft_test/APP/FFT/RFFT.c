/*
 * RFFT.c
 *
 *  Created on: 2022年11月2日
 *      Author: Administrator
 */


#include "dsp.h"
#include "fpu_rfft.h"
#include "RFFT.h"
#include <math.h>
#include "complex.h"

#define Fs 1000
#define FFT_STAGES      (10U)   //迭代次数 =Log2(FFT_SIZE)
#define FFT_SIZE        (1 << FFT_STAGES)  //FFT计算点数

RFFT_F32_STRUCT rfft;
RFFT_ADC_F32_STRUCT rfft_adc;
RFFT_F32_STRUCT_Handle hnd_rfft = &rfft;
RFFT_ADC_F32_STRUCT_Handle hnd_rfft_adc = &rfft_adc;
RFFT_Analyse_Struct rfft_analyse;

//#pragma DATA_SECTION(FFT_input, "FFT_buffer");
#pragma DATA_SECTION(FFT_output, "FFT_buffer1");
#pragma DATA_SECTION(FFT_twiddleFactors, "FFT_buffer2");
#pragma DATA_SECTION(FFT_magnitude_phase, "FFT_buffer3");

//uint16_t FFT_input[FFT_SIZE];
extern uint16_t FFT_input[2U*FFT_SIZE];
float FFT_twiddleFactors[FFT_SIZE];
float FFT_output[FFT_SIZE];
float FFT_magnitude_phase[(FFT_SIZE >> 1) + 1];


#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))


float myabs;

void RFFT_ADC_Init()
{

    RFFT_f32_setInputPtr(hnd_rfft, (float *)FFT_input);
    RFFT_f32_setOutputPtr(hnd_rfft, FFT_output);
    RFFT_f32_setStages(hnd_rfft,  FFT_STAGES);
    RFFT_f32_setFFTSize(hnd_rfft, FFT_SIZE);
    RFFT_f32_setMagnitudePtr(hnd_rfft, FFT_magnitude_phase);
    RFFT_f32_setPhasePtr(hnd_rfft, FFT_magnitude_phase);

    RFFT_f32_setTwiddlesPtr(hnd_rfft, FFT_twiddleFactors);
    RFFT_f32_sincostable(hnd_rfft);

    RFFT_ADC_f32_setTailPtr(hnd_rfft_adc, &(hnd_rfft->OutBuf));
    RFFT_ADC_f32_setInBufPtr(hnd_rfft_adc, FFT_input);


}

void RFFT_ADC_Caculate()
{
    float* temp;

    RFFT_adc_f32(hnd_rfft_adc);
    RFFT_f32_mag(hnd_rfft);
    temp=RFFT_f32_getMagnitudePtr(hnd_rfft);
    RFFT_Analyse(temp);
}

float RFFT_Phase_Caculate(Uint16 index,float ratio)
{
    complex p;
    complex FFT_value;

    p=(1-cexpf((2*M_PI*ratio/FFT_SIZE)*I));
    p=p/ (1-cexpf((2*M_PI*ratio)*I));
    FFT_value=FFT_output[index]+FFT_output[FFT_SIZE-index]*I;
    p=FFT_value*p;

    return (cargf(p)+M_PI/2);
}

Uint16 RFFT_Peak_Find(float *src ,Uint16 len,Uint16 *index) //幅度谱及其长度
{
    Uint16 num=0;
    Uint16 i;
    float max_data=0;
    float data1=0;
    float data2=0;
    float data3=0;


    for (i=1;i<len;i++)
    {
        if(*(src+i)>max_data)
            max_data=*(src+i);
    }
    for (i=1;i<len-1;i++)
    {
        data1=*(src+i-1);
        data2=*(src+i);
        data3=*(src+i+1);
        if((data1<data2) && (data2>data3) && (data2 >max_data*0.1))
        {
            if(num<20)
            {
            *(index+num)=i;
            num++;
            }
            else
                return num;
        }
    }
    return num;
}




float RFFT_Fractional_Frequency(float ratio)
 {
      Uint16 niter;
      float K,f,a,b,y,yp;
      f=0;
      K=(M_PI/FFT_SIZE) * sin(M_PI/FFT_SIZE);
      for(niter=0;niter<20;niter++)
      {
          a  = sin(M_PI*f/FFT_SIZE);
          b  = sin(M_PI*(f-1)/FFT_SIZE);

          y  = ratio - a/b;
          yp = K / (b*b);
          f = MAX(-0.5, MIN(f - y/yp, 0.5));
      }
      return f;
 }


void RFFT_Analyse(float *src)
{
    Uint16 i;
    float ratio;
    float FFT_Value;
    Uint16 peak_index[RFFT_Analyse_MaxNum];

    memset(peak_index, 0U, RFFT_Analyse_MaxNum*sizeof(Uint16));
    memset(rfft_analyse.freq, 0U, RFFT_Analyse_MaxNum*sizeof(float));
    memset(rfft_analyse.Amp, 0U, RFFT_Analyse_MaxNum*sizeof(float));
    memset(rfft_analyse.Phase, 0U, RFFT_Analyse_MaxNum*sizeof(float));

    rfft_analyse.Wave_Num=RFFT_Peak_Find(src,FFT_SIZE/2,peak_index);

    for(i=0;i<rfft_analyse.Wave_Num;i++)
    {
        FFT_Value=*(src+peak_index[i]);
        ratio = (*(src+peak_index[i]+1))/FFT_Value;
        if ((*(src+peak_index[i]+1)) > (*(src+peak_index[i]-1)))
          ratio = -ratio;
        ratio = RFFT_Fractional_Frequency(ratio);
        rfft_analyse.freq[i]  = (*(peak_index+i)-1+ratio)*Fs/FFT_SIZE;
        rfft_analyse.Amp[i]   = 2 *FFT_Value * fabsf(sin(M_PI*ratio/FFT_SIZE)/sin(M_PI*ratio));
        rfft_analyse.Phase[i]  = RFFT_Phase_Caculate(peak_index[i],ratio);
    }
    for(i=0;i<rfft_analyse.Wave_Num;i++)
    {
        rfft_analyse.Phase[i]=rfft_analyse.Phase[i]-rfft_analyse.Phase[0];
        rfft_analyse.Phase[i]=rfft_analyse.Phase[i]*180/M_PI;
    }
    rfft_analyse.DC_Amp=*src/FFT_SIZE;
}






