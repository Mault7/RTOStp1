/*=============================================================================
 * Copyright (c) 2020, Mauricio Lara <torneosmau@gmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2020/07/02
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef __USER_TASKS_H__
#define __USER_TASKS_H__

/*=====[Inclusions of public function dependencies]==========================*/

#include "FreeRTOS.h"
#include "task.h"
#include "sapi.h"
#include "queue.h"

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

/*=====[Prototypes (declarations) of public functions]=======================*/


void ledInit(void);
/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* __USER_TASKS_H__ */
