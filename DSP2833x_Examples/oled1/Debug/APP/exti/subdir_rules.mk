################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/exti/%.obj: ../APP/exti/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/CMD" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/adc" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/delay" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/dma" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/ecap" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/exti" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/iic" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/key" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/lcd12864" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/lcd1602" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/leds" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/OLED" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/relay" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/spi" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/oled1/APP/uart" --advice:performance=all -g --diag_warning=225 --diag_wrap=off --display_error_number --abi=coffabi --preproc_with_compile --preproc_dependency="APP/exti/$(basename $(<F)).d_raw" --obj_directory="APP/exti" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


