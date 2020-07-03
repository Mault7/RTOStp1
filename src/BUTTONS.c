/*
 * BUTTONS.c
 *
 *  Created on: 2 jul. 2020
 *      Author: mauri
 */

#include "BUTTONS.h"
#include "UART.h"


static void buttons( void* taskParmPtr );


void buttonsInit(void)
{

	debounceSM_Init(&tecla_1,TEC1);
	debounceSM_Init(&tecla_2,TEC2);


	BaseType_t tarea=xTaskCreate(
			buttons,                     // Function that implements the task.
			(const char *)"buttons",     // Text name for the task.
			configMINIMAL_STACK_SIZE*3 , // Stack size in words, not bytes.
			0,                          // Parameter passed into the task.
			tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			0                           // Pointer to the task created in the system
	);

	if(tarea==pdFALSE)
	{

		printf("No se pudo crear tarea buttons\r\n");

		while(TRUE)

		{

			gpioWrite(LED1,ON);

		}

	}


}


static void buttons( void* taskParmPtr )
{

	while (TRUE)
	{

		debounceSM_Update(&tecla_1);

		debounceSM_Update(&tecla_2);

		vTaskDelay(1/portTICK_RATE_MS);

		if(tecla_1.buttonPressdifftime!=0)
		{

			uint8_t msgtec1[20];

			sprintf(msgtec1, "tec1 t %i ms", tecla_1.buttonPressdifftime);

			senduart(msgtec1);


		}

		if(tecla_2.buttonPressdifftime!=0)

		{
			uint8_t msgtec2[20];

			sprintf(msgtec2, "tec2 t %i ms", tecla_2.buttonPressdifftime);

			senduart(msgtec2);


		}

	}

}
