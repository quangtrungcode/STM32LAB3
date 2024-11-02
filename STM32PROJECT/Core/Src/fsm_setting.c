/*
 * fsm_setting.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "fsm_setting.h"

//int checksave=0;
void fsm_setting_run(){
      switch(status){
		  case INCREASE_VALUE_LED_RED:
//			  	Increase_Save_led7RED_segment_run13();
				if(checksave==0){
				//	Save_led7RED_segment_run13();
					Increase_Save_led7RED_segment_run13();
					++checksave;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 400);
				}
				if(isTimerExpired(2)==1){
//					if(checksave==0){
//						Increase_Save_led7RED_segment_run13();
//						checksave=1;
//					}
					Save_led7RED_segment_run13();
					setTimer(2, 1000);
		//			setTimer(4, 10000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
					setTimer(3, 500);
				}
				if(isTimerExpired(4)==1){
					status=AUTO_RED1_GREEN2;
					counter=0;
					++countergreen13;
					counterred13=savecounterred13-checksave;
					checksave=0;
					--idx_led13;
					setTimer(0, countergreen13*1000);
		               setTimer(1, 443);
		               setTimer(2, 1000);
				}
				if(isTimerExpired(5)==1){
					status=AUTO_RED1_YELLOW2;
					counter=0;
					if(counterred13!=a) {
						++counteryellow13;
						counterred13=savecounterred13-checksave;
					}
					else{
						counterred13=1;
						counteryellow13=1;
					}
					checksave=0;
					--idx_led13;
					setTimer(0, counteryellow13*1000);
		               setTimer(1, 443);
		               setTimer(2, 1000);
				}
				if(isTimerExpired(6)==1){
					status=AUTO_GREEN1_RED2;
					counter=0;
					++countergreen13;
					counterred13=savecounterred13-checksave;
					checksave=0;
					--idx_led13;
					setTimer(0, countergreen13*1000);
		               setTimer(1, 443);
		               setTimer(2, 1000);
				}
				if(isTimerExpired(7)==1){
					status=AUTO_YELLOW1_RED2;
					counter=0;
					if(counterred13!=a) {
						++counteryellow13;
						counterred13=savecounterred13-checksave;
					}
					else{
						counterred13=1;
						counteryellow13=1;
					}
					checksave=0;
					--idx_led13;
					setTimer(0, counteryellow13*1000);
		               setTimer(1, 443);
		               setTimer(2, 1000);
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
					++checksave;
				    Increase_Save_led7RED_segment_run13();
				    setTimer(checkstatus, 10000);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_RED;
					checksave=0;
				//	  setTimer(checkstatus, 10000);
//					  counterred13 = savecounterred13;
//					  countergreen13=counterred13-counteryellow13;
//					  counteryellow13=counterred13-countergreen13;
//					  a=counterred13;
//					  b=countergreen13;
//					  c=counteryellow13;
				}

			  break;
		  case SET_VALUE_LED_RED:
			  counterred13 = savecounterred13;
			  countergreen13=counterred13-counteryellow13;
			  counteryellow13=counterred13-countergreen13;
			//  savecountergreen13=countergreen13;
			  a=counterred13;
			  b=countergreen13;
			  c=counteryellow13;
				if(checksave==0){
					Save_led7RED_segment_run13();
					//Increase_Save_led7RED_segment_run13();
					checksave=1;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 400);
				}
				if(isTimerExpired(2)==1){
//					if(checksave==0){
//						Increase_Save_led7RED_segment_run13();
//						checksave=1;
//					}
					Save_led7RED_segment_run13();
					setTimer(2, 1000);
		//			setTimer(4, 10000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
					setTimer(3, 500);
				}
//				if(isTimerExpired(checkstatus)==1){
//					status=AUTO_RED1_GREEN2;
//					counter=0;
//					//++countergreen13;
//					//counterred13;
//					idx_led13=0;
//					setTimer(0, b*1000);
//		            setTimer(1, 443);
//		            setTimer(2, 1000);
//				}
//				if(isTimerExpired(5)==1){
//					status=AUTO_RED1_YELLOW2;
//					if(counterred13!=a) {
//						++counteryellow13;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//				}
//				if(isTimerExpired(6)==1){
//					status=AUTO_GREEN1_RED2;
//					++countergreen13;
//					//++counterred13;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//				}
//				if(isTimerExpired(7)==1){
//					status=AUTO_YELLOW1_RED2;
//					if(counterred13!=a) {
//						++counteryellow13;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//				}
//				if(isButtonPressed(0)==1){
//					status= MAN_GREEN;
//					check=0;
//					setTimer(1, 400);
//					setTimer(2, 1000);
//					setTimer(3, 500);
//					setTimer(checkstatus, 10000);
//					checkcountergreen=1;
//				}
				if(isButtonPressed(1)==1){
					status=INCREASE_VALUE_LED_RED;
					//Increase_Save_led7RED_segment_run13();
					checksave=0;
					setTimer(1, 400);
					setTimer(2, 1000);
					setTimer(3, 500);
					setTimer(checkstatus, 10000);
				}
				if(isButtonPressed(2)==1){
					status=AUTO_RED1_GREEN2;
					counter=0;
					//++countergreen13;
					//counterred13;
					idx_led13=0;
					setTimer(0, b*1000);
		            setTimer(1, 443);
		            setTimer(2, 1000);
				}

			  break;
		  default:
			  break;
      }
}
