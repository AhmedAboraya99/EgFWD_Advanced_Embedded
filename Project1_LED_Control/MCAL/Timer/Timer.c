/*
 * Timer.c
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into groups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Timer.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define SYS_CLOCK                         16000000UL
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static uint32_t TickPerTime[12] = {0};
static void (*Gpt_CallBackFunction[12])(void);
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
* \Syntax          :  Gpt_Init
* \Description     : initialize Nvic\SCB Module by parsing the Configuration
*                    into Nvic\SCB registers
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  ConfigPtr :Pointer to a selected configuration structure
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(const Gpt_Config_t* ConfigPtr)
{
    uint8_t i;

     for ( i = 0; i<CONFIGURED_TIMER_CHANNELS; i++){
         TIMER_TypeDef* Timer_Channel = ConfigPtr[i].Gpt_ChannelID ;
         vuint32_t TimerNumber  = ((uint32_t)(Timer_Channel)-(uint32_t)(TIMER0_BASE))/4096;

         /*enable Timer module clock*/
          SET_BIT(SYSCTRL->RCGCTIMER, TimerNumber);
					SET_BIT(SYSCTRL->RCGC1, ((int)TimerNumber+(int)16));
					
					
        /*TODO : initialize HW timer module according to configuration set by ConfigPtr */
          /*1. Ensure the timer is disabled using (TnEN bit in the GPTMCTL register) before making any changes. */
          RESET_BIT(Timer_Channel->GPTMCTL, PIN0);

          /* 2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000 */
          ASSIGN_PORT(Timer_Channel->GPTMCFG, 0x00000000);

          /* 3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR) */
            if(ConfigPtr->Gpt_ChannelMode == GPT_CH_MODE_ONESHOT)
                SET_BIT(Timer_Channel->GPTMTAR, PIN0);
            else if(ConfigPtr->Gpt_ChannelMode == GPT_CH_MODE_CONTINUOUS)
                SET_BIT(Timer_Channel->GPTMTAR, PIN1);

          /* 4. Option: configure the bits in the GPTMTnMR register
            to select whether to configure an additional trigger or interrupt, and count up or down */
            SET_BIT(Timer_Channel->GPTMTAR, PIN4);         //COUNT_UP tick Direction

          /* 5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR). */
            uint32_t TickPerTime = SYS_CLOCK / (ConfigPtr[i].Gpt_ChannelTickFrequency);
            uint32_t AtcualMaxTick = TickPerTime * (ConfigPtr[i].Gpt_ChannelTickValueMax);
            ASSIGN_PORT(Timer_Channel->GPTMTAILR, AtcualMaxTick);

          /* 6. If interrupts are required, set the appropriate bits in the GPTM Interrupt Mask Register(GPTMIMR) */



        /*TODO : enable GPT Predef Timers at value "0" */

          /* 7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting */
            SET_BIT(Timer_Channel->GPTMCTL, PIN0);
          /* 8. Poll the GPTMRIS register or wait for the interrupt to be generated (if enabled). In both cases,
            the status flags are cleared using the (GPTMICR) Register */
            while (GET_BIT(Timer_Channel->GPTMRIS, PIN0) != LOW)   //Timer A has timed out
                SET_BIT(Timer_Channel->GPTMICR, PIN0);             //clears the TATORIS bit in the GPTMRIS register

     }

}

/******************************************************************************
* \Syntax          : Gpt_DisableNotification
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Gpt_DisableNotification(TIMER_TypeDef* TIMERx){
    RESET_BIT(TIMERx->GPTMIMR, PIN0);      //Disable GPTM Timer A Time-Out Interrupt Mask
}
/******************************************************************************
* \Syntax          : Gpt_EnableNotification
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) :  TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Gpt_EnableNotification(TIMER_TypeDef* TIMERx){
    SET_BIT(TIMERx->GPTMIMR, PIN0);      //enable GPTM Timer A Time-Out Interrupt Mask
}
/******************************************************************************
* \Syntax          : Gpt_StartTimer
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (in) : Value  :Target time value in ms.
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Gpt_StartTimer(TIMER_TypeDef* TIMERx,Gpt_Value_t Value){
    vuint32_t TimerNumber  = ((uint32_t)(TIMERx)-(uint32_t)(TIMER0_BASE))/4096;
    uint32_t AtcualMaxTick = TickPerTime[TimerNumber] * Value;
    ASSIGN_PORT(TIMERx->GPTMTAILR, AtcualMaxTick);
    SET_BIT(TIMERx->GPTMCTL, PIN0);

}
/******************************************************************************
* \Syntax          : Gpt_StopTimer
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Gpt_StopTimer(TIMER_TypeDef* TIMERx){
    RESET_BIT(TIMERx->GPTMCTL, PIN0);
}
/******************************************************************************
* \Syntax          : Gpt_GetTimeElapsed
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): Gpt_Value_t Elapsed time value in ms
* \Return value:   : None
*******************************************************************************/

Gpt_Value_t Gpt_GetTimeElapsed(TIMER_TypeDef* TIMERx){
    vuint32_t TimerNumber  = ((uint32_t)(TIMERx)-(uint32_t)(TIMER0_BASE))/4096;

    return (TIMERx->GPTMTAR)/TickPerTime[TimerNumber];
}
/******************************************************************************
* \Syntax          : Gpt_GetTimeRemaining
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out):  Gpt_Value_t Remaining time value in ms
* \Return value:   : None
*******************************************************************************/

Gpt_Value_t Gpt_GetTimeRemaining(TIMER_TypeDef* TIMERx){
    vuint32_t TimerNumber  = ((uint32_t)(TIMERx)-(uint32_t)(TIMER0_BASE))/4096;

    return ((TIMERx->GPTMTAILR)-(TIMERx->GPTMTAR))/TickPerTime[TimerNumber];

}
/******************************************************************************
* \Syntax          : Gpt_GetPredefTimerValue
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

Std_Return_t Gpt_GetPredefTimerValue(Gpt_PredefTimer_t PredefTimer,uint32_t*TimeValuePtr){

}
/******************************************************************************
* \Syntax          : Gpt_ClearFlag
* \Description     :
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : TIMERx : where x can be (0-->5) to select TIMER Module Channel
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/

void Gpt_ClearFlag(TIMER_TypeDef* TIMERx){
    uint32_t InterruptStatus = (TIMERx->GPTMRIS);
    SET_BIT(TIMERx->GPTMICR, InterruptStatus);
}


//=====ISR=======
void TIMER0A_Handler(void){
    Gpt_ClearFlag(TIMER0);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[0]!= NULL_PTR){Gpt_CallBackFunction[0]() ; }
}
void TIMER1A_Handler(void){
    Gpt_ClearFlag(TIMER1);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[1]!= NULL_PTR){ Gpt_CallBackFunction[1]() ;  }
}
void TIMER2A_Handler(void){
    Gpt_ClearFlag(TIMER2);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[2]!= NULL_PTR){ Gpt_CallBackFunction[2]() ;
    }
}
void TIMER3A_Handler(void){
    Gpt_ClearFlag(TIMER3);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[3]!= NULL_PTR){ Gpt_CallBackFunction[3]() ; }
}
void TIMER4A_Handler(void){
    Gpt_ClearFlag(TIMER4);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[4]!= NULL_PTR) {Gpt_CallBackFunction[4]() ; }
}
void TIMER5A_Handler(void){
    Gpt_ClearFlag(TIMER5);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[5]!= NULL_PTR) {Gpt_CallBackFunction[5](); }
}
void WTIMER0A_Handler(void){
    Gpt_ClearFlag(TIMER0W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[0]!= NULL_PTR) {Gpt_CallBackFunction[0]() ; }
}
void WTIMER1A_Handler(void){
    Gpt_ClearFlag(TIMER3W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[1]!= NULL_PTR) {Gpt_CallBackFunction[1]() ; }
}
void WTIMER2A_Handler(void){
    Gpt_ClearFlag(TIMER2W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[2]!= NULL_PTR) {Gpt_CallBackFunction[2]() ; }

}
void WTIMER3A_Handler(void){
    Gpt_ClearFlag(TIMER3W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[3]!= NULL_PTR) { Gpt_CallBackFunction[3]() ;}
}
void WTIMER4A_Handler(void){
    Gpt_ClearFlag(TIMER4W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[4]!= NULL_PTR) {Gpt_CallBackFunction[4](); }
}
void WTIMER5A_Handler(void){
    Gpt_ClearFlag(TIMER5W);
    //Call IRQ CallBack function
    if(Gpt_CallBackFunction[5]!= NULL_PTR) { Gpt_CallBackFunction[5](); }
}

/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/
