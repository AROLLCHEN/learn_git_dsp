################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
APP/epwm/%.obj: ../APP/epwm/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example15_DSP2833x_Epwm_Up_AQ/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example15_DSP2833x_Epwm_Up_AQ/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example15_DSP2833x_Epwm_Up_AQ/APP/leds" --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/epwm/$(basename $(<F)).d_raw" --obj_directory="APP/epwm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


