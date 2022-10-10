/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  App_00_LedCtrl.c
 *        \brief  App
 *      \details: this file contains the implementaion of LedCtrl app
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"
#include "GPIO.h"
#include "Timer.h"
#include "App_00_LedCtrl.h"

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
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : LedCtrl_Init
* \Description     : Initializes the Led Port pin
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void LedCtrl_Init(void){
    Gpt_Init(Gpt_Cfg);
    Gpt_EnableNotification(TIMER0);

}
/******************************************************************************
* \Syntax          :  LedCtrl_SetON
* \Description     : Set the On time in sec for LED
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Time   required time in sec
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void LedCtrl_SetON(uint32_t Time){
    GPIO_WriteChannel(Port_Cfg->GPIO_Channel, HIGH);
    Gpt_StartTimer(TIMER0, Time);

}
/******************************************************************************
* \Syntax          :  LedCtrl_SetOFF
* \Description     : Set the Off time in sec for LED
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : Time   required time in sec
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void LedCtrl_SetOFF(uint32_t Time){
 GPIO_WriteChannel(Port_Cfg->GPIO_Channel, LOW);
 Gpt_StartTimer(TIMER0, Time);

}
/******************************************************************************
* \Syntax          :  LedCtrl_Start
* \Description     : make the LED start based on the OnTime and OffTime
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

/******************************************************************************
* \Syntax          :  LedCtrl_Stop
* \Description     : Stops the LED
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

/******************************************************************************
* \Syntax          :  Timer0_CallBack
* \Description     : This the timer IRQ CallBack which is called by the Timer ISR
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Timer0_CallBack(void)
{

}
/******************************************************************************
* \Syntax          :  LedCtrl_Run
* \Description     : check for OnTime period and OffTime period and take required action to make LED blink
*
* \Sync\Async      : Synchronous
* \Reentrancy      : None Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void LedCtrl_Run(){

}
