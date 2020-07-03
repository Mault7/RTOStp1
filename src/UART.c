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
		//==========Mensaje de error en  creacion de cola==========//
		printf("No se pudo crear COLA queueuart\r\n");

		while(TRUE)
		{
		//=================Alerta de cola no creada =============//
			gpioWrite(LED1,ON);

		}

	}


	BaseType_t tarea=xTaskCreate(
			uarttask,
			(const char *)"uarttask",
			configMINIMAL_STACK_SIZE*3,
			0,
			tskIDLE_PRIORITY+1,
			0
	);

	if(tarea==pdFALSE)
	{
		//==========Mensaje de error de creacion de tarea==========//
		printf("No se pudo crear tarea uarttask\r\n");

		while(TRUE)

		{
		//=================Alerta de tarea no creada =============//
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

