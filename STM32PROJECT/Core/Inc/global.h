/*
 * global.h
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "traffic_light.h"
#include "led7_segment.h"
#include "fsm_automatic.h"
#include "fsm_manual.h"
#define INIT 1
#define AUTO_RED1_GREEN2 2
#define AUTO_RED1_YELLOW2 3
#define AUTO_GREEN1_RED2 4
#define AUTO_YELLOW1_RED2 5

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14
#define INCREASE_VALUE_LED_RED 15
#define SET_VALUE_LED_RED 16
#define SAVE_VALUE_LED_RED 17
extern int status;

#endif /* INC_GLOBAL_H_ */
