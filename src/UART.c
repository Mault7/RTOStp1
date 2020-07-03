/*
 * UART.c
 *
 *  Created on: 2 jul. 2020
 *      Author: mauri
 */

#include "UART.h"

static void uarttask( void* taskParmPtr );

void uart_Init(void)
{

	queueuart=xQueueCreate(length, sizeof(uint8_t*));

	if(queueuart==pdFALSE)
	{

		printf("No se pudo crear COLA queueuart\r\n");

		while(TRUE)
		{

			gpioWrite(LED1,ON);

		}

	}


	BaseType_t tarea=xTaskCreate(
			uarttask,                     // Function that implements the task.
			(const char *)"uarttask",     // Text name for the task.
			configMINIMAL_STACK_SIZE*3, // Stack size in words, not bytes.
			0,                          // Parameter passed into the task.
			tskIDLE_PRIORITY+1,         // Priority at which the task is created.
			0                           // Pointer to the task created in the system
	);

	if(tarea==pdFALSE)
	{

		printf("No se pudo crear tarea uarttask\r\n");

		while(TRUE)

		{

			gpioWrite(LED1,ON);

		}

	}



}


static void uarttask( void* taskParmPtr )
{

	while (TRUE)
	{

		if(xQueueReceive(queueuart,(void*)&datouart,portMAX_DELAY==pdTRUE))
		{

			printf("%s\r\n",datouart);

		}

	}

}


void senduart(uint8_t *datouart)
{
	xQueueSend(queueuart, (void *) &datouart, portMAX_DELAY);

}

