/*
 * adc.h
 *
 *  Created on: 2018-1-29
 *      Author: Administrator
 */

#ifndef ADC_H_
#define ADC_H_

#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件


#define ADC_MODCLK 3
#define ADC_CKPS   0x1   // ADC module clock = HSPCLK/2*ADC_CKPS   = 25.0MHz/(1*2) = 12.5MHz
#define ADC_SHCLK  0xf   // S/H width in ADC module periods                        = 16 ADC clocks

#define BUF_SIZE   1024  // 信号缓存区长度
extern double SampleTable0[BUF_SIZE];//存储脉搏信号
extern double SampleTable1[BUF_SIZE];//IO2信号
extern double SampleTable2[BUF_SIZE];//IO4信号

extern Uint16 SampleDone;

void ADC_Init(void);
Uint16 Read_ADCValue(void);
interrupt void adc_isr(void);
#endif /* ADC_H_ */
