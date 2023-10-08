/*
 * epwm.c
 *
 *  Created on: 2018-1-26
 *      Author: Administrator
 */


#include "epwm.h"
#include "leds.h"

Uint16 x = 0;
/*
void EPWM1_Init()
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

    EPwm1Regs.ETSEL.bit.SOCAEN = 1;             // ʹ��ePWMa����ADת��
    EPwm1Regs.ETSEL.bit.SOCASEL = 4;            // ѡ�񵱼���ֵ������CMPA��Ϊ�����¼�
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;             // �ڵ�һ�������¼��󼴲�����������
    EPwm1Regs.TBCTL.bit.CTRMODE = 0;            // ������ģʽ
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;          //HSPCLKDIVѡ��2��Ƶ
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;             //CLKDIVѡ�񲻷�Ƶ
    EPwm1Regs.TBPRD = 49999;                    //��������ֵ������Ƶ��Ϊ150M / (1*2)/ (TBPRD+1) = 1500Hz
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD /2;    // ���ñȽ�ֵ

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
    x++;
    // Clear INT flag for this timer
    EPwm1Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}
*/

void EPWM1_Init(Uint16 tbprd)
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
    EPwm1Regs.TBCTL.bit.SYNCOSEL = TB_SYNC_DISABLE;  // Pass through
    // Allow each timer to be sync'ed
    EPwm1Regs.TBCTR = 0x0000;                  // Clear counter
    EPwm1Regs.TBPRD = tbprd;
    EPwm1Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;
    EPwm1Regs.TBCTL.bit.HSPCLKDIV=TB_DIV1;
    EPwm1Regs.TBCTL.bit.CLKDIV=2;
//    EPwm1Regs.TBCTL.bit.PRDLD = TB_SHADOW;

    // Setup shadow register load on ZERO
    EPwm1Regs.CMPCTL.bit.SHDWAMODE = CC_SHADOW;
    EPwm1Regs.CMPCTL.bit.LOADAMODE = CC_CTR_ZERO;

    // Set Compare values
    EPwm1Regs.CMPA.half.CMPA = (tbprd+1)/2;    // Set compare A value

    // Set actions
    EPwm1Regs.AQCTLA.bit.ZRO = AQ_SET;            // Set PWM1A on Zero
    EPwm1Regs.AQCTLA.bit.CAU = AQ_CLEAR;          // Clear PWM1A on event A, up count

    // Active Low PWMs - Setup Deadband
    EPwm1Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm1Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm1Regs.DBCTL.bit.IN_MODE = DBA_ALL;

//    EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;     // Select INT on Zero event
//    EPwm1Regs.ETSEL.bit.INTEN = 1;                // Enable INT
//    EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;           // Generate INT on 1st event

    // ����ePWM1����ADC
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;             // ʹ��ePWMa����ADת��
    EPwm1Regs.ETSEL.bit.SOCASEL = 4;            // ѡ�񵱼���ֵ������CMPA��Ϊ�����¼�
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;             // �ڵ�һ�������¼��󼴲�����������

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
    x++;
    // Clear INT flag for this timer
    EPwm1Regs.ETCLR.bit.INT = 1;
    // Acknowledge this interrupt to receive more interrupts from group 3
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;

}

