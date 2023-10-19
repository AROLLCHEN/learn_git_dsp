/*
 * lcd12864.h
 *
 *  Created on: 2018-4-16
 *      Author: Administrator
 */

#ifndef LCD12864_H_
#define LCD12864_H_


#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件


#define LCD12864_RS_SETH 	(GpioDataRegs.GPASET.bit.GPIO0=1)
#define LCD12864_RS_SETL 	(GpioDataRegs.GPACLEAR.bit.GPIO0=1)

#define LCD12864_RW_SETH 	(GpioDataRegs.GPBSET.bit.GPIO60=1)
#define LCD12864_RW_SETL 	(GpioDataRegs.GPBCLEAR.bit.GPIO60=1)

#define LCD12864_EN_SETH 	(GpioDataRegs.GPASET.bit.GPIO1=1)
#define LCD12864_EN_SETL 	(GpioDataRegs.GPACLEAR.bit.GPIO1=1)

#define LCD12864_CS_SETH 	(GpioDataRegs.GPBSET.bit.GPIO48=1)
#define LCD12864_CS_SETL 	(GpioDataRegs.GPBCLEAR.bit.GPIO48=1)

#define LCD12864_RSET_SETH 	(GpioDataRegs.GPBSET.bit.GPIO49=1)
#define LCD12864_RSET_SETL 	(GpioDataRegs.GPBCLEAR.bit.GPIO49=1)

#define LCD12864_DATAPORT	(GpioDataRegs.GPADAT.all)



void LCD12864_WriteCmd(unsigned char cmd);
void LCD12864_WriteData(unsigned char dat);
void LCD12864_Init(void);
void LCD12864_ClearScreen(void);
unsigned char LCD12864_Write16CnCHAR(unsigned char x, unsigned char y, unsigned char *cn);

#endif /* LCD12864_H_ */
