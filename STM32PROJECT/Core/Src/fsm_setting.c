/*
 * fsm_setting.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "fsm_setting.h"

int checksave=0;
void fsm_setting_run(){
      switch(status){
		  case INCREASE_VALUE_LED_RED:
//			  	Increase_Save_led7RED_segment_run13();
//				if(checksave==0){
//				//	Save_led7RED_segment_run13();
//					Increase_Save_led7RED_segment_run13();
//					checksave=1;
//				}
//				if(isTimerExpired(1)==1){
//					led7_segment_run02();
//					setTimer(1, 400);
//				}
				if(isTimerExpired(2)==1){
					if(checksave==0){
						Increase_Save_led7RED_segment_run13();
						checksave=1;
					}
					Save_led7RED_segment_run13();
					setTimer(2, 1000);
		//			setTimer(4, 10000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
					setTimer(3, 500);
				}
				if(isTimerExpired(4)==1){
					status=INIT;
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
				    Increase_Save_led7RED_segment_run13();
				    setTimer(4, 10000);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_RED;
				//	setTimer(1, 400);
					setTimer(2, 1000);
				//	setTimer(3, 500);
				//	setTimer(4, 10000);
				}

			  break;
		  case SET_VALUE_LED_RED:
			  counterred13 = savecounterred13;
			  countergreen13=counterred13-counteryellow13;
			  counteryellow13=counterred13-countergreen13;
			  a=counterred13;
			  b=countergreen13;
			  c=counteryellow13;
			  if(isTimerExpired(2)==1){
				  status=INIT;
			  }
			  break;
		  default:
			  break;
      }
}
