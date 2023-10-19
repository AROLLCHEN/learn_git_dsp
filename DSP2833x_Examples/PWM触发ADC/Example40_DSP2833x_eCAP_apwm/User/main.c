#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "leds.h"

void InitEPwm1Example();

extern float adcresulta0[1024]; //用于保存ADCINA0通道的10次采样结果
//extern void DSP28x_usDelay(Uint32 Count);

main()
{
   Uint16 i;

   InitSysCtrl();

   DINT;
   InitPieCtrl();
   IER = 0x0000;
   IFR = 0x0000;
   InitPieVectTable();

    for(i=0;i<1024;i++)
	{
	  adcresulta0[i] = 0;
	}

    LED_Init();
   InitEPwm1Example();
   InitAdc();         // For this example, init the ADC

   while(1)
   {
	   LED1_TOGGLE;
	   LED2_TOGGLE;
	   DELAY_US(100000);
   }

}

void InitEPwm1Example()
{
   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;// Disable TBCLK within the ePWM
   EDIS;

   EPwm1Regs.TBPRD = 145;  //1ms  // Set timer  Period =600 TBCLK counts
   EPwm1Regs.TBCTR = 0x0000;      // Clear  TB counter

// Setup TBCLK = SYSCLKOUT / (HSPCLKDIV * CLKDIV)=150/4*4
   EPwm1Regs.TBCTL.bit.CTRMODE = 0x00; //00 Up-count mode;01 Down-count mode;10 Up-down-count mode
   EPwm1Regs.TBCTL.bit.HSPCLKDIV =0x0;   //TB_DIV1;
   EPwm1Regs.TBCTL.bit.CLKDIV = 0x0;     //TBclk = 75MHz

   EPwm1Regs.ETSEL.bit.SOCAEN = 1;        // Enable SOC on A group
   EPwm1Regs.ETSEL.bit.SOCASEL = 2;       // Select SOC from from CPMA on upcount
   EPwm1Regs.ETPS.bit.SOCAPRD = 1;        // Generate pulse on 1st event

   EPwm1Regs.CMPA.half.CMPA =(145+1)/2;//(tbprd+1)/2

   EALLOW;
   GpioDataRegs.GPACLEAR.bit.GPIO13 = 1;
   GpioDataRegs.GPACLEAR.bit.GPIO12 = 1;
   EDIS;

   EALLOW;
   SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;// Enable TBCLK within the ePWM
   EDIS;
}
