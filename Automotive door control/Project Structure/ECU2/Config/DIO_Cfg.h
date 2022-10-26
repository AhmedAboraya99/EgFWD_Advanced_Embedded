/*
 * DIO_Cfg.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */



/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "DIO.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DIO_CONFIGURED_CHANNELS        1
/* DIO Configured Port IDs  */
#define BUZZER_PORT_CHANNEL               DIOA
#define LLIGHT_PORT_CHANNEL               DIOA
#define RLIGHT_PORT_CHANNEL                DIOA

/* DIO Configured Pin IDs  */
#define BUZZER_PIN_CHANNEL                PIN1
#define LLIGHT_PIN_CHANNEL                PIN2
#define RLIGHT_PIN_CHANNEL                PIN0

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern DIO_PinConfig_t Port_Cfg[];


#endif  /* DIO_Cfg_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Cfg.h
 *********************************************************************************************************************/
