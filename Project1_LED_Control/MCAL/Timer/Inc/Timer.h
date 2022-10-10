/*
 * Timer.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  TIMER.h
 *       Module:  TIMER
 *
 *  Description:  header file for TIMER Module
 *
 *********************************************************************************************************************/

#ifndef MCAL_TIMER_H_
#define MCAL_TIMER_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_Types.h"
#include "Timer_Cfg.h"
#include "MCU_HW.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA _tS AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTO_tS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTO_tS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void Gpt_Init(const Gpt_Config_t* ConfigPtr)
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_Config_t* ConfigPtr);
void Gpt_DisableNotification(TIMER_TypeDef* TIMERx); //no notifiaction, no isr will operate
void Gpt_EnableNotification(TIMER_TypeDef* TIMERx);
void Gpt_StartTimer(TIMER_TypeDef* TIMERx,Gpt_Value_t Value);
void Gpt_StopTimer(TIMER_TypeDef* TIMERx);
Gpt_Value_t Gpt_GetTimeElapsed(TIMER_TypeDef* TIMERx);
Gpt_Value_t Gpt_GetTimeRemaining(TIMER_TypeDef* TIMERx);
Std_Return_t Gpt_GetPredefTimerValue(Gpt_PredefTimer_t PredefTimer,uint32_t*TimeValuePtr);
void Gpt_ClearFlag(TIMER_TypeDef* TIMERx);

void TIMER0A_Handler(void);
void TIMER1A_Handler(void);
void TIMER2A_Handler(void);
void TIMER3A_Handler(void);
void TIMER4A_Handler(void);
void TIMER5A_Handler(void);
void WTIMER0A_Handler(void);
void WTIMER1A_Handler(void);
void WTIMER2A_Handler(void);
void WTIMER3A_Handler(void);
void WTIMER4A_Handler(void);
void WTIMER5A_Handler(void);

#endif /* MCAL_TIMER_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/




