/*=============================================================================
 * Copyright (c) 2020, Mauricio Lara <torneosmau@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/07/02
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "RTOS_tp1.h"

#include "LED.h"
#include "BUTTONS.h"
#include "UART.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
	//==========Inicialiacion de la placa=========//
	boardInit();
	//==========Creacion de la tarea led==========//
	ledInit();
	//==========Creacion de la tarea botones======//
	buttonsInit();
	//==========Creacion de la tarea UART======//
	uart_Init();
	//==========Inicializacion del scheduler======//
	vTaskStartScheduler();

	return 0;
}
