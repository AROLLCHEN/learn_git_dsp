/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "leds.h"
#include "time.h"
#include "adc.h"
#include "epwm.h"



/*******************************************************************************
* 函 数 名         : main
* 函数功能         : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
    int i=0;
    float adc_vol;

    InitSysCtrl();

    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();

    LED_Init();
    TIM0_Init(150,200000);//200ms
    EPWM1_Init(36);//36
    ADC_Init();

    for (i=0; i<BUF_SIZE; i++)
      {
          SampleTable0[i] = 0;
          SampleTable1[i] = 0;
          SampleTable2[i] = 0;
      }
    while(1)
    {
     if  (SampleDone==1)
     {
         for ( i=0; i<BUF_SIZE-1; i++)
       {
         SampleTable0[i] = SampleTable0[i+1];
         SampleTable1[i] = SampleTable1[i+1];
         SampleTable2[i] = SampleTable2[i+1];

       }
         SampleDone=0;
     }
    }
}

