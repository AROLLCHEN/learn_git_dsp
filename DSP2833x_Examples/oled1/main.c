#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "oled.h"
#include "delay.h"
#include "leds.h"

void main(void)
{
    u8 t = ' ';
    InitSysCtrl();
    InitPieCtrl();
    IER = 0x0000;
    IFR = 0x0000;
    InitPieVectTable();
    MemCopy(&RamfuncsLoadStart,&RamfuncsLoadEnd,&RamfuncsRunStart);
    InitFlash(); //烧写要加MemCopy InitFlash 这两句。如果在线调试必须删掉这两句
    OLED_Init();

    OLED_ShowString(0,0,"ALIENTEK",24);
    OLED_ShowString(0,24,"0.96' OLED TEST",16);
    OLED_ShowString(0,40,"ATOM 2014/5/4",12);
    OLED_ShowString(0,52,"ASCII:",12);
    OLED_ShowString(64,52,"CODE:",12);
    OLED_Refresh_Gram();//更新显示到OLED

    while(1)
    {
        OLED_ShowChar(36,52,t,12,1);//显示ASCII字符
        OLED_ShowNum(94,52,t,3,12); //显示ASCII字符的码值
        OLED_Refresh_Gram();        //更新显示到OLED
        t++;
        if(t>'~')t=' ';
        delay_ms(1000);
    }
}




