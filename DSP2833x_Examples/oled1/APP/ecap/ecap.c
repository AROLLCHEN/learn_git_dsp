/*
 * ecap.c
 *
 *  Created on: 2018��7��3��
 *      Author: Administrator
 */

#include "ecap.h"
//#include "epwm.h"

__interrupt void ecap1_isr(void);
void Fail(void);

/*
Uint32 t1=0,t2=0,t3=0,t4=0,T1=0,T2=0,t5,t6,t7,t8,T3,T4,i,led=0,led1=0,T1_temp=1,T2_temp=1;
Uint32 freq1=0,average=0;
Uint32 freq[];
float duty=0;
*/
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
    ECap1Regs.ECCTL2.bit.CONT_ONESHT = 0;      // 0-����ģʽ/1-����ģʽ
    ECap1Regs.ECCTL2.bit.STOP_WRAP = 3;        // Stop at 4 events

    ECap1Regs.ECCTL1.bit.CAP1POL=0;//������ѡ�������ز���
    ECap1Regs.ECCTL1.bit.CAP2POL=0;//������ѡ�������ز���
    ECap1Regs.ECCTL1.bit.CAP3POL=0;//������ѡ�������ز���
    ECap1Regs.ECCTL1.bit.CAP4POL=0;//������ѡ���½��ز���

    ECap1Regs.ECCTL1.bit.CTRRST1=0;//CAP1�¼������ü�������0-��CAP1�¼��в����ü�������1-���ü�����
    ECap1Regs.ECCTL1.bit.CTRRST2=0;//CAP2�¼������ü�������0-��CAP2�¼��в����ü�������1-���ü�����
    ECap1Regs.ECCTL1.bit.CTRRST3=0;//CAP3�¼������ü�������0-��CAP3�¼��в����ü�������1-���ü�����
    ECap1Regs.ECCTL1.bit.CTRRST4=0;//CAP4�¼������ü�������0-��CAP4�¼��в����ü�������1-���ü�����

    ECap1Regs.ECCTL1.bit.CAPLDEN = 1;  //ʹ���¼���׽ʱ��׽�Ĵ���װ�ؼ�����ֵ
//    ECap1Regs.ECCTL1.bit.PRESCALE = 5; //���ⲿ�źŲ���Ƶ

    ECap1Regs.ECCTL2.bit.SYNCI_EN = 0; // Enable sync in
    ECap1Regs.ECCTL2.bit.SYNCO_SEL = 0;// Pass through

    ECap1Regs.ECCTL2.bit.CAP_APWM=0; //ģʽѡ��0-��׽ģʽ��1-APWMģʽ
    ECap1Regs.ECCTL2.bit.REARM = 1;  // arm one-shot
    ECap1Regs.ECCTL2.bit.TSCTRSTOP=1;//���ü���������
    ECap1Regs.ECEINT.bit.CEVT4=1;    //�����¼�4�ж�

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

interrupt void ecap1_isr(void)
{
   // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
    ECap1Regs.ECCLR.all=0xFFFF;//clare all flag

}

void eCAP2_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR1.bit.ECAP2ENCLK = 1;  // eCAP1
    EDIS;

    InitECap2Gpio();

    ECap2Regs.ECEINT.all = 0x0000;             // Disable all capture interrupts
    ECap2Regs.ECCLR.all = 0xFFFF;              // Clear all CAP interrupt flags
    ECap2Regs.ECCTL1.bit.CAPLDEN = 0;          // Disable CAP1-CAP4 register loads
    ECap2Regs.ECCTL2.bit.TSCTRSTOP = 0;        // Make sure the counter is stopped

    // Configure peripheral registers
    ECap2Regs.ECCTL2.bit.CONT_ONESHT = 0;      // 0-����ģʽ/1-����ģʽ
    ECap2Regs.ECCTL2.bit.STOP_WRAP = 3;        // Stop at 4 events

    ECap2Regs.ECCTL1.bit.CAP1POL=0;//������ѡ�������ز���
    ECap2Regs.ECCTL1.bit.CTRRST1=0;//CAP1�¼������ü�������0-��CAP1�¼��в����ü�������1-���ü�����

    ECap2Regs.ECCTL1.bit.CAP2POL=0;//������ѡ�������ز���
    ECap2Regs.ECCTL1.bit.CAP3POL=0;//������ѡ�������ز���
    ECap2Regs.ECCTL1.bit.CAP4POL=1;//������ѡ���½��ز���

    ECap2Regs.ECCTL1.bit.CTRRST1=0;//CAP1�¼������ü�������0-��CAP1�¼��в����ü�������1-���ü�����
    ECap2Regs.ECCTL1.bit.CTRRST2=0;//CAP2�¼������ü�������0-��CAP2�¼��в����ü�������1-���ü�����
    ECap2Regs.ECCTL1.bit.CTRRST3=0;//CAP3�¼������ü�������0-��CAP3�¼��в����ü�������1-���ü�����
    ECap2Regs.ECCTL1.bit.CTRRST4=0;//CAP4�¼������ü�������0-��CAP4�¼��в����ü�������1-���ü�����

    ECap2Regs.ECCTL1.bit.CAPLDEN = 1;  //ʹ���¼���׽ʱ��׽�Ĵ���װ�ؼ�����ֵ
    ECap2Regs.ECCTL1.bit.PRESCALE = 0; //���ⲿ�źŲ���Ƶ

    ECap2Regs.ECCTL2.bit.SYNCI_EN = 0; // Enable sync in
    ECap2Regs.ECCTL2.bit.SYNCO_SEL = 0;// Pass through

    ECap2Regs.ECCTL2.bit.CAP_APWM=0; //ģʽѡ��0-��׽ģʽ��1-APWMģʽ
    ECap2Regs.ECCTL2.bit.REARM = 1;  // arm one-shot
    ECap2Regs.ECCTL2.bit.TSCTRSTOP=1;//���ü���������
    ECap2Regs.ECEINT.bit.CEVT4=1;    //�����¼�4�ж�

    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ECAP2_INT = &ecap2_isr;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    // Enable CPU INT4 which is connected to ECAP1-4 INT:
    IER |= M_INT4;
    // Enable eCAP INTn in the PIE: Group 3 interrupt 1-6
    PieCtrlRegs.PIEIER4.bit.INTx2 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}

interrupt void ecap2_isr(void)
{
   // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP4;
    ECap2Regs.ECCLR.all=0xFFFF;//clare all flag
//    led1++;

//    t5= ECap2Regs.CAP1;
/*
    t2= ECap1Regs.CAP2;
    t3= ECap1Regs.CAP3;
    t4= ECap1Regs.CAP4;
    T1=t2-t1;T2=t4-t3;
    T1_temp=T1;
    T2_temp=T2*10;
    freq = (150000/T1_temp)*1000;
    duty = (T2_temp/T1_temp)*10;

    if(led>100)
    {
        T1_temp = T1;
        T2_temp = T2*10;
        freq = (150000/T1_temp)*1000;
        duty = (T2_temp/T1_temp)*10;
        led = 0;
    }
*/
}


void Fail()
{
    __asm("   ESTOP0");
}

