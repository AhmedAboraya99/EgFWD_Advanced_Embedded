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
    {{ BUZZER_PORT_CHANNEL, BUZZER_PIN_CHANNEL},LOW,PORT_MODE_NORMAL,OUTPUT,OPENDRAIN,CURRENT_4mA},
    {{ LLIGHT_PORT_CHANNEL, LLIGHT_PIN_CHANNEL},LOW,PORT_MODE_NORMAL,OUTPUT,OPENDRAIN,CURRENT_4mA},
    {{ RLIGHT_PORT_CHANNEL, RLIGHT_PIN_CHANNEL},LOW,PORT_MODE_NORMAL,OUTPUT,OPENDRAIN,CURRENT_4mA},
};


/**********************************************************************************************************************
 *  END OF FILE: DIO_Lcfg.c
 *********************************************************************************************************************/
