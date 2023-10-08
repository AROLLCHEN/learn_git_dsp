/*
 * epwm.c
 *
 *  Created on: 2018-1-26
 *      Author: Administrator
 */


#include "epwm.h"
#include "leds.h"

#if (CPU_FRQ_150MHZ)
    #define CPU_CLK   150e6
#endif
#if (CPU_FRQ_100MHZ)
    #define CPU_CLK   100e6
#endif

//
// 5kHz (300rpm) EPWM1 frequency. Frequency can be changed here
//


#define PHASE 90
#define PWM_CLK   10e3
#define SP        CPU_CLK/(2*PWM_CLK)
#define TBCTLVAL  0x200E      // up-down count, timebase=SYSCLKOUT
#define CAPA  SP/(180.0/(PHASE+0.0000001))  //0~SP
#define CAPB  SP-CAPA
Uint32 sp;
Uint32 capA;
Uint32 capB;

interrupt void epwm1_isr(void);

void EPWM1_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;   // Disable TBCLK within the ePWM
	SysCtrlRegs.PCLKCR1.bit.EPWM1ENCLK = 1;  // ePWM1
	EDIS;

	InitEPwm1Gpio();

	// Interrupts that are used in this example are re-mapped to
	// ISR functions found within this file.
	EALLOW;  // This is needed to write to EALLOW protected registers
	PieVectTable.EPWM1_INT = &epwm1_isr;
	EDIS;    // This is needed to disable write to EALLOW protected registers

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
	EDIS;

	// Setup Sync
	EPwm1Regs.TBSTS.all=0;
    EPwm1Regs.TBPHS.half.TBPHS =0;
    EPwm1Regs.TBCTR=0;

    EPwm1Regs.CMPCTL.all=0x50;     // immediate mode for CMPA and CMPB
    EPwm1Regs.CMPA.half.CMPA=CAPA;
    EPwm1Regs.CMPB=CAPB;
    //
    // CTR=CMPA when inc->EPWM1A=1, when dec->EPWM1A=0
    //
    EPwm1Regs.AQCTLA.all=0x420;

    EPwm1Regs.AQCTLB.all=0x06;     // CTR=PRD ->EPWM1B=1, CTR=0 ->EPWM1B=0
    EPwm1Regs.AQSFRC.all=0;
    EPwm1Regs.AQCSFRC.all=0;

    EPwm1Regs.TZSEL.all=0;
    EPwm1Regs.TZCTL.all=0;
    EPwm1Regs.TZEINT.all=0;
    EPwm1Regs.TZFLG.all=0;
    EPwm1Regs.TZCLR.all=0;
    EPwm1Regs.TZFRC.all=0;

    EPwm1Regs.ETSEL.all=0x0A;      // Interrupt on PRD
    EPwm1Regs.ETPS.all=1;
    EPwm1Regs.ETFLG.all=0;
    EPwm1Regs.ETCLR.all=0;
    EPwm1Regs.ETFRC.all=0;

    EPwm1Regs.PCCTL.all=0;

    EPwm1Regs.TBCTL.all=0x0010+TBCTLVAL; // Enable Timer
    EPwm1Regs.TBPRD=SP;      // Generate INT on 1st event

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         // Start all the timers synced
	EDIS;

	// Enable CPU INT3 which is connected to EPWM1-3 INT:
	IER |= M_INT3;

	// Enable EPWM INTn in the PIE: Group 3 interrupt 1-3
	PieCtrlRegs.PIEIER3.bit.INTx1 = 1;

	// Enable global Interrupts and higher priority real-time debug events:
	EINT;   // Enable Global interrupt INTM
	ERTM;   // Enable Global realtime interrupt DBGM
}

interrupt void epwm1_isr(void)
{
	static Uint16 cnt=0;

	cnt++;
	if(cnt==50000)
	{
		cnt=0;
		LED3_TOGGLE;
	}

	// Clear INT flag for this timer
	EPwm1Regs.ETCLR.bit.INT = 1;
	// Acknowledge this interrupt to receive more interrupts from group 3
	PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;
}

void EPwm1A_SetCompare(Uint16 val)
{
	EPwm1Regs.CMPA.half.CMPA = val;  //设置占空比
}
void EPwm1B_SetCompare(Uint16 val)
{
	EPwm1Regs.CMPB = val;  //设置占空比
}
//void EPwm1_SetFreq(Uint32 freq)
//{
//    sp=CPU_CLK/(2*freq);
//    capA=sp/(180.0/(PHASE+0.0001));
//    capB=sp-capA;
//    EPwm1Regs.CMPA.half.CMPA=capA;
//    EPwm1Regs.CMPB=capB;
//    EPwm1Regs.TBPRD=sp;
//
//}
//void EPwm1_SetPhase(float32 phase)
//{
//    capA=sp/(180.0/(phase+0.0001));
//    capB=sp-capA;
//    EPwm1Regs.CMPA.half.CMPA=capA;
//    EPwm1Regs.CMPB=capB;
//    EPwm1Regs.TBPRD=sp;
//}

void EPwm1_SetFreqPhase(Uint32 freq,float32 phase)
{
    sp=CPU_CLK/(2*freq);
    capA=sp/(180.0/(phase+0.0001));
    capB=sp-capA;
    EPwm1Regs.CMPA.half.CMPA=capA;
    EPwm1Regs.CMPB=capB;
    EPwm1Regs.TBPRD=sp;

}


void EPWM6_Init(Uint16 tbprd)
{
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;   // Disable TBCLK within the ePWM
	SysCtrlRegs.PCLKCR1.bit.EPWM6ENCLK = 1;  // ePWM6
	EDIS;

	InitEPwm6Gpio();

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 0;      // Stop all the TB clocks
	EDIS;

	// Setup Sync
	EPwm6Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;  // Pass through
	// Allow each timer to be sync'ed
	EPwm6Regs.TBCTL.bit.PHSEN = TB_DISABLE;
	EPwm6Regs.TBPHS.half.TBPHS = 0;
	EPwm6Regs.TBCTR = 0x0000;                  // Clear counter
	EPwm6Regs.TBPRD = tbprd;
	EPwm6Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;    // Count up
	EPwm6Regs.TBCTL.bit.HSPCLKDIV=TB_DIV1;
	EPwm6Regs.TBCTL.bit.CLKDIV=TB_DIV1;

	// Setup shadow register load on ZERO
	EPwm6Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.SHDWBMODE = CC_SHADOW;
	EPwm6Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;
	EPwm6Regs.CMPCTL.bit.LOADBMODE = CC_CTR_ZERO;

	// Set Compare values
	EPwm6Regs.CMPA.half.CMPA = 0;    // Set compare A value
	EPwm6Regs.CMPB = 0;              // Set Compare B value

	// Set actions
	EPwm6Regs.AQCTLA.bit.ZRO = AQ_CLEAR;            // Set PWM1A on Zero
	EPwm6Regs.AQCTLA.bit.CAU = AQ_SET;          // Clear PWM1A on event A, up count
	EPwm6Regs.AQCTLB.bit.ZRO = AQ_CLEAR;            // Set PWM1B on Zero
	EPwm6Regs.AQCTLB.bit.CBU = AQ_SET;          // Clear PWM1B on event B, up count

	EPwm6Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
	EPwm6Regs.ETSEL.bit.INTEN = 1;  // Enable INT
	EPwm6Regs.ETPS.bit.INTPRD = ET_1ST;           // Generate INT on 1st event

	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;         // Start all the timers synced
	EDIS;
}

void EPwm6A_SetCompare(Uint16 val)
{
	EPwm6Regs.CMPA.half.CMPA = val;  //设置占空比
}
void EPwm6B_SetCompare(Uint16 val)
{
	EPwm6Regs.CMPB = val;  //设置占空比
}
