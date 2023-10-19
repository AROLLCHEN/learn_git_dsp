/*
 * main.c
 *
 *  Created on: 2023年9月14日
 *      Author: CHENJIE
 */
#include "RFFT.h"
#include "epwm.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"


#define RAM_RUN     0
#define FLASH_RUN   1

#define RUN_TYPE    RAM_RUN

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	/*第一步：初始化系统控制:*/
	    InitSysCtrl();
	/*第二步：初始化GPIO口*/
	    //InitGpio();
	/* 第三步：清除所有中断 和初始化 PIE 向量表:*/
	    //DINT;// 禁用CPU中断
	    InitPieCtrl();// 初始化 PIE 控制寄存器到默认状态，默认状态是全部 PIE 中断被禁用和标志位被清除
	    IER = 0x0000;// 禁用 CPU 中断和清除所有 CPU 中断标志位:
	    IFR = 0x0000;
	    InitPieVectTable();// 初始化 PIE 中断向量表
	    // 中断重映射，注册中断程序入口（用户按需求添加）
	/*程序烧录入28335（可选的）*/
	#if RUN_TYPE==FLASH_RUN
	    MemCopy(&RamfuncsLoadStart,&RamfuncsLoadEnd,&RamfuncsRunStart);
	    InitFlash();
	#endif
	    RFFT_ADC_Init();

	    RFFT_ADC_Caculate();



}
