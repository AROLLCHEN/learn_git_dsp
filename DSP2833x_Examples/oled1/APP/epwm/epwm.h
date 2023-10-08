/*
 * epwm.h
 *
 *  Created on: 2018-1-26
 *      Author: Administrator
 */

#ifndef EPWM_H_
#define EPWM_H_


#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�

void EPWM1_Init(Uint16 tbprd);
void EPWM2_Init(Uint16 tbprd);
void EPWM6_Init(Uint16 tbprd);

interrupt void epwm2_isr(void);
interrupt void epwm1_isr(void);

#endif /* EPWM_H_ */
