/*
 * debounceRTOS.h
 *
 *  Created on: 1 jul. 2020
 *      Author: mauri
 */

#ifndef PROGRAMAS_TPRTOSII_INC_DEBOUNCERTOS_H_
#define PROGRAMAS_TPRTOSII_INC_DEBOUNCERTOS_H_

#include "FreeRTOS.h"
#include "task.h"
#include "sapi.h"
#include "queue.h"


#define DEBOUNCE_TIME 40

typedef enum{
   UP,
   FALLING,
   DOWN,
   RISING
} debounceState_t;

typedef struct {
	uint32_t buttonPressedtime;
	uint32_t buttonReleasedtime;
	uint32_t buttonPressdifftime;
	gpioMap_t key;
	debounceState_t buttonState;
	uint8_t countfalling;
	uint8_t countrising;
} debounceButton_t;



void debounceSM_Init(debounceButton_t *pButton, gpioMap_t key);
void debounceSM_Update(debounceButton_t *pButton);



#endif /* PROGRAMAS_TPRTOSII_INC_DEBOUNCERTOS_H_ */
