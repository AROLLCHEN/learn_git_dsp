################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FPU/source/utility/%.obj: ../FPU/source/utility/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="C:/ti/ccs1240/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --include_path="C:/ti/controlSUITE/device_support/f2833x/v140/DSP2833x_common/include" --include_path="C:/ti/controlSUITE/device_support/f2833x/v140/DSP2833x_headers/include" --include_path="F:/Project/自主创业/原创例程/GPIO流水灯实验/bsp" -g --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="FPU/source/utility/$(basename $(<F)).d_raw" --obj_directory="FPU/source/utility" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


