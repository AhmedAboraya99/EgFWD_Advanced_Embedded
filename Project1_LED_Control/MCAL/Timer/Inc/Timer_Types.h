/*
 * Timer_Types.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */




/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef MCAL_TIMER_TYPES_H_
#define MCAL_TIMER_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "GPIO_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Gpt_Value_t       uint8_t
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//API-Types


/*typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    TIMER0W,
    TIMER1W,
    TIMER2W,
    TIMER3W,
    TIMER4W,
    TIMER5W
}Gpt_Channel_t;*/

typedef enum{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP

}Gpt_Mode_t;

//  @ref Gpt_ChannelMode_define
typedef enum{
    GPT_CH_MODE_CONTINUOUS,
    GPT_CH_MODE_ONESHOT
}Gpt_ChannelMode_t;


typedef enum{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimer_t;

//@ref Bus_length_define
typedef enum{
    GPT_LENGTH_16BIT,
    GPT_LENGTH_32BIT,
    GPT_LENGTH_64BIT,
}Gpt_BusLength_t;

typedef struct
{
    TIMER_TypeDef* Gpt_ChannelID; //select the Channel module ID of Timer
    //this parameter can be a value of  @ref Timer_Channel_define @MCU_HW.h

    uint32_t Gpt_ChannelTickFrequency;           //select tick frequency of timer channel

    uint32_t Gpt_ChannelTickValueMax; //select the maximum tick value of timer channel

    Gpt_BusLength_t BusLength;      //select Timer module Bus Length 16/32/64 bit
    //this parameter can be a value of @ref Bus_length_define

    Gpt_ChannelMode_t Gpt_ChannelMode;           //select mode of timer(continuous/one shot)
    //this parameter can be a value of @ref Gpt_ChannelMode_define

    void (*P_IRQ_CallBack_Function)();  //pointer to IRQ call back function

}Gpt_Config_t;



#endif /* MCAL_TIMER_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer_Types.h
 *********************************************************************************************************************/

