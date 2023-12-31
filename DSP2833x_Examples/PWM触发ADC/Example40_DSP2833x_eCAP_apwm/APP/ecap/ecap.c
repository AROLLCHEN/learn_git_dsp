/*
 * ecap.c
 *
 *  Created on: 2018��7��3��
 *      Author: Administrator
 */

#include "ecap.h"
#include "epwm.h"

// Prototype statements for functions found within this file.
__interrupt void ecap1_isr(void);
void Fail(void);





// Global variables used in this example
Uint32  ECap1IntCount=0;
Uint32  ECap1PassCount=0;
Uint32  EPwm5TimerDirection=EPWM_TIMER_UP;





void eCAP1_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;  // eCAP1
	EDIS;

	InitECap1Gpio();

	ECap1Regs.ECEINT.all = 0x0000;             // Disable all capture interrupts
	ECap1Regs.ECCLR.all = 0xFFFF;              // Clear all CAP interrupt flags
	ECap1Regs.ECCTL1.bit.CAPLDEN = 0;          // Disable CAP1-CAP4 register loads
	ECap1Regs.ECCTL2.bit.TSCTRSTOP = 0;        // Make sure the counter is stopped

	// Configure peripheral registers
	ECap1Regs.ECCTL2.bit.CONT_ONESHT = 1;      // One-shot
	ECap1Regs.ECCTL2.bit.STOP_WRAP = 3;        // Stop at 4 events
	ECap1Regs.ECCTL1.bit.CAP1POL = 1;          // Falling edge
	ECap1Regs.ECCTL1.bit.CAP2POL = 0;          // Rising edge
	ECap1Regs.ECCTL1.bit.CAP3POL = 1;          // Falling edge
	ECap1Regs.ECCTL1.bit.CAP4POL = 0;          // Rising edge
	ECap1Regs.ECCTL1.bit.CTRRST1 = 1;          // Difference operation
	ECap1Regs.ECCTL1.bit.CTRRST2 = 1;          // Difference operation
	ECap1Regs.ECCTL1.bit.CTRRST3 = 1;          // Difference operation
	ECap1Regs.ECCTL1.bit.CTRRST4 = 1;          // Difference operation
	ECap1Regs.ECCTL2.bit.SYNCI_EN = 1;         // Enable sync in
	ECap1Regs.ECCTL2.bit.SYNCO_SEL = 0;        // Pass through
	ECap1Regs.ECCTL1.bit.CAPLDEN = 1;          // Enable capture units


	ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1;        // Start Counter
	ECap1Regs.ECCTL2.bit.REARM = 1;            // arm one-shot
	ECap1Regs.ECCTL1.bit.CAPLDEN = 1;          // Enable CAP1-CAP4 register loads
	ECap1Regs.ECEINT.bit.CEVT4 = 1;            // 4 events = interrupt

	EALLOW;  // This is needed to write to EALLOW protected registers
	PieVectTable.ECAP1_INT = &ecap1_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	// Enable CPU INT4 which is connected to ECAP1-4 INT:
	IER |= M_INT4;
	// Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
	PieCtrlRegs.PIEIER4.bit.INTx1 = 1;

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
}

__interrupt void ecap1_isr(void)
{
   // Cap input is syc'ed to SYSCLKOUT so there may be
   // a +/- 1 cycle variation

   if(ECap1Regs.CAP2 > EPwm5Regs.TBPRD*2+1 || ECap1Regs.CAP2 < EPwm5Regs.TBPRD*2-1)
   {
       Fail();
   }

   if(ECap1Regs.CAP3 > EPwm5Regs.TBPRD*2+1 || ECap1Regs.CAP3 < EPwm5Regs.TBPRD*2-1)
   {
       Fail();
   }

   if(ECap1Regs.CAP4 > EPwm5Regs.TBPRD*2+1 || ECap1Regs.CAP4 < EPwm5Regs.TBPRD*2-1)
   {
       Fail();
   }

   ECap1IntCount++;

   if(EPwm5TimerDirection == EPWM_TIMER_UP)
   {
		if(EPwm5Regs.TBPRD < PWM5_TIMER_MAX)
		{
		   EPwm5Regs.TBPRD++;
		}
		else
		{
		   EPwm5TimerDirection = EPWM_TIMER_DOWN;
		   EPwm5Regs.TBPRD--;
		}
   }
   else
   {
        if(EPwm5Regs.TBPRD > PWM5_TIMER_MIN)
        {
           EPwm5Regs.TBPRD--;
        }
        else
        {
           EPwm5TimerDirection = EPWM_TIMER_UP;
           EPwm5Regs.TBPRD++;
        }
   }

   ECap1PassCount++;

   ECap1Regs.ECCLR.bit.CEVT4 = 1;
   ECap1Regs.ECCLR.bit.INT = 1;
   ECap1Regs.ECCTL2.bit.REARM = 1;

   // Acknowledge this interrupt to receive more interrupts from group 4
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
}

void Fail()
{
    __asm("   ESTOP0");
}


void eCAP1_APWM_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR1.bit.ECAP1ENCLK = 1;  // eCAP1
	EDIS;

	InitECap1Gpio();

	// Setup APWM mode on CAP1, set period and compare registers
	ECap1Regs.ECCTL2.bit.CAP_APWM = 1;	// Enable APWM mode
	ECap1Regs.CAP1 = 0x01312D00;			// Set Period value
	ECap1Regs.CAP2 = 0x00989680;			// Set Compare value
	ECap1Regs.ECCLR.all = 0x0FF;			// Clear pending interrupts
	ECap1Regs.ECEINT.bit.CTR_EQ_CMP = 1; // enable Compare Equal Int

	// Start counters
	ECap1Regs.ECCTL2.bit.TSCTRSTOP = 1;

}
