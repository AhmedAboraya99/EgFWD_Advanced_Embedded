################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
App/App_00_LedCtrl/App_00_LedCtrl.obj: ../App/App_00_LedCtrl/App_00_LedCtrl.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/App/App_00_LedCtrl" --include_path="C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/MCAL/IntCtrl" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/Common" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/Config" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/MCAL/GPIO/Inc" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/MCAL/IntCtrl/Inc" --include_path="E:/Work/Embedded systems/EgFwd_Embedded/Project1_LED_Control/MCAL/Timer/Inc" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="App/App_00_LedCtrl/App_00_LedCtrl.d_raw" --obj_directory="App/App_00_LedCtrl" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


