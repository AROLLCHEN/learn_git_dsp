/*
 * FIR.c
 *
 *  Created on: 2023年1月12日
 *      Author: yang
 */


#include <FIR.h>
#include "dsp.h"
#include "fpu_filter.h"
#include <math.h>
#include "complex.h"
#include "fdacoefs.h"

#define pi 3.14159
#define FIR_SIZE       (512U)
#define FIR_ORDER       (80U)             // ORDER = NUM_TAPS - 1，ORDER为滤波器阶数

#pragma DATA_SECTION(coeffs, "FIR_buffer0");
#pragma DATA_SECTION(FIR_output, "FIR_buffer1");

// FIR_f32 object
FIR_f32 fir;
// Handle to the FIR_f32 object
FIR_f32_Handle hnd_fir = &fir;

// The filter coefficients are tacked on to the end of the
// MATLAB generated input

// The delay line buffer
float delayLine[FIR_ORDER+1];

float FIR_output[FIR_SIZE];

extern float test_input[];
extern const float coeffs[];
//*****************************************************************************
// the function definitions
//*****************************************************************************
void FIR_Init(void)
{
    // Configure the object
    FIR_f32_setCoefficientsPtr(hnd_fir, coeffs);
    FIR_f32_setDelayLinePtr(hnd_fir, delayLine);
    FIR_f32_setOrder(hnd_fir, FIR_ORDER);
    FIR_f32_setInitFunction(hnd_fir, (v_pfn_v)FIR_f32_init);
    FIR_f32_setCalcFunction(hnd_fir, (v_pfn_v)FIR_f32_calc);

    // Copy the coefficients from test input into the "coeffs" array
    //memcpy(&coeffs, &test_input[FIR_SIZE], (FIR_ORDER + 1U)*sizeof(float));

    // Run the initialization function
    hnd_fir->init(hnd_fir);

}

void FIR_filter_run(void)
{
    // Locals
    uint16_t i;
    float32u_t in, out;

    for(i = 0U; i < FIR_SIZE; i++)
    {
        in.f32   = test_input[i];
        out.f32  = FLT_MAX;
        FIR_f32_setInput(hnd_fir, in.f32);
        FIR_f32_setOutput(hnd_fir, out.f32);

        // Call the calculation routine
        hnd_fir->calc(hnd_fir);

        out.f32 = FIR_f32_getOutput(hnd_fir);
        FIR_output[i] = out.f32;
    }
}

// End of File









