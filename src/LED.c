/*=============================================================================
 * Copyright (c) 2020, Mauricio Lara <torneosmau@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/07/02
 *===========================================================================*/

/*=====[Inclusion of own header]=============================================*/

#include "LED.h"
#include "UART.h"

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

// Task implementation

static void LEDTASK( void* taskParmPtr );


void ledInit(void)
{
	BaseType_t tarea=xTaskCreate(
			LEDTASK,                     // Function that implements the task.
			(const char *)"LEDTASK",     // Text name for the task.
			configMINIMAL_STACK_SIZE*2, // Stack size in words, not bytes.
			0,                          // Parameter passed into the task.
			tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			0                           // Pointer to the task created in the system
	);

	if(tarea==pdFALSE)
	{

		printf("No se pudo crear tarea LED\r\n");

		while(TRUE)
		{

			gpioWrite(LED1,ON);

		}

	}

}




static void LEDTASK( void* taskParmPtr )
{


	while(TRUE) {

		gpioWrite( LED3, ON );


		senduart("led on");

		vTaskDelay( 500 / portTICK_RATE_MS );

		gpioWrite( LED3, OFF );

		vTaskDelay( 500 / portTICK_RATE_MS );

	}
}

/*=====[Implementations of interrupt functions]==============================*/

/*=====[Implementations of private functions]================================*/

