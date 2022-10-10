/*
 * GPIO_Types.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef MCAL_GPIO_TYPES_H_
#define MCAL_GPIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include"MCU_HW.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_PortLevel_t        uint8_t
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//API-Types

//@ref GPIO_Level_define
typedef enum {
    LOW,
    HIGH
}GPIO_Level_t;

//@ref Port_Direction_define
typedef enum {

    INPUT ,
    OUTPUT

}GPIO_Direction_t;

//@ref GPIO_Pins_define
typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}GPIO_Pin_t;

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}GPIO_Port_t;

//@ref GPIO_Channel_define

/*
    GPIO_TypeDef* GPIO_Port;    //specify GPIO Port
    //this parameter can be a value of  @ref GPIO_Port_define in MCU_HW.h

    GPIO_Pin_t GPIO_PinNumber;    //pin number of GPIO Port
    //this parameter can be a value of  @ref GPIO_Pins_define
*/
typedef struct
{
    GPIO_TypeDef* GPIOx;
    GPIO_Pin_t PINx;
}GPIO_Channel_t;

//@ref GPIO_Mode_define
typedef enum {
    PORT_MODE_NORMAL,
    PORT_MODE_ALTERNATE
}Port_Mode_t;

//@ref Port_InternalAttach_define
typedef enum {
    DIGITAL,
    ANALOG,
    PULLUP,
    PULLDOWN,
    OPENDRAIN

}Port_Attach_t;

//@ref Port_Current_define
typedef enum {

    CURRENT_2mA,
    CURRENT_4mA,
    CURRENT_8mA

}Port_OutputCurrent_t;



typedef struct {


    GPIO_Channel_t GPIO_Channel;     //Channel pair (Port, Pin) of GPIO
    //this parameter can be a value of  @ref GPIO_Channel_define

    GPIO_Level_t GPIO_LevelValue;     //Set Level of selected pins
    //this parameter can be a value of  @ref GPIO_Level_define

    Port_Mode_t Pin_Mode;          //mode of GPIO selected pins
    //this parameter can be a value of  @ref GPIO_Mode_define

    GPIO_Direction_t Pin_Direction;         //direction of GPIO selected pins
    //this parameter can be a value of  @ref Port_Direction_define

    Port_Attach_t    Attach_Select; //select the attach type of selected pins
    //this parameter can be a value of  @ref Port_InternalAttach_define

    Port_OutputCurrent_t Current_Level ;   //Current level of Port selected pins
    //this parameter can be a value of  @ref Port_Current_define
}GPIO_PinConfig_t;

#endif /* MCAL_GPIO_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: GPIO_Types.h
 *********************************************************************************************************************/
