/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: Ahmed Aboraya
 */


/**
 ******************************************************************************
 *    FILE DESCRIPTION
 *  ----------------------------------------------------------------------------
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************

 ******************************************************************************
 */

#include "system_TM4C123.h"
#include "App_00_LedCtrl.h"
#include "IntCtrl.h"
#include "GPIO.h"
#include "Timer.h"

#define ONTime          500
#define OFFTime         500
int main(void)
{
		SystemInit();
    IntCrtl_Init(IRQ_Cfg);
    GPIO_Init(Port_Cfg);
    LedCtrl_Init();


    while(1){
        LedCtrl_SetON(ONTime);
        LedCtrl_SetOFF(OFFTime);
    }
}
