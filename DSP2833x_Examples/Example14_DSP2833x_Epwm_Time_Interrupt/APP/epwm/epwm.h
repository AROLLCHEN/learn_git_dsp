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
interrupt void epwm1_timer_isr(void);


#endif /* EPWM_H_ */
