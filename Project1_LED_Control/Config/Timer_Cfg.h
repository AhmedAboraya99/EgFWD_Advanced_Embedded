/*
 * Timer_Cfg.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Cfg.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Timer.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CHANNEL_TICK_FREQUENCY        1000
#define TICK_VALUE_MAX                1000000   //1 million sec
#define CONFIGURED_TIMER_CHANNELS     1


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
extern void Timer0_CallBack(void);

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern Gpt_Config_t Gpt_Cfg[];


#endif  /* TIMER_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer_Cfg.h
 *********************************************************************************************************************/
