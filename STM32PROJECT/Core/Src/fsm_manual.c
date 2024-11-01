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
		if(check==0){
			Turn_On_All_LED_RED();
			check=1;
		}
		if(isTimerExpired(3)==1){
			HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
			setTimer(3, 500);
		}
		if(isButtonPressed(0)==1){
			status= MAN_GREEN;
			check=0;
			setTimer(3, 500);
		}
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
			status= AUTO_RED1_GREEN2;
            set_led();
            set_led7_segement();
            setTimer(0, 3000);
            setTimer(1, 400);
            setTimer(2, 1000);
            counter=0;
		}
		break;
	default:
		break;
	}
}
