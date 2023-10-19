################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/uart/%.obj: ../APP/uart/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/adc" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/lcd1602" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/lcd1602" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/iic" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/24cxx" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/secwatch" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/spi" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/uart" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/smg" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/relay" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/exti" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/step_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/dc_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/key" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/beep" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example31_DSP2833x_LCD1602/APP/leds" --include_path="E:/DSP8233x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/uart/$(basename $(<F)).d_raw" --obj_directory="APP/uart" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


