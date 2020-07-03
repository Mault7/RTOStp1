/*
 * UART.h
 *
 *  Created on: 2 jul. 2020
 *      Author: mauri
 */

#ifndef PROGRAMAS_RTOS_TP1_INC_UART_H_
#define PROGRAMAS_RTOS_TP1_INC_UART_H_

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "sapi.h"

#define length 2

QueueHandle_t queueuart;

uint8_t* datouart;

void uart_Init(void);
void senduart(uint8_t* datouart);

#endif /* PROGRAMAS_RTOS_TP1_INC_UART_H_ */
