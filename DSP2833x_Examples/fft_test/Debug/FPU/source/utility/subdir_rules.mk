################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FPU/source/utility/%.obj: ../FPU/source/utility/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/APP/EPWM" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/APP/leds" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/APP/FFT" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/APP/FIR" --include_path="D:/matlab/R2023a/extern/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/FPU/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/fft_test/bsp" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="FPU/source/utility/$(basename $(<F)).d_raw" --obj_directory="FPU/source/utility" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


