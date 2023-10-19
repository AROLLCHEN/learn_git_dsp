
#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "epwm.h"

#define POST_SHIFT   0  // Shift results after the entire sample table is full
#define INLINE_SHIFT 1  // Shift results as the data is taken from the results regsiter
#define NO_SHIFT     0  // Do not shift the results

// ADC start parameters
#if (CPU_FRQ_150MHZ)     // Default - 150 MHz SYSCLKOUT
  #define ADC_MODCLK 0x3 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
#endif
#if (CPU_FRQ_100MHZ)
  #define ADC_MODCLK 0x2 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*2)   = 25.0 MHz
#endif
#define ADC_CKPS   0x0   // ADC module clock = HSPCLK/1      = 25.5MHz/(1)   = 25.0 MHz
#define ADC_SHCLK  0x1   // S/H width in ADC module periods                  = 2 ADC cycle
#define AVG        1000  // Average sample limit
#define ZOFFSET    0x00
#define BUF_SIZE   6


volatile Uint16 SampleTable[BUF_SIZE];
volatile float adc0=0;
volatile float adc1=0;
volatile float adc2=0;



Uint32 t1=0,t2=0,t3=0,t4=0,T1=0,T2=0,t5,t6,t7,t8,T3,T4,i,led=0,freq=0,duty=1,T1_temp=1,T2_temp=1;

interrupt void epwm_int(void);
void InitCapl();
Uint16 array_index;


void main(void)
{


   InitSysCtrl();

   EALLOW;
   SysCtrlRegs.HISPCP.all = ADC_MODCLK; //  ϵͳ����ʱ��6��Ƶ��һ��ADC����6��Ƶ
                                        //  ������ΪADC���ֻ������25MHz��Ƶ��
                                        //  �������ת��һ�ε�ʱ��ʹ80ns
   EDIS;

   InitXintf16Gpio();


   DINT;

   InitPieCtrl();

   IER = 0x0000;
   IFR = 0x0000;

   InitPieVectTable();

//   InitAdc();                                  //�����ʼ�����򣬱������DSP2833x_Adc.C�ļ�
//
//     EALLOW;
//     PieVectTable.EPWM1_INT = &epwm_int;
//     EDIS;
//
//      IER |= M_INT3;
//     //IER |= M_INT14;
//
//      PieCtrlRegs.PIEIER3.bit.INTx1 = 1;
//      EINT;
//      ERTM;
//
//      AdcRegs.ADCTRL1.bit.ACQ_PS = ADC_SHCLK;     //ADC����ʱ��ѡ��
//      AdcRegs.ADCTRL3.bit.ADCCLKPS = ADC_CKPS;    //ADC�ں˷�Ƶ
//      AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;           //����������ʽ
//      AdcRegs.ADCTRL3.bit.SMODE_SEL= 0;           // ˳�����
//      AdcRegs.ADCTRL1.bit.CONT_RUN = 1;            //��������
//      AdcRegs.ADCTRL1.bit.SEQ_OVRD = 1 ;           //��������������ָ��ص����״̬
//
//      AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 0x2;
//      AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
//      AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1 ;
//      AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2 ;
//      AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1; //�������ת������
//      AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 0x1; //������CPU�����ж�����
//
//      for (i=0; i<BUF_SIZE; i++)
//      {
//        SampleTable[i] = 0;
//
//      }


   EPwmSetup();


//    for(; ;)
//    {
//
//    }

}

interrupt void epwm_int(void)
{

    led++;
    if(led==100)
    {led=0;}
          if(array_index>BUF_SIZE)
                array_index = 0;

            while(AdcRegs.ADCST.bit.INT_SEQ1 == 1);                 //�ȴ�ADC���ж�λΪ1
            AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;                     //����������ж�λ


            SampleTable[array_index++]= ( (AdcRegs.ADCRESULT0)>>4);
            SampleTable[array_index++]= ( (AdcRegs.ADCRESULT1)>>4);
            SampleTable[array_index++]= ( (AdcRegs.ADCRESULT2)>>4);
            adc0=(float)SampleTable[0] * 3.0 /4096.0;               // ת��Ϊ���Ƕ�ȡ����������
            adc1=(float)SampleTable[1] * 3.0 /4096.0;               // ��������ת������һƪ��˵��
            adc2=(float)SampleTable[2] * 3.0 /4096.0;


    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
      EPwm1Regs.ETCLR.bit.INT=1;

}
