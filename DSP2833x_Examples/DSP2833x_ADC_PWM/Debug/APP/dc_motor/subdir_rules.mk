################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
APP/dc_motor/dc_motor.obj: ../APP/dc_motor/dc_motor.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/adc" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/adc" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/smg" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/relay" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/exti" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/step_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/dc_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/key" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/beep" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP2833x_ADC_PWM/APP/leds" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/dc_motor/dc_motor.d" --obj_directory="APP/dc_motor" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


