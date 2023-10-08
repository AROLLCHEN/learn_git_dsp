/*
 * ecap.h
 *
 *  Created on: 2018��7��3��
 *      Author: Administrator
 */

#ifndef ECAP_H_
#define ECAP_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"



void eCAP1_Init(void);
void eCAP2_Init(void);

interrupt void ecap1_isr(void);
__interrupt void ecap2_isr(void);

#endif /* APP_ECAP_ECAP_H_ */
