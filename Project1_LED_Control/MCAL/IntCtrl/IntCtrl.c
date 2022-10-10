/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

void (*GP_IRQ_Callback[4])(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(const IntCtrl_Config_t *ConfigPtr)
{
	
    uint8_t i;
		/*Enable/Disable Global Interrupt*/
		#if(ENABLE_GLOBAL_INTERRUPT == 1)
			__asm
				(
					"CPSIE i \n"
				);
		#else
			__asm
				(
					"CPSID i \n"
				);
		#endif
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    //APINT = 0xFA05|0x00001234;

    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    for(i = 0; i<CONFIGURED_IRQ; i++){
        if ( ConfigPtr[i].IRQ_SRC < 32)
            SET_BIT(NVIC->EN0, ConfigPtr[i].IRQ_SRC );
        else if (32 <= ConfigPtr[i].IRQ_SRC && ConfigPtr[i].IRQ_SRC<64)
            SET_BIT(NVIC->EN1, (ConfigPtr[i].IRQ_SRC-32));
        else if (64 <= ConfigPtr[i].IRQ_SRC&&ConfigPtr[i].IRQ_SRC<96)
            SET_BIT(NVIC->EN2, (ConfigPtr[i].IRQ_SRC-64));
        else if (96 <= ConfigPtr[i].IRQ_SRC&&ConfigPtr[i].IRQ_SRC<128)
            SET_BIT(NVIC->EN3, (ConfigPtr[i].IRQ_SRC-96));
        else if (128 <= ConfigPtr[i].IRQ_SRC && ConfigPtr[i].IRQ_SRC<= 138)
            SET_BIT(NVIC->EN4, (ConfigPtr[i].IRQ_SRC-128));
    }

	

}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
