/*
 * fsm_setting.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "fsm_setting.h"

//int checksavered=0;
void fsm_setting_run(){
      switch(status){
		  case INCREASE_VALUE_LED_RED:
//			  	Increase_Save_led7RED_segment_run13();
				if(checksavered==0){
				//	Save_led7RED_segment_run13();
					Increase_Save_led7RED_segment_run13();
					++checksavered;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 487);
				}
				if(isTimerExpired(2)==1){
//					if(checksavered==0){
//						Increase_Save_led7RED_segment_run13();
//						checksavered=1;
//					}
					Save_led7RED_segment_run13();
					setTimer(2, 1000);
		//			setTimer(4, 10000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
					setTimer(3, 500);
				}
//				if(isTimerExpired(4)==1){
//					status=AUTO_RED1_GREEN2;
//					counter=0;
//					++countergreen13;
//					counterred13=savecounterred13-checksavered;
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(5)==1){
//					status=AUTO_RED1_YELLOW2;
//					counter=0;
//					if(counterred13!=a) {
//						++counteryellow13;
//						counterred13=savecounterred13-checksavered;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(6)==1){
//					status=AUTO_GREEN1_RED2;
//					counter=0;
//					++countergreen13;
//					counterred13=savecounterred13-checksavered;
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, countergreen13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}
//				if(isTimerExpired(7)==1){
//					status=AUTO_YELLOW1_RED2;
//					counter=0;
//					if(counterred13!=a) {
//						++counteryellow13;
//						counterred13=savecounterred13-checksavered;
//					}
//					else{
//						counterred13=1;
//						counteryellow13=1;
//					}
//					checksavered=0;
//					--idx_led13;
//					setTimer(0, counteryellow13*1000);
//		               setTimer(1, 443);
//		               setTimer(2, 1000);
//				}

				if(isButtonPressed(0)==1){
					status= MAN_GREEN;
					check=0;
					setTimer(1, 487);
					setTimer(2, 1000);
					setTimer(3, 500);
					setTimer(4, 10000);
				}
				if(isButtonPressed(1)==1){
					++checksavered;
				    Increase_Save_led7RED_segment_run13();
				 //   setTimer(checkstatus, 10000);
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_RED;
					checksavered=0;
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
			  Turn_On_All_LED_RED();
			  counterred13 = savecounterred13;
			//  countergreen13=counterred13-counteryellow13;
			// counteryellow13=counterred13-countergreen13;
			//  savecountergreen13=countergreen13;
			//  a=counterred13;
			//  b=countergreen13;
			//  c=counteryellow13;
				if(checksavered==0){
					Save_led7RED_segment_run13();
					//Increase_Save_led7RED_segment_run13();
					checksavered=1;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 487);
				}
				if(isTimerExpired(2)==1){
//					if(checksavered==0){
//						Increase_Save_led7RED_segment_run13();
//						checksavered=1;
//					}
					Save_led7RED_segment_run13();
					setTimer(2, 1000);
		//			setTimer(4, 10000);
				}
//				if(isTimerExpired(3)==1){
//					HAL_GPIO_TogglePin(GPIOA, LED_RED1_Pin|LED_RED2_Pin);
//					setTimer(3, 500);
//				}
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
//					setTimer(1, 487);
//					setTimer(2, 1000);
//					setTimer(3, 500);
//					setTimer(checkstatus, 10000);
//					checkcountergreen=1;
//				}
				if(isButtonPressed(0)==1){
					status= MAN_GREEN;
					check=0;
					setTimer(1, 487);
					setTimer(2, 1000);
					setTimer(3, 500);
				//	setTimer(4, 10000);
				}
				if(isButtonPressed(1)==1){
					status=INCREASE_VALUE_LED_RED;
					//Increase_Save_led7RED_segment_run13();
					checksavered=0;
					setTimer(1, 487);
					setTimer(2, 1000);
					setTimer(3, 500);
				//	setTimer(checkstatus, 10000);
				}
//				if(isButtonPressed(2)==1){
//					status=SAVE_VALUE_LED_RED;
////					status=AUTO_RED1_GREEN2;
////					counter=0;
////					//++countergreen13;
////					//counterred13;
////					idx_led13=0;
////					setTimer(0, b*1000);
////		            setTimer(1, 443);
////		            setTimer(2, 1000);
//				}

			  break;
		  case SAVE_VALUE_LED_RED:
			  					status=AUTO_RED1_GREEN2;
			  					counter=0;
			  					idx_led13=0;
			  					setTimer(0, b*1000);
			  		            setTimer(1, 443);
			  		            setTimer(2, 1000);
			  break;
		  case INCREASE_VALUE_LED_GREEN:
				if(checksavegreen==0){
					Increase_Save_led7GREEN_segment_run13();
					++checksavegreen;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 487);
				}
				if(isTimerExpired(2)==1){
					Save_led7GREEN_segment_run13();
					setTimer(2, 1000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
					setTimer(3, 500);
				}
				if(isButtonPressed(0)==1){
					status= MAN_YELLOW;
					check=0;
					checksaveyellow=0;
					setTimer(1, 487);
					setTimer(2, 1000);
					setTimer(3, 500);
					setTimer(4, 10000);
				}
				if(isButtonPressed(1)==1){
					++checksavegreen;
				    Increase_Save_led7GREEN_segment_run13();
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_GREEN;
					checksavegreen=0;
				}
			  break;
		  case SET_VALUE_LED_GREEN:
                      Turn_On_All_LED_GREEN();
		  			  countergreen13 = savecountergreen13;
		  			 // b=countergreen13;
		  				if(checksavegreen==0){
		  					Save_led7GREEN_segment_run13();
		  					checksavegreen=1;
		  				}
		  				if(isTimerExpired(1)==1){
		  					led7_segment_run02();
		  					setTimer(1, 487);
		  				}
		  				if(isTimerExpired(2)==1){
		  					Save_led7GREEN_segment_run13();
		  					setTimer(2, 1000);
		  				}
//		  				if(isTimerExpired(3)==1){
//		  					HAL_GPIO_TogglePin(GPIOA, LED_GREEN1_Pin|LED_GREEN2_Pin);
//		  					setTimer(3, 500);
//		  				}
		  				if(isButtonPressed(0)==1){
		  					status= MAN_YELLOW;
		  					check=0;
		  					checksaveyellow=0;
		  					setTimer(1, 487);
		  					setTimer(2, 1000);
		  					setTimer(3, 500);
		  				}
		  				if(isButtonPressed(1)==1){
		  					status=INCREASE_VALUE_LED_GREEN;
		  					checksavegreen=0;
		  					setTimer(1, 487);
		  					setTimer(2, 1000);
		  					setTimer(3, 500);
		  				}
		  			  break;
		  case INCREASE_VALUE_LED_YELLOW:
				if(checksaveyellow==0){
					Increase_Save_led7YELLOW_segment_run13();
					++checksaveyellow;
				}
				if(isTimerExpired(1)==1){
					led7_segment_run02();
					setTimer(1, 487);
				}
				if(isTimerExpired(2)==1){
					Save_led7YELLOW_segment_run13();
					setTimer(2, 1000);
				}
				if(isTimerExpired(3)==1){
					HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
					setTimer(3, 500);
				}
				if(isButtonPressed(0)==1){
					status= INIT;
				}
				if(isButtonPressed(1)==1){
					++checksaveyellow;
				    Increase_Save_led7YELLOW_segment_run13();
				}
				if(isButtonPressed(2)==1){
					status=SET_VALUE_LED_YELLOW;
					checksaveyellow=0;
				}
			  break;
		  case SET_VALUE_LED_YELLOW:
			          Turn_On_All_LED_YELLOW();
		  			  counteryellow13 = savecounteryellow13;
		  			//  c=counteryellow13;
		  				if(checksaveyellow==0){
		  					Save_led7YELLOW_segment_run13();
		  					checksaveyellow=1;
		  				}
		  				if(isTimerExpired(1)==1){
		  					led7_segment_run02();
		  					setTimer(1, 487);
		  				}
		  				if(isTimerExpired(2)==1){
		  					Save_led7YELLOW_segment_run13();
		  					setTimer(2, 1000);
		  				}
//		  				if(isTimerExpired(3)==1){
//		  					HAL_GPIO_TogglePin(GPIOA, LED_YELLOW1_Pin|LED_YELLOW2_Pin);
//		  					setTimer(3, 500);
//		  				}
		  				if(isButtonPressed(0)==1){
		  					status= INIT;
		  				}
		  				if(isButtonPressed(1)==1){
		  					status=INCREASE_VALUE_LED_YELLOW;
		  					checksaveyellow=0;
		  					setTimer(1, 487);
		  					setTimer(2, 1000);
		  					setTimer(3, 500);
		  				}
		  			  break;
		  default:
			  break;
      }
}
