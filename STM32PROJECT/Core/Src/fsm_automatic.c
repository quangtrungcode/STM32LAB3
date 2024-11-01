/*
 * fsm_automatic.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"
#include "global.h"

int counter=0;
void fsm_automatic_run(){
	switch(status){
		case INIT:
               set_led();
               set_led7_segement();
               status=AUTO_RED1_GREEN2;
               setTimer(0, 3000);
               setTimer(1, 400);
               setTimer(2, 1000);
			break;
		case AUTO_RED1_GREEN2:
			LED_RED1_GREEN2();
			if(counter==0){
			led7_segment_run13();
			counter=1;
			}
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 400);
			}
			if(isTimerExpired(2)==1){
					led7_segment_run13();
					setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_YELLOW2;
				setTimer(0, 2000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;

				setTimer(3, 500);
			}
			break;
		case AUTO_RED1_YELLOW2:
			LED_RED1_YELLOW2();
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 400);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_GREEN1_RED2;
				setTimer(0, 3000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;

				setTimer(3, 500);
			}
			break;
		case AUTO_GREEN1_RED2:
			LED_GREEN1_RED2();
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 400);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_YELLOW1_RED2;
				setTimer(0, 2000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;

				setTimer(3, 500);
			}
			break;
		case AUTO_YELLOW1_RED2:
			LED_YELLOW1_RED2();
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 400);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_GREEN2;
				setTimer(0, 3000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;

				setTimer(3, 500);
			}
			break;
		default:
			break;
	}
}
