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

//=========inicializacion del antirebote==========//
	debounceSM_Init(&tecla_1,TEC1);
	debounceSM_Init(&tecla_2,TEC2);
//================================================//

	BaseType_t tarea=xTaskCreate(
			buttons,
			(const char *)"buttons",
			configMINIMAL_STACK_SIZE*3 ,
			0,
			tskIDLE_PRIORITY+1,
			0
	);

	if(tarea==pdFALSE)
	{

	//==========Mensaje de error de creacion de tarea==========//
		printf("No se pudo crear tarea buttons\r\n");

		while(TRUE)

		{
	//=================Alerta de Tarea no creada =============//
			gpioWrite(LED1,ON);

		}

	}


}


static void buttons( void* taskParmPtr )
{

	while (TRUE)
	{

	//==========Actualiacion de botones==========//
		debounceSM_Update(&tecla_1);

		debounceSM_Update(&tecla_2);
	//===========================================//

		vTaskDelay(1/portTICK_RATE_MS);

	//======== lectura de tiempos ante presionado de teclas ====//

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
	//========================================================//
}
