// TI File $Revision: /main/4 $
// Checkin $Date: July 30, 2007   14:15:53 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x Header Files V1.01 $
// $Release Date: September 26, 2007 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define ADC_usDELAY  5000L

//ADC start parameters
#if (CPU_FRQ_150MHZ)     // Default - 150 MHz SYSCLKOUT
#define ADC_MODCLK 0x3 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 150/(2*3)   = 25.0 MHz
#endif
#if (CPU_FRQ_100MHZ)
 #define ADC_MODCLK 0x2 // HSPCLK = SYSCLKOUT/2*ADC_MODCLK2 = 100/(2*2)   = 25.0 MHz
#endif

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
interrupt void  adc_isr(void);

void InitAdc(void)
{
    extern void DSP28x_usDelay(Uint32 Count);


    // *IMPORTANT*
	// The ADC_cal function, which  copies the ADC calibration values from TI reserved
	// OTP into the ADCREFSEL and ADCOFFTRIM registers, occurs automatically in the
	// Boot ROM. If the boot ROM code is bypassed during the debug process, the
	// following function MUST be called for the ADC to function according
	// to specification. The clocks to the ADC MUST be enabled before calling this
	// function.
	// See the device data manual and/or the ADC Reference
	// Manual for more information.

	    EALLOW;
		SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
		ADC_cal();
		EDIS;

		   EALLOW;
		   SysCtrlRegs.HISPCP.all = ADC_MODCLK; //存疑
		   EDIS;

		   EALLOW;
		   PieVectTable.ADCINT = &adc_isr;
		   EDIS;

    // Specific ADC setup for this example:
   AdcRegs.ADCTRL1.bit.ACQ_PS = 1;  // Sequential mode: Sample rate   = 1/[(2+ACQ_PS)*ADC clock in ns]
                        //                     = 1/(3*40ns) =8.3MHz (for 150 MHz SYSCLKOUT)
					    //                     = 1/(3*80ns) =4.17MHz (for 100 MHz SYSCLKOUT)
					    // If Simultaneous mode enabled: Sample rate = 1/[(3+ACQ_PS)*ADC clock in ns]

   AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;//1;  0 双排序 // 1  Cascaded mode
          // Setup continuous run
   AdcRegs.ADCTRL3.bit.SMODE_SEL= 0; //0 顺序采样
   AdcRegs.ADCTRL1.bit.SEQ_OVRD = 1;       // Enable Sequencer override feature
   AdcRegs.ADCTRL3.bit.ADCCLKPS = 0;
   AdcRegs.ADCTRL1.bit.CONT_RUN = 0;

//   AdcRegs.ADCMAXCONV.all = 0x0002;       // Setup 1 conv's on SEQ1

   AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0; // Setup ADCINA0 as 1st SEQ1 conv.
//   AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x3;
//   AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x9;

    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;// Enable SOCA from ePWM to start SEQ1
   //AdcRegs.ADCTRL2.bit.EPWM_SOCB_SEQ2 = 1;
   AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 1;  // Enable SEQ1 interrupt (every EOS)
   //AdcRegs.ADCTRL2.bit.INT_ENA_SEQ2 = 1;


    // To powerup the ADC the ADCENCLK bit should be set first to enable
    // clocks, followed by powering up the bandgap, reference circuitry, and ADC core.
    // Before the first conversion is performed a 5ms delay must be observed
	// after power up to give all analog circuits time to power up and settle

    // Please note that for the delay function below to operate correctly the
	// CPU_CLOCK_SPEED define statement in the DSP2833x_Examples.h file must
	// contain the correct CPU clock period in nanoseconds.

    AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
    DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels

    // Enable ADCINT in PIE
    PieCtrlRegs.PIEIER1.bit.INTx6 = 1;
    IER |= M_INT1; // Enable CPU Interrupt 1
    EINT;          // Enable Global interrupt INTM
    ERTM;          // Enable Global realtime interrupt DBGM
}

float adc[1];         //用于存储AD转换结果
float Output0; //用于保存ADCINA0、ADCINA1、ADCINB0、ADCINB1四个通道滤波处理后的采样结果
float adcresulta0[1024]; //用于保存ADCINA0通道的10次采样结果
int SampleCount = 0;      //用于保存采样次数

interrupt void  adc_isr(void)
{
    SampleCount++;

    adc[0] = AdcRegs.ADCRESULT0 >>4;

    adcresulta0[SampleCount-1] = adc[0];

	if(SampleCount==1024)
	{
		Output0 = 0;
		SampleCount = 0;
	}

  // Reinitialize for next ADC sequence
  AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;         // Reset SEQ1
  AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;       // Clear INT SEQ1 bit

  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;   // Acknowledge interrupt to PIE
  EINT;
}
