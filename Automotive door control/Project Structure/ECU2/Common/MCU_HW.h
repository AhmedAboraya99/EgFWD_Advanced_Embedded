/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H_
#define MCU_HW_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE               0x00000000UL/* This executable region is for program code.
                                                        Data can also be stored here */

#define SRAM_BASE                       0x20000000UL
#define PERIPHERALS_BASE                0x40000000UL

#define CORTEXM4_PERIPHERALS_BASE       0xE000E000UL
//-----------------------------
//Base addresses for ABP Peripherals
//-----------------------------

#define SYSCTRL_BASE    (PERIPHERALS_BASE+0x000FE000UL)


//=====GPIO=====
/*  0x4000.4000 0x4000.4FFF GPIO Port A
    0x4000.5000 0x4000.5FFF GPIO Port B
    0x4000.6000 0x4000.6FFF GPIO Port C
    0x4000.7000 0x4000.7FFF GPIO Port D
    0x4002.4000 0x4002.4FFF GPIO Port E
    0x4002.5000 0x4002.5FFF GPIO Port F */
#define GPIOA_BASE      (PERIPHERALS_BASE+0x00004000UL)
#define GPIOB_BASE      (PERIPHERALS_BASE+0x00005000UL)
#define GPIOC_BASE      (PERIPHERALS_BASE+0x00006000UL)
#define GPIOD_BASE      (PERIPHERALS_BASE+0x00007000UL)
#define GPIOE_BASE      (PERIPHERALS_BASE+0x00024000UL)
#define GPIOF_BASE      (PERIPHERALS_BASE+0x00025000UL)



#define PORT_NUMBER(x)			(x<GPIOE_BASE?((uint32_t)x-(uint32_t)GPIOA_BASE)/4096:((((uint32_t)x-(uint32_t)GPIOE_BASE)/4096)+4))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: GPIO
//-*-*-*-*-*-*-*-*-*-*-*


typedef struct{

    uint32_t  RESERVED0[255];
    vuint32_t GPIODATA;     /* GPIO Data */
    vuint32_t GPIODIR;      /* GPIO Direction */
    vuint32_t GPIOIS;       /* GPIO Interrupt Sense */
    vuint32_t GPIOIBE;      /* GPIO Interrupt Both Edges */
    vuint32_t GPIOIEV;      /* GPIO Interrupt Event */
    vuint32_t GPIOIM;       /* GPIO Interrupt Mask*/
    vuint32_t GPIORIS;      /*GPIO Raw Interrupt Status*/
    vuint32_t GPIOMIS;      /* GPIO Masked Interrupt Status*/
    vuint32_t GPIOICR;      /* GPIO Interrupt Clear*/
    vuint32_t GPIOAFSEL;    /*GPIO Alternate Function Select*/
    uint32_t  RESERVED1[55];
    vuint32_t GPIODR2R;     /*GPIO  Drive Select*/
    vuint32_t GPIODR4R;     /*GPIO  Drive Select*/
    vuint32_t GPIODR8R;      /*GPIO  Drive Select*/
    vuint32_t GPIOODR;       /* GPIO Open Drain Select*/
    vuint32_t GPIOPUR;      /*- GPIO Pull-Up Select*/
    vuint32_t GPIOPDR;      /*GPIO Pull-Down Select*/
    vuint32_t GPIOSLR;       /*GPIO Slew Rate Control Select*/
    vuint32_t GPIODEN;       /*- GPIO Digital Enable*/
    vuint32_t GPIOLOCK;      /*GPIO Lock*/
    vuint32_t GPIOCR;        /*- GPIO Commit*/
    vuint32_t GPIOAMSEL;     /*GPIO Analog Mode Select*/
    vuint32_t GPIOPCTL;      /*- GPIO Port Control*/
    vuint32_t GPIOADCCTL;    /*GPIO ADC Control*/
    vuint32_t GPIODMACTL;    /* GPIO DMA Control*/

}GPIO_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants
//-*-*-*-*-*-*-*-*-*-*-*
//@ref GPIO_Port_define
#define GPIOA                     ((GPIO_TypeDef*)(GPIOA_BASE))
#define GPIOB                     ((GPIO_TypeDef*)(GPIOB_BASE))
#define GPIOC                     ((GPIO_TypeDef*)(GPIOC_BASE))
#define GPIOD                     ((GPIO_TypeDef*)(GPIOD_BASE))
#define GPIOE                     ((GPIO_TypeDef*)(GPIOE_BASE))
#define GPIOF                     ((GPIO_TypeDef*)(GPIOF_BASE))

//=====TIMER=====
/*  0x4003.0000 0x4003.0FFF 16/32-bit Timer 0
    0x4003.1000 0x4003.1FFF 16/32-bit Timer 1
    0x4003.2000 0x4003.2FFF 16/32-bit Timer 2
    0x4003.3000 0x4003.3FFF 16/32-bit Timer 3
    0x4003.4000 0x4003.4FFF 16/32-bit Timer 4
    0x4003.5000 0x4003.5FFF 16/32-bit Timer 5
    0x4003.6000 0x4003.6FFF 32/64-bit Timer 0
    0x4003.7000 0x4003.7FFF 32/64-bit Timer 1
    0x4004.C000 0x4004.CFFF 32/64-bit Timer 2
    0x4004.D000 0x4004.DFFF 32/64-bit Timer 3
    0x4004.E000 0x4004.EFFF 32/64-bit Timer 4
    0x4004.F000 0x4004.FFFF 32/64-bit Timer 5 */
#define TIMER0_BASE         (PERIPHERALS_BASE+0x00030000UL)
#define TIMER1_BASE         (PERIPHERALS_BASE+0x00031000UL)
#define TIMER2_BASE         (PERIPHERALS_BASE+0x00032000UL)
#define TIMER3_BASE         (PERIPHERALS_BASE+0x00033000UL)
#define TIMER4_BASE         (PERIPHERALS_BASE+0x00034000UL)
#define TIMER5_BASE         (PERIPHERALS_BASE+0x00035000UL)

#define TIMER0W_BASE        (PERIPHERALS_BASE+0x00036000UL)
#define TIMER1W_BASE        (PERIPHERALS_BASE+0x00037000UL)
#define TIMER2W_BASE        (PERIPHERALS_BASE+0x0004C000UL)
#define TIMER3W_BASE        (PERIPHERALS_BASE+0x0004D000UL)
#define TIMER4W_BASE        (PERIPHERALS_BASE+0x0004E000UL)
#define TIMER5W_BASE        (PERIPHERALS_BASE+0x0004F000UL)



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: TIMER
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

  vuint32_t  GPTMCFG;                               /* GPTM Configuration                */
  vuint32_t  GPTMTAMR;                              /* GPTM Timer A Mode                 */
  vuint32_t  GPTMTBMR;                              /* GPTM Timer B Mode                 */
  vuint32_t  GPTMCTL;                               /* GPTM Control                      */
  vuint32_t  GPTMSYNC;                              /* GPTM Synchronize                  */
  uint32_t   RESERVED0;
  vuint32_t  GPTMIMR;                               /* GPTM Interrupt Mask               */
  vuint32_t  GPTMRIS;                               /* GPTM Raw Interrupt Status         */
  vuint32_t  GPTMMIS;                               /* GPTM Masked Interrupt Status      */
  vuint32_t  GPTMICR;                               /* GPTM Interrupt Clear              */
  vuint32_t  GPTMTAILR;                             /* GPTM Timer A Interval Load        */
  vuint32_t  GPTMTBILR;                             /* GPTM Timer B Interval Load        */
  vuint32_t  GPTMTAMATCHR;                          /* GPTM Timer A Match                */
  vuint32_t  GPTMTBMATCHR;                          /* GPTM Timer B Match                */
  vuint32_t  GPTMTAPR;                              /* GPTM Timer A Prescale             */
  vuint32_t  GPTMTBPR;                              /* GPTM Timer B Prescale             */
  vuint32_t  GPTMTAPMR;                             /* GPTM TimerA Prescale Match        */
  vuint32_t  GPTMTBPMR;                             /* GPTM TimerB Prescale Match        */
  vuint32_t  GPTMTAR;                               /* GPTM Timer A                      */
  vuint32_t  GPTMTBR;                               /* GPTM Timer B                      */
  vuint32_t  GPTMTAV;                               /* GPTM Timer A Value                */
  vuint32_t  GPTMTBV;                               /* GPTM Timer B Value                */
  vuint32_t  GPTMRTCPD;                             /* GPTM RTC Predivide                */
  vuint32_t  GPTMTAPS;                              /* GPTM Timer A Prescale Snapshot    */
  vuint32_t  GPTMTBPS;                              /* GPTM Timer B Prescale Snapshot    */
  vuint32_t  GPTMTAPV;                              /* GPTM Timer A Prescale Value       */
  vuint32_t  GPTMTBPV;                              /* GPTM Timer B Prescale Value       */
  uint32_t   RESERVED1[981];
  vuint32_t  GPTMPP;                                /* GPTM Peripheral Properties        */
} TIMER_TypeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants
//-*-*-*-*-*-*-*-*-*-*-*

//@ref Timer_Channel_define
#define TIMER0                    ((TIMER_TypeDef*)(TIMER0_BASE))
#define TIMER1                    ((TIMER_TypeDef*)(TIMER1_BASE))
#define TIMER2                    ((TIMER_TypeDef*)(TIMER2_BASE))
#define TIMER3                    ((TIMER_TypeDef*)(TIMER3_BASE))
#define TIMER4                    ((TIMER_TypeDef*)(TIMER4_BASE))
#define TIMER5                    ((TIMER_TypeDef*)(TIMER5_BASE))

#define TIMER0W                   ((TIMER_TypeDef*)(TIMER0W_BASE))
#define TIMER1W                   ((TIMER_TypeDef*)(TIMER1W_BASE))
#define TIMER2W                   ((TIMER_TypeDef*)(TIMER2W_BASE))
#define TIMER3W                   ((TIMER_TypeDef*)(TIMER3W_BASE))
#define TIMER4W                   ((TIMER_TypeDef*)(TIMER4W_BASE))
#define TIMER5W                   ((TIMER_TypeDef*)(TIMER5W_BASE))

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral registers: SYSTEM CONTROL
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
    uint32_t                :1;
    uint32_t    SLEEPEXIT   :1;
    uint32_t    SLEEPDEEP   :1;
    uint32_t                :1;
    uint32_t    SEVONPEND   :1;
    uint32_t                :0;

}SYSCTRL_BF;

typedef union
{
    uint32_t R;
    SYSCTRL_BF B;
}SYSCTRL_Tag;
typedef struct
{
    uint32_t BASETHR        :1;
    uint32_t MAINPEND       :1;
    uint32_t                :1;
    uint32_t UNALIGNED      :1;
    uint32_t DIV0           :1;
    uint32_t                :3;
    uint32_t BFHFNMIGN      :1;
    uint32_t STKALIGN       :1;
    uint32_t                :0;
}CFGCTRL_BF;
typedef union
{
    uint32_t R;
    CFGCTRL_BF B;
}CFGCTRL_Tag;

typedef struct {
  vuint32_t  DID0;                              /* Device Identification 0                       */
  vuint32_t  DID1;                              /* Device Identification 1                       */
  vuint32_t  DC0;                               /* Device Capabilities 0                         */
  uint32_t  RESERVED0;
  vuint32_t  DC1;                               /* Device Capabilities 1                         */
  vuint32_t  DC2;                               /* Device Capabilities 2                         */
  vuint32_t  DC3;                               /* Device Capabilities 3                         */
  vuint32_t  DC4;                               /* Device Capabilities 4                         */
  vuint32_t  DC5;                               /* Device Capabilities 5                         */
  vuint32_t  DC6;                               /* Device Capabilities 6                         */
  vuint32_t  DC7;                               /* Device Capabilities 7                         */
  vuint32_t  DC8;                               /* Device Capabilities 8                         */
  vuint32_t  PBORCTL;                           /* Brown-Out Reset Control                       */
  uint32_t  RESERVED1[3];
  vuint32_t  SRCR0;                             /* Software Reset Control 0                      */
  vuint32_t  SRCR1;                             /* Software Reset Control 1                      */
  vuint32_t  SRCR2;                             /* Software Reset Control 2                      */
  uint32_t  RESERVED2;
  vuint32_t  RIS;                               /* Raw Interrupt Status                          */
  vuint32_t  IMC;                               /* Interrupt Mask Control                        */
  vuint32_t  MISC;                              /* Masked Interrupt Status and Clear             */
  vuint32_t  RESC;                              /* Reset Cause                                   */
  vuint32_t  RCC;                               /* Run-Mode Clock Configuration                  */
  uint32_t  RESERVED3[2];
  vuint32_t  GPIOHBCTL;                         /* PORT High-Performance Bus Control             */
  vuint32_t  RCC2;                              /* Run-Mode Clock Configuration 2                */
  uint32_t  RESERVED4[2];
  vuint32_t  MOSCCTL;                           /* Main Oscillator Control                       */
  uint32_t  RESERVED5[32];
  vuint32_t  RCGC0;                             /* Run Mode Clock Gating Control Register 0      */
  vuint32_t  RCGC1;                             /* Run Mode Clock Gating Control Register 1      */
  vuint32_t  RCGC2;                             /* Run Mode Clock Gating Control Register 2      */
  uint32_t  RESERVED6;
  vuint32_t  SCGC0;                             /* Sleep Mode Clock Gating Control Register 0    */
  vuint32_t  SCGC1;                             /* Sleep Mode Clock Gating Control Register 1    */
  vuint32_t  SCGC2;                             /* Sleep Mode Clock Gating Control Register 2    */
  uint32_t  RESERVED7;
  vuint32_t  DCGC0;                             /* Deep Sleep Mode Clock Gating Control Register 0                       */
  vuint32_t  DCGC1;                             /* Deep-Sleep Mode Clock Gating Control Register 1                       */
  vuint32_t  DCGC2;                             /* Deep Sleep Mode Clock Gating Control Register 2                       */
  uint32_t  RESERVED8[6];
  vuint32_t  DSLPCLKCFG;                        /* Deep Sleep Clock Configuration                */
  uint32_t  RESERVED9;
  vuint32_t  SYSPROP;                           /* System Properties                             */
  vuint32_t  PIOSCCAL;                          /* Precision Internal Oscillator Calibration     */
  vuint32_t  PIOSCSTAT;                         /* Precision Internal Oscillator Statistics      */
  uint32_t  RESERVED10[2];
  vuint32_t  PLLFREQ0;                          /* PLL Frequency 0                               */
  vuint32_t  PLLFREQ1;                          /* PLL Frequency 1                               */
  vuint32_t  PLLSTAT;                           /* PLL Status                                    */
  uint32_t  RESERVED11[7];
  vuint32_t  SLPPWRCFG;                         /* Sleep Power Configuration                     */
  vuint32_t  DSLPPWRCFG;                        /* Deep-Sleep Power Configuration                */
  vuint32_t  DC9;                               /* Device Capabilities 9                         */
  uint32_t  RESERVED12[3];
  vuint32_t  NVMSTAT;                           /* Non-Volatile Memory Information               */
  uint32_t  RESERVED13[4];
  vuint32_t  LDOSPCTL;                          /* LDO Sleep Power Control                       */
  uint32_t  RESERVED14;
  vuint32_t  LDODPCTL;                          /* LDO Deep-Sleep Power Control                  */
  uint32_t  RESERVED15[80];
  vuint32_t  PPWD;                              /* Watchdog Timer Peripheral Present             */
  vuint32_t  PPTIMER;                           /* 16/32-Bit General-Purpose Timer Peripheral Present                    */
  vuint32_t  PPPORT;                            /* General-Purpose Input/Output Peripheral Present                       */
  vuint32_t  PPDMA;                             /* Micro Direct Memory Access Peripheral Present */
  uint32_t  RESERVED16;
  vuint32_t  PPHIB;                             /* Hibernation Peripheral Present                */
  vuint32_t  PPUART;                            /* Universal Asynchronous Receiver/Transmitter Peripheral Present        */
  vuint32_t  PPSSI;                             /* Synchronous Serial Interface Peripheral Present                       */
  vuint32_t  PPI2C;                             /* Inter-Integrated Circuit Peripheral Present   */
  uint32_t  RESERVED17;
  vuint32_t  PPUSB;                             /* Universal Serial Bus Peripheral Present       */
  uint32_t  RESERVED18[2];
  vuint32_t  PPCAN;                             /* Controller Area Network Peripheral Present    */
  vuint32_t  PPADC;                             /* Analog-to-Digital Converter Peripheral Present                        */
  vuint32_t  PPACMP;                            /* Analog Comparator Peripheral Present          */
  vuint32_t  PPPWM;                             /* Pulse Width Modulator Peripheral Present      */
  vuint32_t  PPQEI;                             /* Quadrature Encoder Interface Peripheral Present                       */
  uint32_t  RESERVED19[4];
  vuint32_t  PPEEPROM;                          /* EEPROM Peripheral Present                     */
  vuint32_t  PPWTIMER;                          /* 32/64-Bit Wide General-Purpose Timer Peripheral Present               */
  uint32_t  RESERVED20[104];
  vuint32_t  SRWD;                              /* Watchdog Timer Software Reset                 */
  vuint32_t  SRTIMER;                           /* 16/32-Bit General-Purpose Timer Software Reset                        */
  vuint32_t  SRPORT;                            /* General-Purpose Input/Output Software Reset   */
  vuint32_t  SRDMA;                             /* Micro Direct Memory Access Software Reset     */
  uint32_t  RESERVED21;
  vuint32_t  SRHIB;                             /* Hibernation Software Reset                    */
  vuint32_t  SRUART;                            /* Universal Asynchronous Receiver/Transmitter Software Reset            */
  vuint32_t  SRSSI;                             /* Synchronous Serial Interface Software Reset   */
  vuint32_t  SRI2C;                             /* Inter-Integrated Circuit Software Reset       */
  uint32_t  RESERVED22;
  vuint32_t  SRUSB;                             /* Universal Serial Bus Software Reset           */
  uint32_t  RESERVED23[2];
  vuint32_t  SRCAN;                             /* Controller Area Network Software Reset        */
  vuint32_t  SRADC;                             /* Analog-to-Digital Converter Software Reset    */
  vuint32_t  SRACMP;                            /* Analog Comparator Software Reset              */
  vuint32_t  SRPWM;                             /* Pulse Width Modulator Software Reset          */
  vuint32_t  SRQEI;                             /* Quadrature Encoder Interface Software Reset   */
  uint32_t  RESERVED24[4];
  vuint32_t  SREEPROM;                          /* EEPROM Software Reset                         */
  vuint32_t  SRWTIMER;                          /* 32/64-Bit Wide General-Purpose Timer Software Reset                   */
  uint32_t  RESERVED25[40];
  vuint32_t  RCGCWD;                            /* Watchdog Timer Run Mode Clock Gating Control  */
  vuint32_t  RCGCTIMER;                         /* 16/32-Bit General-Purpose Timer Run Mode Clock Gating Control         */
  vuint32_t  RCGCGPIO;                          /* General-Purpose Input/Output Run Mode Clock Gating Control            */
  vuint32_t  RCGCDMA;                           /* Micro Direct Memory Access Run Mode Clock Gating Control              */
  uint32_t  RESERVED26;
  vuint32_t  RCGCHIB;                           /* Hibernation Run Mode Clock Gating Control     */
  vuint32_t  RCGCUART;                          /* Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating
                                                         Control                                       */
  vuint32_t  RCGCSSI;                           /* Synchronous Serial Interface Run Mode Clock Gating Control            */
  vuint32_t  RCGCI2C;                           /* Inter-Integrated Circuit Run Mode Clock Gating Control                */
  uint32_t  RESERVED27;
  vuint32_t  RCGCUSB;                           /* Universal Serial Bus Run Mode Clock Gating Control                    */
  uint32_t  RESERVED28[2];
  vuint32_t  RCGCCAN;                           /* Controller Area Network Run Mode Clock Gating Control                 */
  vuint32_t  RCGCADC;                           /* Analog-to-Digital Converter Run Mode Clock Gating Control             */
  vuint32_t  RCGCACMP;                          /* Analog Comparator Run Mode Clock Gating Control                       */
  vuint32_t  RCGCPWM;                           /* Pulse Width Modulator Run Mode Clock Gating Control                   */
  vuint32_t  RCGCQEI;                           /* Quadrature Encoder Interface Run Mode Clock Gating Control            */
  uint32_t  RESERVED29[4];
  vuint32_t  RCGCEEPROM;                        /* EEPROM Run Mode Clock Gating Control          */
  vuint32_t  RCGCWTIMER;                        /* 32/64-Bit Wide General-Purpose Timer Run Mode Clock Gating Control    */
  uint32_t  RESERVED30[40];
  vuint32_t  SCGCWD;                            /* Watchdog Timer Sleep Mode Clock Gating Control                        */
  vuint32_t  SCGCTIMER;                         /* 16/32-Bit General-Purpose Timer Sleep Mode Clock Gating Control       */
  vuint32_t  SCGCGPIO;                          /* General-Purpose Input/Output Sleep Mode Clock Gating Control          */
  vuint32_t  SCGCDMA;                           /* Micro Direct Memory Access Sleep Mode Clock Gating Control            */
  uint32_t  RESERVED31;
  vuint32_t  SCGCHIB;                           /* Hibernation Sleep Mode Clock Gating Control   */
  vuint32_t  SCGCUART;                          /* Universal Asynchronous Receiver/Transmitter Sleep Mode Clock
                                                         Gating Control                                */
  vuint32_t  SCGCSSI;                           /* Synchronous Serial Interface Sleep Mode Clock Gating Control          */
  vuint32_t  SCGCI2C;                           /* Inter-Integrated Circuit Sleep Mode Clock Gating Control              */
  uint32_t  RESERVED32;
  vuint32_t  SCGCUSB;                           /* Universal Serial Bus Sleep Mode Clock Gating Control                  */
  uint32_t  RESERVED33[2];
  vuint32_t  SCGCCAN;                           /* Controller Area Network Sleep Mode Clock Gating Control               */
  vuint32_t  SCGCADC;                           /* Analog-to-Digital Converter Sleep Mode Clock Gating Control           */
  vuint32_t  SCGCACMP;                          /* Analog Comparator Sleep Mode Clock Gating Control                     */
  vuint32_t  SCGCPWM;                           /* Pulse Width Modulator Sleep Mode Clock Gating Control                 */
  vuint32_t  SCGCQEI;                           /* Quadrature Encoder Interface Sleep Mode Clock Gating Control          */
  uint32_t  RESERVED34[4];
  vuint32_t  SCGCEEPROM;                        /* EEPROM Sleep Mode Clock Gating Control        */
  vuint32_t  SCGCWTIMER;                        /* 32/64-Bit Wide General-Purpose Timer Sleep Mode Clock Gating
                                                         Control                                       */
  uint32_t  RESERVED35[40];
  vuint32_t  DCGCWD;                            /* Watchdog Timer Deep-Sleep Mode Clock Gating Control                   */
  vuint32_t  DCGCTIMER;                         /* 16/32-Bit General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                       */
  vuint32_t  DCGCGPIO;                          /* General-Purpose Input/Output Deep-Sleep Mode Clock Gating Control     */
  vuint32_t  DCGCDMA;                           /* Micro Direct Memory Access Deep-Sleep Mode Clock Gating Control       */
  uint32_t  RESERVED36;
  vuint32_t  DCGCHIB;                           /* Hibernation Deep-Sleep Mode Clock Gating Control                      */
  vuint32_t  DCGCUART;                          /* Universal Asynchronous Receiver/Transmitter Deep-Sleep Mode
                                                         Clock Gating Control                          */
  vuint32_t  DCGCSSI;                           /* Synchronous Serial Interface Deep-Sleep Mode Clock Gating Control     */
  vuint32_t  DCGCI2C;                           /* Inter-Integrated Circuit Deep-Sleep Mode Clock Gating Control         */
  uint32_t  RESERVED37;
  vuint32_t  DCGCUSB;                           /* Universal Serial Bus Deep-Sleep Mode Clock Gating Control             */
  uint32_t  RESERVED38[2];
  vuint32_t  DCGCCAN;                           /* Controller Area Network Deep-Sleep Mode Clock Gating Control          */
  vuint32_t  DCGCADC;                           /* Analog-to-Digital Converter Deep-Sleep Mode Clock Gating Control      */
  vuint32_t  DCGCACMP;                          /* Analog Comparator Deep-Sleep Mode Clock Gating Control                */
  vuint32_t  DCGCPWM;                           /* Pulse Width Modulator Deep-Sleep Mode Clock Gating Control            */
  vuint32_t  DCGCQEI;                           /* Quadrature Encoder Interface Deep-Sleep Mode Clock Gating Control     */
  uint32_t  RESERVED39[4];
  vuint32_t  DCGCEEPROM;                        /* EEPROM Deep-Sleep Mode Clock Gating Control   */
  vuint32_t  DCGCWTIMER;                        /* 32/64-Bit Wide General-Purpose Timer Deep-Sleep Mode Clock Gating
                                                         Control                                       */
  uint32_t  RESERVED40[104];
  vuint32_t  PRWD;                              /* Watchdog Timer Peripheral Ready               */
  vuint32_t  PRTIMER;                           /* 16/32-Bit General-Purpose Timer Peripheral Ready     */
  vuint32_t  PRGPIO;                            /* General-Purpose Input/Output Peripheral Ready */
  vuint32_t  PRDMA;                             /* Micro Direct Memory Access Peripheral Ready   */
  uint32_t  RESERVED41;
  vuint32_t  PRHIB;                             /* Hibernation Peripheral Ready                  */
  vuint32_t  PRUART;                            /* Universal Asynchronous Receiver/Transmitter Peripheral Ready   */
  vuint32_t  PRSSI;                             /* Synchronous Serial Interface Peripheral Ready */
  vuint32_t  PRI2C;                             /* Inter-Integrated Circuit Peripheral Ready     */
  uint32_t  RESERVED42;
  vuint32_t  PRUSB;                             /* Universal Serial Bus Peripheral Ready         */
  uint32_t  RESERVED43[2];
  vuint32_t  PRCAN;                             /* Controller Area Network Peripheral Ready      */
  vuint32_t  PRADC;                             /* Analog-to-Digital Converter Peripheral Ready  */
  vuint32_t  PRACMP;                            /* Analog Comparator Peripheral Ready            */
  vuint32_t  PRPWM;                             /* Pulse Width Modulator Peripheral Ready        */
  vuint32_t  PRQEI;                             /* Quadrature Encoder Interface Peripheral Ready */
  uint32_t  RESERVED44[4];
  vuint32_t  PREEPROM;                          /* EEPROM Peripheral Ready                       */
  vuint32_t  PRWTIMER;                          /* 32/64-Bit Wide General-Purpose Timer Peripheral Ready   */
} SysCtrl_TypeDef;

#define SYSCTRL                                ((SysCtrl_TypeDef*)SYSCTRL_BASE)

//-----------------------------
//PRIVATE PERIPHERALS REGISTERS
//-----------------------------

#define APINT                                  *((volatile uint32*)(CORTEXM4_PERIPHERALS_BASE+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERIPHERALS_BASE+0xD04))
#define VTABLE                                 ((volatile uint32_t*)(CORTEXM4_PERIPHERALS_BASE+0xD08))//10 LSB BITS RESERVED

#define CFGCTRL                                ((volatile CFGCTRL_Tag*)(CORTEXM4_PERIPHERALS_BASE+0xD14))

//=====NVIC=====
#define NVIC_BASE                       (CORTEXM4_PERIPHERALS_BASE+0x100UL)


typedef struct{
    /*The ENn registers enable interrupts and show which interrupts are enabled.*/
    vuint32_t EN0;
    vuint32_t EN1;
    vuint32_t EN2;
    vuint32_t EN3;
    vuint32_t EN4;
    uint32_t RESERVED0[28];
    /*The DISn registers disable interrupts. */
    vuint32_t DIS0;
    vuint32_t DIS1;
    vuint32_t DIS2;
    vuint32_t DIS3;
    vuint32_t DIS4;
    uint32_t RESERVED1[28];
    /*The PENDn registers force interrupts into the pending state and show which interrupts are pending*/
    vuint32_t PIND0;
    vuint32_t PIND1;
    vuint32_t PIND2;
    vuint32_t PIND3;
    vuint32_t PIND4;
    uint32_t RESERVED2[28];
    /*The UNPENDn registers show which interrupts are pending and remove the pending state from interrupts.*/
    vuint32_t UNPIND0;
    vuint32_t UNPIND1;
    vuint32_t UNPIND2;
    vuint32_t UNPIND3;
    vuint32_t UNPIND4;
    uint32_t RESERVED3[28];
   /* The ACTIVEn registers indicate which interrupts are active.*/
    vuint32_t ACTIVE0;
    vuint32_t ACTIVE1;
    vuint32_t ACTIVE2;
    vuint32_t ACTIVE3;
    vuint32_t ACTIVE4;


}NVIC_StateType;


#define NVIC                            ((NVIC_StateType*)(NVIC_BASE))


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H_ */

/**********************************************************************************************************************
 *   END OF FILE: Mcu_Hw.h
 **********************************************************************************************************************/
