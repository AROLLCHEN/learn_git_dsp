################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
APP/epwm/epwm.obj: ../APP/epwm/epwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example14_DSP2833x_Epwm_Time_Interrupt/APP/time" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example14_DSP2833x_Epwm_Time_Interrupt/APP/epwm" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Examples/Example14_DSP2833x_Epwm_Time_Interrupt/APP/leds" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" -g --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="APP/epwm/epwm.d" --obj_directory="APP/epwm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

