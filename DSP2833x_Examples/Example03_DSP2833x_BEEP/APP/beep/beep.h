/*
 * beep.h
 *
 *  Created on: 2023Äê9ÔÂ14ÈÕ
 *      Author: CHENJIE
 */

#ifndef _BEEP_H_
#define _BEEP_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

#define BEEP_ON			(GpioDataRegs.GPASET.bit.GPIO6=1)
#define BEEP_OFF		(GpioDataRegs.GPACLEAR.bit.GPIO6=1)
#define BEEP_TOGGLE		(GpioDataRegs.GPATOGGLE.bit.GPIO6=1)

void BEEP_Init(void);



#endif /* APP_BEEP_BEEP_H_ */
