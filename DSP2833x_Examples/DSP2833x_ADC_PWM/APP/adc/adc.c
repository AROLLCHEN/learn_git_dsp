/*
 * adc.c
 *
 *  Created on: 2018-1-29
 *      Author: Administrator
 */

#include "adc.h"

Uint16 SampleDone = 0;
double SampleTable0[BUF_SIZE] = {};//存储脉搏信号
double SampleTable1[BUF_SIZE] = {};//IO2信号
double SampleTable2[BUF_SIZE] = {};//IO4信号
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
    AdcRegs.ADCTRL1.bit.ACQ_PS = ADC_SHCLK;     //ADC采样时间选择
    AdcRegs.ADCTRL3.bit.ADCCLKPS = ADC_CKPS;    //ADC内核分频
    AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;           // 1  Cascaded mode
    AdcRegs.ADCTRL1.bit.CONT_RUN = 1;           // Setup continuous run

    AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 0x2;
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1 ;
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2 ;
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;     //软件启动转换功能
    AdcRegs.ADCTRL2.bit.INT_ENA_SEQ1 = 0x1;     //允许向CPU发出中断请求
    AdcRegs.ADCTRL2.bit.INT_MOD_SEQ1 = 0;       //在每个SEQ1转换结束后产生中断
/*
    // 配置ePWM1触发ADC
    EPwm1Regs.ETSEL.bit.SOCAEN = 1;             // 使能ePWMa触发AD转换
    EPwm1Regs.ETSEL.bit.SOCASEL = 4;            // 选择当计数值递增至CMPA作为触发事件
    EPwm1Regs.ETPS.bit.SOCAPRD = 1;             // 在第一个触发事件后即产生触发脉冲
    EPwm1Regs.TBCTL.bit.CTRMODE = 0;            // 增计数模式
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 1;          //HSPCLKDIV选择2分频
    EPwm1Regs.TBCTL.bit.CLKDIV = 0;             //CLKDIV选择不分频
    EPwm1Regs.TBPRD = 49999;                    //设置周期值，采样频率为150M / (1*2)/ (TBPRD+1) = 1500Hz
    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD /2;    // 设置比较值
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

    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 1;           // 复位排序器至CONV00
    AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;         // 清除SEQ1中断标志位
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;     // 应答PIE分组中断
}

