################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
DSP2833x_ADC_cal.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_ADC_cal.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_ADC_cal.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_CodeStartBranch.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_CodeStartBranch.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_DefaultIsr.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_DefaultIsr.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_DefaultIsr.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_EPwm.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_EPwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_EPwm.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_EQep.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_EQep.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_EQep.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_GlobalVariableDefs.obj: D:/DSP2833x_ProjectExample/DSP2833x_headers/source/DSP2833x_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieCtrl.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_PieCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_PieCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_PieVect.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_PieVect.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_PieVect.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_SysCtrl.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_SysCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_SysCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

DSP2833x_usDelay.obj: D:/DSP2833x_ProjectExample/DSP2833x_common/source/DSP2833x_usDelay.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="DSP2833x_usDelay.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example_2833xEqep_pos_speed.obj: ../Example_2833xEqep_pos_speed.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="Example_2833xEqep_pos_speed.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example_EPwmSetup.obj: ../Example_EPwmSetup.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="Example_EPwmSetup.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

Example_posspeed.obj: ../Example_posspeed.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_common" --include_path="D:/DSP2833x_ProjectExample/DSP2833x_Libraries/DSP2833x_headers/include" --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="/packages/ti/xdais" --include_path="D:/libs/math/IQmath/v15c/include" --include_path="D:/libs/math/FPUfastRTS/V100/include" -g --define="_DEBUG" --define="LARGE_MODEL" --quiet --verbose_diagnostics --diag_warning=225 --diag_suppress=10063 --diag_suppress=16002 --issue_remarks --output_all_syms --cdebug_asm_data --asm_directory="C:/tidcs/c28/DSP2833x/v130/DSP2833x_examples_ccsv5/eqep_pos_speed/Debug" --preproc_with_compile --preproc_dependency="Example_posspeed.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

