/*
 * DIO.h
 *
 *  Created on: Oct 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Types.h"
#include "MCU_HW.h"
#include "DIO_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//=======API-Functions=======
void DIO_Init(const DIO_PinConfig_t* ConfigPtr);
DIO_Level_t DIO_ReadChannel(DIO_Channel_t ChannelId);
void DIO_WriteChannel(DIO_Channel_t ChannelId,DIO_Level_t Level);
DIO_PortLevel_t DIO_ReadPort(DIO_TypeDef* DIOx);
void DIO_WritePort(DIO_TypeDef* DIOx,DIO_PortLevel_t Level);
DIO_Level_t DIO_FlipChannel(DIO_Channel_t ChannelId);


//API-Types
extern DIO_PinConfig_t Port_Cfg[];

#endif /* MCAL_DIO_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/





