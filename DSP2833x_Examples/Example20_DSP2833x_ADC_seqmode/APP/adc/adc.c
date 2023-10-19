/*
 * adc.c
 *
 *  Created on: 2018-1-29
 *      Author: Administrator
 */

#include "adc.h"

Uint16 SampleDone = 0;
double SampleTable0[BUF_SIZE] = {};//�洢�����ź�
double SampleTable1[BUF_SIZE] = {};//IO2�ź�
double SampleTable2[BUF_SIZE] = {};//IO4�ź�
Uint16 z = 0;

void ADC_Init(void)
{
    EALLOW;
    SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;    // ADC
    EDIS;

    // Specific clock setting for this example:
    EALLOW;
    SysCtrlRegs.HISPCP.all = ADC_MODCLK;    // HSPCLK = SYSCLKOUT/ADC_MODCLK
    EDIS;

    // Interrupts that are used in this example are re-mapped to
    // ISR functions found within this file.
    EALLOW;  // This is needed to write to EALLOW protected registers
    PieVectTable.ADCINT = &adc_isr;
    EDIS;    // This is needed to disable write to EALLOW protected registers

    InitAdc();  // For this example, init the ADC

    // Specific ADC setup for this example:
    AdcRegs.ADCTRL1.bit.ACQ_PS = ADC_SHCLK;     //ADC����ʱ��ѡ��
    AdcRegs.ADCTRL3.bit.ADCCLKPS = ADC_CKPS;    //ADC�ں˷�Ƶ
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;           // 1  Cascaded mode
    AdcRegs.ADCTRL1.bit.CONT_RUN = 1;           // Setup continuous run

    AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 0x2;
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1 ;
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2 ;
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;     //�������ת������
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 0x1;     //������CPU�����ж�����
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;       //��ÿ��SEQ1ת������������ж�
/*
    // ����ePWM1����ADC
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;             // ʹ��ePWMa����ADת��
    EPwm1Regs.ETSEL.bit.SOCASEL = 4;            // ѡ�񵱼���ֵ������CMPA��Ϊ�����¼�
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;             // �ڵ�һ�������¼��󼴲�����������
    EPwm1Regs.TBCTL.bit.CTRMODE = 0;            // ������ģʽ
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;          //HSPCLKDIVѡ��2��Ƶ
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;             //CLKDIVѡ�񲻷�Ƶ
    EPwm1Regs.TBPRD = 49999;                    //��������ֵ������Ƶ��Ϊ150M / (1*2)/ (TBPRD+1) = 1500Hz
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD /2;    // ���ñȽ�ֵ
*/
    IER |= M_INT1;

    PieCtrlRegs.PIEIER1.bit.INTx6 = 1;

    // Enable global Interrupts and higher priority real-time debug events:
    EINT;   // Enable Global interrupt INTM
    ERTM;   // Enable Global realtime interrupt DBGM
}

Uint16 Read_ADCValue(void)
{
	while (AdcRegs.ADCST.bit.INT_SEQ1== 0);
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
	return AdcRegs.ADCRESULT0>>4;
}

interrupt void adc_isr(void)
{
    z++;
    SampleDone=1;
    SampleTable0[BUF_SIZE-1] = 3.0*(AdcRegs.ADCRESULT0 >>4)/4095;
    SampleTable1[BUF_SIZE-1] = 3.0*(AdcRegs.ADCRESULT1 >>4)/4095;
    SampleTable2[BUF_SIZE-1] = 3.0*(AdcRegs.ADCRESULT2 >>4)/4095;

    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;           // ��λ��������CONV00
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;         // ���SEQ1�жϱ�־λ
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;     // Ӧ��PIE�����ж�
}

