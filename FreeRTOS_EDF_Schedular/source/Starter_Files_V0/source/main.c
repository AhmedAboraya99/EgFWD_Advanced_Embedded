/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"
#include "queue.h"
/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )

//-------------------------------------------------
// Global Macros
//-------------------------------------------------
#define TASK1_PERIOD 	50
#define TASK2_PERIOD	50
#define TASK3_PERIOD	100
#define TASK4_PERIOD	20
#define TASK5_PERIOD	10
#define TASK6_PERIOD	100
#define MAX_WAIT_TIME	1
#define MESSAGE_STRING_LENGTH 20
//-------------------------------------------------
// Global Variables
//-------------------------------------------------
int Task1_InTime	= 0, Task1_OutTime = 0, Task1_TotalTime = 0;
int Task2_InTime	= 0, Task2_OutTime = 0, Task2_TotalTime = 0;
int Task3_InTime	= 0, Task3_OutTime = 0, Task3_TotalTime = 0;
int Task4_InTime	= 0, Task4_OutTime = 0, Task4_TotalTime = 0;
int Task5_InTime	= 0, Task5_OutTime = 0, Task5_TotalTime = 0;
int Task6_InTime	= 0, Task6_OutTime = 0, Task6_TotalTime = 0;

int CPU_Load = 0;
int systemTime = 0;
//flagState_t button1_flag, button2_flag ;
QueueHandle_t ConsumerQueue;

void Timer1Reset(void)
{
	const unsigned long TCR_COUNT_RESET = 2;
	T1TCR |= TCR_COUNT_RESET;
	T1TCR &= ~TCR_COUNT_RESET;
}

void vConfigureTimerForRunTimeStats( void )
{
const unsigned long TCR_COUNT_ENABLE = 0x01;

    /* Prescale to a frequency that is good enough to get a decent resolution,
    but not too fast so as to overflow all the time. */
    T1PR =  ( configCPU_CLOCK_HZ / 60000UL );

    /* Start the counter. */
    T1TCR |= TCR_COUNT_ENABLE;
}

/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/


/* Button 1 Monitor task implementation. */
void Button_1_Monitor( void * pvParameters )
{
		TickType_t xLastWakeTime ;
		message_t MessageBuffer ;
		bool MessageFlag ;
	
		pinState_t CurrButtonState, PrevButtonState = GPIO_read(PORT_1, PIN0);
		MessageBuffer.ucMessageID = 1 ;

	/* This task is going to be represented by a voltage scale of 1. */
		 vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 1 );
		
		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        /* Task code goes here. */
			// monitor button 1 pin
			CurrButtonState = GPIO_read(PORT_1, PIN0);
			if(CurrButtonState != PrevButtonState){
				PrevButtonState = CurrButtonState ;
				if(CurrButtonState == PIN_IS_LOW ){//Detecting falling edge
					strcpy((char *)MessageBuffer.ucData, "\nButton1: falling edge"); 
					MessageFlag = true;
				}else{ //Detecting rising edge
					strcpy((char *)MessageBuffer.ucData, "\nButton1: rising edge");
					MessageFlag = true;
				}
			}else {MessageFlag = false;} //no change 
			
			if(MessageFlag == true){
			xQueueSend(ConsumerQueue, &MessageBuffer, MAX_WAIT_TIME );
		}
		// periodic task every 50 ms
			vTaskDelayUntil(&xLastWakeTime, TASK1_PERIOD);
	}
}

	//"Button 1 Monitor" task handler
	TaskHandle_t Button_1_MonitorHandler = NULL;

/* Button 2 Monitor task implementation. */
void Button_2_Monitor( void * pvParameters )
{
		TickType_t xLastWakeTime ;
		message_t MessageBuffer;
		bool MessageFlag ;
		
		pinState_t CurrButtonState, PrevButtonState = GPIO_read(PORT_1, PIN1);
		MessageBuffer.ucMessageID = 2;
  
	/* This task is going to be represented by a voltage scale of 2. */
		 vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 2 );
		
		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount();
    for( ;; )
    {
			
			CurrButtonState = GPIO_read(PORT_1, PIN1);
			
			if(CurrButtonState != PrevButtonState){
				PrevButtonState = CurrButtonState ;
				if(CurrButtonState == PIN_IS_LOW ){ //Detecting falling edge
					strcpy((char *)MessageBuffer.ucData, "\nButton2: falling edge");
					MessageFlag = true;
				}else{ //Detecting rising edge
					strcpy((char *)MessageBuffer.ucData, "\nButton2: rising edge");
					MessageFlag = true;
				}
			}else {MessageFlag = false;} //no change 
			
			if(MessageFlag == true){
			xQueueSend(ConsumerQueue, &MessageBuffer, MAX_WAIT_TIME );
		}
			// periodic task every 50 ms
			vTaskDelayUntil(&xLastWakeTime, TASK2_PERIOD);
    }

}

	// "Button 2 Monitor" task handler
	TaskHandle_t Button_2_MonitorHandler = NULL;

/* Periodic Transmitter task implementation. */
void Periodic_Transmitter( void * pvParameters )
{
		TickType_t xLastWakeTime;
		message_t MessageBuffer ;
		MessageBuffer.ucMessageID = 3 ;

		/* This task is going to be represented by a voltage scale of 3. */
		 vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 3 );
	
		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount();
    for( ;; )
    {
        /* Task code goes here. */
			//send string
			strcpy((char *)MessageBuffer.ucData, "\nPeriodic String");
			xQueueSend(ConsumerQueue, &MessageBuffer, MAX_WAIT_TIME );
			
			//  periodic task every 100 ms
			vTaskDelayUntil(&xLastWakeTime, TASK3_PERIOD);
    }
}
	// "Periodic Transmitter" task handler
	TaskHandle_t Periodic_TransmitHandler = NULL;

	/* Uart Receiver task implementation. */
void Uart_Receiver( void * pvParameters )
{		
		TickType_t xLastWakeTime;
		message_t MessageBuffer;
		unsigned short StringLength ;
		
	   /* This task is going to be represented by a voltage scale of 4. */
		 vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 4 );
		// Initialise the xLastWakeTime variable with the current time.
		xLastWakeTime = xTaskGetTickCount();
    for( ;; )
    {	//receive message from queue buffer 
			if( xQueueReceive( ConsumerQueue,
                         &( MessageBuffer),
                         ( TickType_t ) MAX_WAIT_TIME) == pdPASS )
      {
				//send message to uart
				StringLength = strlen(MessageBuffer.ucData);
        vSerialPutString(( signed char *)(MessageBuffer.ucData), StringLength);
					
				
			}
			// periodic task every 20 ms
			vTaskDelayUntil(&xLastWakeTime, TASK4_PERIOD);
		}
}
	// "Uart Receiver" task handler
	TaskHandle_t Uart_ReceiveHandler = NULL;

void Load_1_Simulation( void * pvParameters )
{
	int i=0;
	TickType_t xLastWakeTime ;
	/* This task is going to be represented by a voltage scale of 5. */
	vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 5 );
	
	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();
	for(;;){
		for(i=0;i<37500;i++)
		{
			//Execution Time = 5ms
		}
		vTaskDelayUntil(&xLastWakeTime, TASK5_PERIOD);
	}

}

void Load_2_Simulation( void * pvParameters )
{
	int i=0;
	TickType_t xLastWakeTime;
	/* This task is going to be represented by a voltage scale of 6. */
	vTaskSetApplicationTaskTag(NULL, (TaskHookFunction_t) 6);
	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();
	for(;;){
		for(i=0;i<=90000;i++)	
		{
				//Execution Time = 12ms 
		}
			vTaskDelayUntil(&xLastWakeTime, TASK6_PERIOD);
	}
}
	// Task creation return status
	BaseType_t xReturned;

void vApplicationTickHook( void )
{
	GPIO_write(PORT_0, PIN0,PIN_IS_HIGH);
	GPIO_write(PORT_0, PIN0,PIN_IS_LOW);	
}

/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
		/* Setup the hardware for use with the Keil demo board. */
		prvSetupHardware();
		
	  ConsumerQueue = xQueueCreate( QUEUE_LENGTH, ITEM_SIZE);
    /* Create Tasks here */
		
    xReturned = xTaskPeriodicCreate(
                    Button_1_Monitor,       /* Function that implements the task. */
                    "Button 1 Monitor",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &Button_1_MonitorHandler,
										TASK1_PERIOD);      /* Used to pass out the created task's handle. */
										
    xReturned = xTaskPeriodicCreate(
                    Button_2_Monitor,       /* Function that implements the task. */
                    "Button 2 Monitor",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &Button_2_MonitorHandler,
										TASK2_PERIOD);      /* Used to pass out the created task's handle. */
										
    xReturned = xTaskPeriodicCreate(
                    Periodic_Transmitter,       /* Function that implements the task. */
                    "Periodic Transmitter",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &Periodic_TransmitHandler,
										TASK3_PERIOD);      /* Used to pass out the created task's handle. */	
										
    xReturned = xTaskPeriodicCreate(
                    Uart_Receiver,       /* Function that implements the task. */
                    "Uart Receiver",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    &Uart_ReceiveHandler,
										TASK4_PERIOD);      /* Used to pass out the created task's handle. */	
										
		xReturned = xTaskPeriodicCreate(
                    Load_1_Simulation,       /* Function that implements the task. */
                    "Load 1 Simulation",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    (TaskHandle_t *)NULL,
										TASK5_PERIOD);      /* Used to pass out the created task's handle. */	
										
    xReturned = xTaskPeriodicCreate(
                    Load_2_Simulation,       /* Function that implements the task. */
                    "Load2 Simulation",          /* Text name for the task. */
                    90,      /* Stack size in words, not bytes. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    1,/* Priority at which the task is created. */
                    (TaskHandle_t *)NULL,
										TASK6_PERIOD);      /* Used to pass out the created task's handle. */	

	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/


