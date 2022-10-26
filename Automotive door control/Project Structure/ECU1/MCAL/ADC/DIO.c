/*
 * DIO.c
 *
 *  Created on: Oct 15, 2022
 *      Author: Ahmed Aboraya
 */

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into groups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "DIO.h"

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


/******************************************************************************
* \Syntax          :  DIO_Init
* \Description     : initialize Nvic\SCB Module by parsing the Configuration
*                    into Nvic\SCB registers
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  ConfigPtr :Pointer to a selected configuration structure
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void DIO_Init(const DIO_PinConfig_t* ConfigPtr){
		
    uint8_t i;

    for ( i = 0; i< DIO_CONFIGURED_CHANNELS; i++ ){

        /*instances of configuration members*/
      vuint8_t PinNumber = ((ConfigPtr[i].DIO_Channel).PINx);
			
        DIO_TypeDef* DIO_Port = ((ConfigPtr[i].DIO_Channel).DIOx);
				vuint8_t Port_Number = PORT_NUMBER(DIO_Port);

        /*enable selected Port clock*/
        SET_BIT(SYSCTRL->RCGCDIO, Port_Number);
				SET_BIT(SYSCTRL->RCGC2, Port_Number);
			
        /*Set Pin mode Normal DIO / Alternate function*/
        if (ConfigPtr[i].Pin_Mode == PORT_MODE_ALTERNATE)
            SET_BIT(DIO_Port->DIOAFSEL, PinNumber);
        else
            RESET_BIT(DIO_Port->DIOAFSEL, PinNumber);

        /*Set Pin Direction*/
        if (ConfigPtr[i].Pin_Direction == OUTPUT)
            SET_BIT(DIO_Port->DIODIR, PinNumber);
        else
            RESET_BIT(DIO_Port->DIODIR, PinNumber);

        /* Set Internal Attachment */
        if(ConfigPtr[i].Attach_Select == PULLUP)
            SET_BIT(DIO_Port->DIOPUR, PinNumber);
        else if (ConfigPtr[i].Attach_Select == PULLDOWN)
            SET_BIT(DIO_Port->DIOPDR, PinNumber);
        else if (ConfigPtr[i].Attach_Select == OPENDRAIN)
            SET_BIT(DIO_Port->DIOODR, PinNumber);

        /*Set Output Current*/
        if (ConfigPtr[i].Current_Level == CURRENT_2mA)
            SET_BIT(DIO_Port->DIODR2R, PinNumber);
        else if (ConfigPtr[i].Current_Level == CURRENT_4mA)
            SET_BIT(DIO_Port->DIODR4R, PinNumber);
        else if (ConfigPtr[i].Current_Level == CURRENT_8mA)
            SET_BIT(DIO_Port->DIODR8R, PinNumber);

        /* enable digital */
        SET_BIT(DIO_Port->DIODEN, PinNumber);

    }
}
/******************************************************************************
 * @Fn          -DIO_ReadChannel
 * @brief       -Read specific DIOx Pin value
 * @param [in]  -ChannelId : to select DIO channel Compose from DIOx , PINx
 * @derived param [in]  -DIOx : where x can be (A-->F) to select DIO peripheral
 * @derived param [in]  -PINx : set pin number to read
 * @retval      -The Reading value of the input pin
 * Note         -none
 *******************************************************************************/
DIO_Level_t DIO_ReadChannel(DIO_Channel_t ChannelId){
    DIO_Level_t PinValue;
    PinValue = GET_BIT((ChannelId.DIOx)->DIODATA, (ChannelId.PINx));
    return PinValue;
}
/******************************************************************************
 * @Fn          -DIO_WriteChannel
 * @brief       -Write value on specific PIN
 * @param [in]  -ChannelId : to select DIO channel Compose from DIOx , PINx
 * @derived param [in]  -DIOx : where x can be (A-->F) to select DIO peripheral
 * @derived param [in]  -PINx : set pin number to read
 * @param [in]   -Value : PIN value
 * @retval      -none
 * Note         -none
 *******************************************************************************/

void DIO_WriteChannel(DIO_Channel_t ChannelId,DIO_Level_t Level){
    if (Level == HIGH)
        SET_BIT((ChannelId.DIOx)->DIODATA, (ChannelId.PINx));
    else
        RESET_BIT((ChannelId.DIOx)->DIODATA, (ChannelId.PINx));
}

/******************************************************************************
 * @Fn          -DIO_ReadChannel
 * @brief       -Read PORT Value
 * @param [in]  -DIOx : where x can be (A-->F) to select DIO peripheral
 * @retval      -The input PORT value (two values based on @ref DIO_Level_define)
 * Note         -none
 *******************************************************************************/

DIO_PortLevel_t DIO_ReadPort(DIO_TypeDef* DIOx){
   return  (DIO_PortLevel_t) DIOx->DIODATA;
}

/******************************************************************************
 * @Fn          -DIO_WritePort
 * @brief       -Write value on PORT
 * @param [in]  -DIOx : where x can be (A-->F) to select DIO peripheral
 * @param [in]   -Value : PIN value
 * @retval      -none
 * Note         -none
 *******************************************************************************/

void DIO_WritePort(DIO_TypeDef* DIOx,DIO_PortLevel_t Level){

         ASSIGN_PORT(DIOx->DIODATA, Level);
}
DIO_Level_t DIO_FlipChannel(DIO_Channel_t ChannelId){

    TOGGLE_BIT((ChannelId.DIOx)->DIODATA, (ChannelId.PINx));
    return GET_BIT((ChannelId.DIOx)->DIODATA, (ChannelId.PINx));
}
/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
