################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./tm4c123gh6pm_startup_ccs.obj" \
"./App/App_00_LedCtrl/App_00_LedCtrl.obj" \
"./App/main.obj" \
"./Config/GPIO_Lcfg.obj" \
"./Config/IntCtrl_Lcfg.obj" \
"./Config/Timer_Lcfg.obj" \
"./MCAL/GPIO/GPIO.obj" \
"./MCAL/IntCtrl/IntCtrl.obj" \
"./MCAL/Timer/Timer.obj" \
"../tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include App/App_00_LedCtrl/subdir_vars.mk
-include App/subdir_vars.mk
-include Config/subdir_vars.mk
-include MCAL/GPIO/subdir_vars.mk
-include MCAL/IntCtrl/subdir_vars.mk
-include MCAL/Timer/subdir_vars.mk
-include subdir_rules.mk
-include App/App_00_LedCtrl/subdir_rules.mk
-include App/subdir_rules.mk
-include Config/subdir_rules.mk
-include MCAL/GPIO/subdir_rules.mk
-include MCAL/IntCtrl/subdir_rules.mk
-include MCAL/Timer/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
Project1_LED_Control.out \

EXE_OUTPUTS__QUOTED += \
"Project1_LED_Control.out" \

BIN_OUTPUTS += \
Project1_LED_Control.hex \

BIN_OUTPUTS__QUOTED += \
"Project1_LED_Control.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "Project1_LED_Control.out" secondary-outputs

# Tool invocations
Project1_LED_Control.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"Project1_LED_Control.map" --heap_size=0 --stack_size=512 -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="Project1_LED_Control_linkInfo.xml" --rom_model -o "Project1_LED_Control.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

Project1_LED_Control.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.4.LTS/bin/armhex"  -o "Project1_LED_Control.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "tm4c123gh6pm_startup_ccs.obj" "App\App_00_LedCtrl\App_00_LedCtrl.obj" "App\main.obj" "Config\GPIO_Lcfg.obj" "Config\IntCtrl_Lcfg.obj" "Config\Timer_Lcfg.obj" "MCAL\GPIO\GPIO.obj" "MCAL\IntCtrl\IntCtrl.obj" "MCAL\Timer\Timer.obj" 
	-$(RM) "tm4c123gh6pm_startup_ccs.d" "App\App_00_LedCtrl\App_00_LedCtrl.d" "App\main.d" "Config\GPIO_Lcfg.d" "Config\IntCtrl_Lcfg.d" "Config\Timer_Lcfg.d" "MCAL\GPIO\GPIO.d" "MCAL\IntCtrl\IntCtrl.d" "MCAL\Timer\Timer.d" 
	-@echo 'Finished clean'
	-@echo ' '

secondary-outputs: $(BIN_OUTPUTS)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

