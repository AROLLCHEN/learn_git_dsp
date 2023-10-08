/*
 * adc.h
 *
 *  Created on: 2018-1-29
 *      Author: Administrator
 */

#ifndef ADC_H_
#define ADC_H_

#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�


#define ADC_MODCLK 3
#define ADC_CKPS   0x1   // ADC module clock = HSPCLK/2*ADC_CKPS   = 25.0MHz/(1*2) = 12.5MHz
#define ADC_SHCLK  0xf   // S/H width in ADC module periods                        = 16 ADC clocks

#define BUF_SIZE   1024  // �źŻ���������
extern double SampleTable0[BUF_SIZE];//�洢�����ź�
extern double SampleTable1[BUF_SIZE];//IO2�ź�
extern double SampleTable2[BUF_SIZE];//IO4�ź�

extern Uint16 SampleDone;

void ADC_Init(void);
Uint16 Read_ADCValue(void);
interrupt void adc_isr(void);
#endif /* ADC_H_ */
