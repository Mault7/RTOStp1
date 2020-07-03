/*
 * BUTTONS.h
 *
 *  Created on: 2 jul. 2020
 *      Author: mauri
 */

#ifndef PROGRAMAS_RTOS_TP1_INC_BUTTONS_H_
#define PROGRAMAS_RTOS_TP1_INC_BUTTONS_H_

#include "FreeRTOS.h"
#include "task.h"
#include "sapi.h"
#include "queue.h"
#include "debounceRTOS.h"


debounceButton_t tecla_1,tecla_2;

void buttonsInit(void);



#endif /* PROGRAMAS_RTOS_TP1_INC_BUTTONS_H_ */
