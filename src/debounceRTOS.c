/*
 * debounceRTOS.c
 *
 *  Created on: 1 jul. 2020
 *      Author: mauri
 */

#include "debounceRTOS.h"
#include "sapi.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include <stdint.h>
#include <stdbool.h>

void debounceSM_Init(debounceButton_t *pButton, gpioMap_t key){

	pButton->buttonPressedtime 	=	0;
	pButton->buttonReleasedtime =	0;
	pButton->buttonPressdifftime= 	0;
	pButton->key 			=	key;
	pButton->buttonState 	=	UP;
	pButton->countrising	=	0;
	pButton->countfalling	=	0;

}

void debounceSM_Update(debounceButton_t *pButton){

	switch (pButton->buttonState) {

	case UP:

		pButton->buttonPressdifftime=0;

		if (!gpioRead(pButton->key)){

			pButton->buttonState = FALLING;
		}

		break;

	case FALLING:

		if (pButton->countfalling>=DEBOUNCE_TIME){

			if (!gpioRead(pButton->key)) {

				pButton->buttonState = DOWN;

				pButton->buttonPressedtime=xTaskGetTickCount();

			}

			else {

				pButton->buttonState = UP;

			}

			pButton->countfalling=0;

		}

		pButton->countfalling++;

		break;

	case DOWN:



		if (gpioRead(pButton->key)){

			pButton->buttonState = RISING;
		}

		break;

	case RISING:

		if (pButton->countrising>=DEBOUNCE_TIME) {

			if (gpioRead(pButton->key)) {

				pButton->buttonState = UP;

				pButton->buttonReleasedtime=xTaskGetTickCount();

				pButton->buttonPressdifftime=pButton->buttonReleasedtime-pButton->buttonPressedtime;

			}
			else {

				pButton->buttonState = DOWN;

			}

			pButton->countrising=0;
		}

		pButton->countrising++;

		break;

	default:

		debounceSM_Init(pButton, pButton->key);

		break;

	}
}


