/*
 * DIO_Types.h
 *
 *  Created on: Sep 15, 2022
 *      Author: Ahmed Aboraya
 */


/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef MCAL_DIO_TYPES_H_
#define MCAL_DIO_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include"MCU_HW.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DIO_PortLevel_t        uint8_t
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//API-Types

//@ref DIO_Level_define
typedef enum {
    LOW,
    HIGH
}DIO_Level_t;

//@ref Port_Direction_define
typedef enum {

    INPUT ,
    OUTPUT

}DIO_Direction_t;

//@ref DIO_Pins_define
typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}DIO_Pin_t;

typedef enum {
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF
}DIO_Port_t;

//@ref DIO_Channel_define

/*
    DIO_TypeDef* DIO_Port;    //specify DIO Port
    //this parameter can be a value of  @ref DIO_Port_define in MCU_HW.h

    DIO_Pin_t DIO_PinNumber;    //pin number of DIO Port
    //this parameter can be a value of  @ref DIO_Pins_define
*/
typedef struct
{
    DIO_TypeDef* DIOx;
    DIO_Pin_t PINx;
}DIO_Channel_t;

//@ref DIO_Mode_define
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


    DIO_Channel_t DIO_Channel;     //Channel pair (Port, Pin) of DIO
    //this parameter can be a value of  @ref DIO_Channel_define

    DIO_Level_t DIO_LevelValue;     //Set Level of selected pins
    //this parameter can be a value of  @ref DIO_Level_define

    Port_Mode_t Pin_Mode;          //mode of DIO selected pins
    //this parameter can be a value of  @ref DIO_Mode_define

    DIO_Direction_t Pin_Direction;         //direction of DIO selected pins
    //this parameter can be a value of  @ref Port_Direction_define

    Port_Attach_t    Attach_Select; //select the attach type of selected pins
    //this parameter can be a value of  @ref Port_InternalAttach_define

    Port_OutputCurrent_t Current_Level ;   //Current level of Port selected pins
    //this parameter can be a value of  @ref Port_Current_define
}DIO_PinConfig_t;

#endif /* MCAL_DIO_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: DIO_Types.h
 *********************************************************************************************************************/
