/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
//-*-*-*-*-*-*-*-*-*-*-*-
//IVT Macros
//-*-*-*-*-*-*-*-*-*-*-*
// @ref IRQ_SRC_define

typedef enum
{

     GPIOA_IRQ                   =  0,              /*   0  GPIOA                */
     GPIOB_IRQ                   =  1,              /*   1  GPIOB                */
     GPIOC_IRQ                   =  2,              /*   2  GPIOC                */
     GPIOD_IRQ                   =  3,              /*   3  GPIOD                */
     GPIOE_IRQ                   =  4,              /*   4  GPIOE                */
     UART0_IRQ                   =  5,              /*   5  UART0                */
     UART1_IRQ                   =  6,              /*   6  UART1                */
     SSI0_IRQ                    =  7,              /*   7  SSI0                 */
     I2C0_IRQ                    =  8,              /*   8  I2C0                 */
     PWM0_FAULT_IRQ              =  9,              /*   9  PWM0_FAULT           */
     PWM0_0_IRQ                  =  10,             /*  10  PWM0_0               */
     PWM0_1_IRQ                  =  11,             /*  11  PWM0_1               */
     PWM0_2_IRQ                  =  12,             /*  12  PWM0_2               */
     QEI0_IRQ                    =  13,             /*  13  QEI0                 */
     ADC0SS0_IRQ                 =  14,             /*  14  ADC0SS0              */
     ADC0SS1_IRQ                 =  15,             /*  15  ADC0SS1              */
     ADC0SS2_IRQ                 =  16,             /*  16  ADC0SS2              */
     ADC0SS3_IRQ                 =  17,             /*  17  ADC0SS3              */
     WATCHDOG0_IRQ               =  18,             /*  18  WATCHDOG0            */
     TIMER0A_IRQ                 =  19,             /*  19  TIMER0A              */
     TIMER0B_IRQ                 =  20,             /*  20  TIMER0B              */
     TIMER1A_IRQ                 =  21,             /*  21  TIMER1A              */
     TIMER1B_IRQ                 =  22,             /*  22  TIMER1B              */
     TIMER2A_IRQ                 =  23,             /*  23  TIMER2A              */
     TIMER2B_IRQ                 =  24,             /*  24  TIMER2B              */
     COMP0_IRQ                   =  25,             /*  25  COMP0                */
     COMP1_IRQ                   =  26,             /*  26  COMP1                */
     SYSCTL_IRQ                  =  28,             /*  28  SYSCTL               */
     FLASH_CTRL_IRQ              =  29,             /*  29  FLASH_CTRL           */
     GPIOF_IRQ                   =  30,             /*  30  GPIOF                */
     UART2_IRQ                   =  33,             /*  33  UART2                */
     SSI1_IRQ                    =  34,             /*  34  SSI1                 */
     TIMER3A_IRQ                 =  35,             /*  35  TIMER3A              */
     TIMER3B_IRQ                 =  36,             /*  36  TIMER3B              */
     I2C1_IRQ                    =  37,             /*  37  I2C1                 */
     QEI1_IRQ                    =  38,             /*  38  QEI1                 */
     CAN0_IRQ                    =  39,             /*  39  CAN0                 */
     CAN1_IRQ                    =  40,             /*  40  CAN1                 */
     HIB_IRQ                     =  43,             /*  43  HIB                  */
     USB0_IRQ                    =  44,             /*  44  USB0                 */
     PWM0_3_IRQ                  =  45,             /*  45  PWM0_3               */
     UDMA_IRQ                    =  46,             /*  46  UDMA                 */
     UDMAERR_IRQ                 =  47,             /*  47  UDMAERR              */
     ADC1SS0_IRQ                 =  48,             /*  48  ADC1SS0              */
     ADC1SS1_IRQ                 =  49,             /*  49  ADC1SS1              */
     ADC1SS2_IRQ                 =  50,             /*  50  ADC1SS2              */
     ADC1SS3_IRQ                 =  51,             /*  51  ADC1SS3              */
     SSI2_IRQ                    =  57,             /*  57  SSI2                 */
     SSI3_IRQ                    =  58,             /*  58  SSI3                 */
     UART3_IRQ                   =  59,             /*  59  UART3                */
     UART4_IRQ                   =  60,             /*  60  UART4                */
     UART5_IRQ                   =  61,             /*  61  UART5                */
     UART6_IRQ                   =  62,             /*  62  UART6                */
     UART7_IRQ                   =  63,             /*  63  UART7                */
     I2C2_IRQ                    =  68,             /*  68  I2C2                 */
     I2C3_IRQ                    =  69,             /*  69  I2C3                 */
     TIMER4A_IRQ                 =  70,             /*  70  TIMER4A              */
     TIMER4B_IRQ                 =  71,             /*  71  TIMER4B              */
     TIMER5A_IRQ                 =  92,             /*  92  TIMER5A              */
     TIMER5B_IRQ                 =  93,             /*  93  TIMER5B              */
     WTIMER0A_IRQ                =  94,             /*  94  WTIMER0A             */
     WTIMER0B_IRQ                =  95,             /*  95  WTIMER0B             */
     WTIMER1A_IRQ                =  96,             /*  96  WTIMER1A             */
     WTIMER1B_IRQ                =  97,             /*  97  WTIMER1B             */
     WTIMER2A_IRQ                =  98,             /*  98  WTIMER2A             */
     WTIMER2B_IRQ                =  99,             /*  99  WTIMER2B             */
     WTIMER3A_IRQ                =  100,            /* 100  WTIMER3A             */
     WTIMER3B_IRQ                =  101,            /* 101  WTIMER3B             */
     WTIMER4A_IRQ                =  102,            /* 102  WTIMER4A             */
     WTIMER4B_IRQ                =  103,            /* 103  WTIMER4B             */
     WTIMER5A_IRQ                =  104,            /* 104  WTIMER5A             */
     WTIMER5B_IRQ                =  105,            /* 105  WTIMER5B             */
     SYSEXC_IRQ                  =  106,            /* 106  SYSEXC               */
     PWM1_0_IRQ                  = 134,             /* 134  PWM1_0               */
     PWM1_1_IRQ                  = 135,             /* 135  PWM1_1               */
     PWM1_2_IRQ                  = 136,             /* 136  PWM1_2               */
     PWM1_3_IRQ                  = 137,             /* 137  PWM1_3               */
     PWM1_FAULT_IRQ              = 138              /* 138  PWM1_FAULT           */

}IntCtrl_Interrupt_t;

//@ref IRQ_State_define
typedef enum{
    IRQ_EN,
    IRQ_DIS,
    IRQ_PIND,
    IRQ_UNPIND,
    IRQ_ACTIVE
}IntCtrl_IRQ_State_t;

typedef struct
{
    IntCtrl_Interrupt_t IRQ_SRC; //select the source of interrupt request
    //this parameter can be a value of  @ref IRQ_SRC_define
/*
    IntCtrl_IRQ_State_t IRQ_State;           //select Interrupt request register state
    //this parameter can be a value of @ref IRQ_State_define
*/
    void (*P_IRQ_CallBack_Function)();  //pointer to IRQ call back function

}IntCtrl_Config_t;
 

#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
