/**
 *  ********************************************************************************************
 *  @file                 main.c
 *  @file                 SK Electronics
 *  @version           V1.0
 *  @date               2020-xx-xx
 *  @brief               LED流水灯测试
 *  *******************************************************************************************
*/
#include <FIR.h>
#include "DSP28x_Project.h"

#define FLASH_RUN 1
#define SRAM_RUN 2
#define RUN_TYPE SRAM_RUN
#if RUN_TYPE==FLASH_RUN
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;
#endif

void delay_1ms(Uint16 t);
/**
 *  @brief                      主函数
 *  @parameter                  无
 *  @return_value               无
 */
void main(void)
{
/*第一步：初始化系统控制:*/
    InitSysCtrl();

/*第二步：初始化GPIO口*/
    InitGpio();

/* 第三步：清除所有中断 和初始化 PIE 向量表:*/
    DINT;// 禁用CPU中断
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

/*第六步：进入主循环*/
    FIR_Init();

    FIR_filter_run();

    for(;;)
    {

    }
}

/**
 *  @brief                           1ms延迟函数
 *  @parameter                  t
 *  @return_value               无
 */
void delay_1ms(Uint16 t)
{
    while(t--)
    {
        DELAY_US(1000);
    }
}










