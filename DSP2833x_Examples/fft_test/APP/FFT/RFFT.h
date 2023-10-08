/*
 * RFFT.h
 *
 *  Created on: 2023年9月30日
 *      Author: CHENJIE
 */

#ifndef _RFFT_H_
#define _RFFT_H_

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include <stdio.h>
#include <string.h>

#define RFFT_Analyse_MaxNum 20

typedef struct {
    Uint16 Wave_Num;
    float DC_Amp;
    float Amp[RFFT_Analyse_MaxNum];
    float freq[RFFT_Analyse_MaxNum];
    float Phase[RFFT_Analyse_MaxNum];
} RFFT_Analyse_Struct;


void RFFT_ADC_Init();
void RFFT_ADC_Caculate();
float RFFT_Fractional_Frequency(float ratio);
void RFFT_Analyse(float *src);
float RFFT_Phase_Caculate(Uint16 index,float ratio);

Uint16 RFFT_Peak_Find(float *src ,Uint16 len,Uint16 *index); //幅度谱及其长度

#endif /* _RFFT_H_ */
