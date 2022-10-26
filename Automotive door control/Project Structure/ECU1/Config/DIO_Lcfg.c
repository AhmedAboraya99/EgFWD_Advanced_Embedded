/*
 * DIO_Lcfg.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO_Lcfg.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Cfg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
DIO_PinConfig_t Port_Cfg[DIO_CONFIGURED_CHANNELS]={
    {{ DOOR_PORT_CHANNEL, DOOR_PIN_CHANNEL},LOW,PORT_MODE_NORMAL,INPUT,OPENDRAIN,CURRENT_4mA},

};


/**********************************************************************************************************************
 *  END OF FILE: DIO_Lcfg.c
 *********************************************************************************************************************/
