/*
 * GPIO.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  GPIO.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into groups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "GPIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void delay_ms(uint32_t value){
        uint32_t i,j;
    for(i=0;i<value;i++){
        for(j=0;j<255;j++);
		}
}

/******************************************************************************
* \Syntax          :  GPIO_Init
* \Description     : initialize Nvic\SCB Module by parsing the Configuration
*                    into Nvic\SCB registers
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  ConfigPtr :Pointer to a selected configuration structure
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void GPIO_Init(const GPIO_PinConfig_t* ConfigPtr){
		vuint32_t delay_count;
    uint8_t i;

    for ( i = 0; i< GPIO_CONFIGURED_CHANNELS; i++ ){

        /*instances of configuration members*/
      vuint8_t PinNumber = ((ConfigPtr[i].GPIO_Channel).PINx);
			//uint8_t PinNumber = 0;
        GPIO_TypeDef* GPIO_Port = ((ConfigPtr[i].GPIO_Channel).GPIOx);
				vuint8_t Port_Number = PORT_NUMBER(GPIO_Port);

        /*enable selected Port clock*/
        SET_BIT(SYSCTRL->RCGCGPIO, Port_Number);
				SET_BIT(SYSCTRL->RCGC2, Port_Number);
			
        /*Set Pin mode Normal DIO / Alternate function*/
        if (ConfigPtr[i].Pin_Mode == PORT_MODE_ALTERNATE)
            SET_BIT(GPIO_Port->GPIOAFSEL, PinNumber);
        else
            RESET_BIT(GPIO_Port->GPIOAFSEL, PinNumber);

        /*Set Pin Direction*/
        if (ConfigPtr[i].Pin_Direction == OUTPUT)
            SET_BIT(GPIO_Port->GPIODIR, PinNumber);
        else
            RESET_BIT(GPIO_Port->GPIODIR, PinNumber);

        /* Set Internal Attachment */
        if(ConfigPtr[i].Attach_Select == PULLUP)
            SET_BIT(GPIO_Port->GPIOPUR, PinNumber);
        else if (ConfigPtr[i].Attach_Select == PULLDOWN)
            SET_BIT(GPIO_Port->GPIOPDR, PinNumber);
        else if (ConfigPtr[i].Attach_Select == OPENDRAIN)
            SET_BIT(GPIO_Port->GPIOODR, PinNumber);

        /*Set Output Current*/
        if (ConfigPtr[i].Current_Level == CURRENT_2mA)
            SET_BIT(GPIO_Port->GPIODR2R, PinNumber);
        else if (ConfigPtr[i].Current_Level == CURRENT_4mA)
            SET_BIT(GPIO_Port->GPIODR4R, PinNumber);
        else if (ConfigPtr[i].Current_Level == CURRENT_8mA)
            SET_BIT(GPIO_Port->GPIODR8R, PinNumber);

        /* enable digital */
        SET_BIT(GPIO_Port->GPIODEN, PinNumber);

    }
}
/******************************************************************************
 * @Fn          -GPIO_ReadChannel
 * @brief       -Read specific GPIOx Pin value
 * @param [in]  -ChannelId : to select GPIO channel Compose from GPIOx , PINx
 * @derived param [in]  -GPIOx : where x can be (A-->F) to select GPIO peripheral
 * @derived param [in]  -PINx : set pin number to read
 * @retval      -The Reading value of the input pin
 * Note         -none
 *******************************************************************************/
GPIO_Level_t GPIO_ReadChannel(GPIO_Channel_t ChannelId){
    GPIO_Level_t PinValue;
    PinValue = GET_BIT((ChannelId.GPIOx)->GPIODATA, (ChannelId.PINx));
    return PinValue;
}
/******************************************************************************
 * @Fn          -GPIO_WriteChannel
 * @brief       -Write value on specific PIN
 * @param [in]  -ChannelId : to select GPIO channel Compose from GPIOx , PINx
 * @derived param [in]  -GPIOx : where x can be (A-->F) to select GPIO peripheral
 * @derived param [in]  -PINx : set pin number to read
 * @param [in]   -Value : PIN value
 * @retval      -none
 * Note         -none
 *******************************************************************************/

void GPIO_WriteChannel(GPIO_Channel_t ChannelId,GPIO_Level_t Level){
    if (Level == HIGH)
        SET_BIT((ChannelId.GPIOx)->GPIODATA, (ChannelId.PINx));
    else
        RESET_BIT((ChannelId.GPIOx)->GPIODATA, (ChannelId.PINx));
}

/******************************************************************************
 * @Fn          -GPIO_ReadChannel
 * @brief       -Read PORT Value
 * @param [in]  -GPIOx : where x can be (A-->F) to select GPIO peripheral
 * @retval      -The input PORT value (two values based on @ref GPIO_Level_define)
 * Note         -none
 *******************************************************************************/

GPIO_PortLevel_t GPIO_ReadPort(GPIO_TypeDef* GPIOx){
   return  (GPIO_PortLevel_t) GPIOx->GPIODATA;
}

/******************************************************************************
 * @Fn          -GPIO_WritePort
 * @brief       -Write value on PORT
 * @param [in]  -GPIOx : where x can be (A-->F) to select GPIO peripheral
 * @param [in]   -Value : PIN value
 * @retval      -none
 * Note         -none
 *******************************************************************************/

void GPIO_WritePort(GPIO_TypeDef* GPIOx,GPIO_PortLevel_t Level){

         ASSIGN_PORT(GPIOx->GPIODATA, Level);
}
GPIO_Level_t GPIO_FlipChannel(GPIO_Channel_t ChannelId){

    TOGGLE_BIT((ChannelId.GPIOx)->GPIODATA, (ChannelId.PINx));
    return GET_BIT((ChannelId.GPIOx)->GPIODATA, (ChannelId.PINx));
}
/**********************************************************************************************************************
 *  END OF FILE: GPIO.c
 *********************************************************************************************************************/
