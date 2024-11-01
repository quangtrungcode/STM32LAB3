/*
 * fsm_manual.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "fsm_manual.h"
#include "global.h"

int check=0;
void fsm_manual_run(){
	switch(status){
	case MAN_RED:
//		HAL_Delay(1000);
//		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		//HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, RESET);
		if(check==0){
			Turn_On_All_LED_RED();
			Save_led7RED_segment_run13();
			check=1;
		}
		if(isTimerExpired(1)==1){
			led7_segment_run02();
			setTimer(1, 400);
		}
		if(isTimerExpired(2)==1){
			Save_led7RED_segment_run13();
			setTimer(2, 1000);
		}
		if(isTimerExpired(3)==1){
			HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
			setTimer(3, 500);
		}
		if(isTimerExpired(4)==1){
			status=AUTO_RED1_GREEN2;
//			++countergreen13;
//			++counterred13;
//			--idx_led13;
			setTimer(0, countergreen13*1000);
		}
		if(isTimerExpired(5)==1){
			status=AUTO_RED1_YELLOW2;
			if(counterred13==a) {
				counterred13=0;
				counteryellow13=0;
			}
			++counteryellow13;
			++counterred13;
			setTimer(0, counteryellow13*1000);
		}
		if(isTimerExpired(6)==1){
			status=AUTO_GREEN1_RED2;
			++countergreen13;
			++counterred13;
			setTimer(0, countergreen13*1000);
		}
		if(isTimerExpired(7)==1){
			status=AUTO_YELLOW1_RED2;
			if(counterred13==a) {
				counterred13=0;
				counteryellow13=0;
			}
			++counteryellow13;
			++counterred13;
			setTimer(0, counteryellow13*1000);
		}
		if(isButtonPressed(0)==1){
			status= MAN_GREEN;
			check=0;
			setTimer(1, 400);
			setTimer(2, 1000);
			setTimer(3, 500);
			setTimer(4, 10000);
		}
		if(isButtonPressed(1)==1){
			status=INCREASE_VALUE_LED_RED;
			//Increase_Save_led7RED_segment_run13();
			setTimer(1, 400);
			setTimer(2, 1000);
			setTimer(3, 500);
			setTimer(4, 10000);
		}
		if(isButtonPressed(2)==1){

		}
		break;
	case INCREASE_VALUE_LED_RED:
		break;
	case SET_VALUE_LED_RED:
		break;
	case MAN_GREEN:
		if(check==0){
			Turn_On_All_LED_GREEN();
			check=1;
		}
		if(isTimerExpired(3)==1){
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
			setTimer(3, 500);
		}
		if(isButtonPressed(0)==1){
			status= MAN_YELLOW;
			check=0;
			setTimer(3, 500);
		}
		break;
	case MAN_YELLOW:
		if(check==0){
			Turn_On_All_LED_YELLOW();
			check=1;
		}
		if(isTimerExpired(3)==1){
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
			setTimer(3, 500);
		}
		if(isButtonPressed(0)==1){
//			status= AUTO_RED1_GREEN2;
//            set_led();
//            set_led7_segement();
//            setTimer(0, 3000);
//            setTimer(1, 400);
//            setTimer(2, 1000);
//            counter=0;
			status=INIT;
		}
		break;
	default:
		break;
	}
}
