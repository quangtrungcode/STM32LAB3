/*
 * fsm_automatic.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"
#include "global.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
               set_led();
               status=MODE1;
			break;
		case AUTO_RED1_GREEN2:
			LED_RED1_GREEN2();
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_YELLOW2;
				setTimer(0, 2000);
			}
			break;
		case AUTO_RED1_YELLOW2:
			LED_RED1_YELLOW2();
			if(isTimerExpired(0)==1){
				status=AUTO_GREEN1_RED2;
				setTimer(0, 3000);
			}
			break;
		case AUTO_GREEN1_RED2:
			LED_GREEN1_RED2();
			if(isTimerExpired(0)==1){
				status=AUTO_YELLOW1_RED2;
				setTimer(0, 2000);
			}
			break;
		case AUTO_YELLOW1_RED2:
			LED_YELLOW1_RED2();
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_GREEN2;
				setTimer(0, 3000);
			}
			break;
		default:
			break;
	}
}
