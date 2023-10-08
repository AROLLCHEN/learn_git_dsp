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


void EPWM1_Init(void);
void EPwm1A_SetCompare(Uint16 val);
void EPwm1B_SetCompare(Uint16 val);
void EPwm1_SetFreqPhase(Uint32 freq,float32 phase);

void EPWM6_Init(Uint16 tbprd);
void EPwm6A_SetCompare(Uint16 val);
void EPwm6B_SetCompare(Uint16 val);

#endif /* EPWM_H_ */
