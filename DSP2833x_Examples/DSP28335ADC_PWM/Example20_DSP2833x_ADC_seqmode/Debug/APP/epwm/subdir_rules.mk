################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/epwm/%.obj: ../APP/epwm/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/adc" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/smg" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/relay" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/exti" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/step_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/dc_motor" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/key" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/beep" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/DSP28335ADC_PWM/Example20_DSP2833x_ADC_seqmode/APP/leds" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/epwm/$(basename $(<F)).d_raw" --obj_directory="APP/epwm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


