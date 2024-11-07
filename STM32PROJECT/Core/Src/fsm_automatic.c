/*
 * fsm_automatic.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */

#include "fsm_automatic.h"
#include "global.h"
int k1=0;
int k2=0;
int counter=0;
int checkstatus=0;
int check=0;
int checksavered=0;
int checksavegreen=0;
int checksaveyellow=0;
//void fsm_automatic_run(){
//	switch(status){
//		case INIT:
//			 //  counter=0;
//               set_led();
//               set_led7_segement();
//               status=AUTO_RED1_GREEN2;
//               setTimer(0, b*1000);
//               setTimer(1, 500);
//               setTimer(2, 1000);
//               setTimer(8,1000);
//   			//led7_segment_run13();
//   			//LED_RED1_GREEN2();
//			break;
//		case AUTO_RED1_GREEN2:
//			if(isTimerExpired(8)==1){
//				LED_RED1_GREEN2();
//				//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			LED_RED1_GREEN2();
//			//setTimer(2, 1000);
//			//setTimer(8,1000);
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//					led7_segment_run13();
//					setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_YELLOW2;
//				setTimer(0, c*1000);
//				//counter=0;
//	             setTimer(1, 500);
//	             setTimer(2, 1000);
//	             setTimer(8,1000);
//	             //  setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//		//		 HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				status=MAN_RED;
//			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(4, 10000);
//			//	setTimer(8, 1000);
//				checkstatus=4;
//			}
//			break;
//		case AUTO_RED1_YELLOW2:
//			if(isTimerExpired(8)==1){
//			//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
//				LED_RED1_YELLOW2();
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_GREEN1_RED2;
//				setTimer(0, b*1000);
//				setTimer(8,1000);
//
//	           //    counter=0;
//			//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//	              setTimer(1, 500);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(5, 10000);
//				checkstatus=5;
//			}
//			break;
//		case AUTO_GREEN1_RED2:
//			if(isTimerExpired(8)==1){
//				LED_GREEN1_RED2();
//				//	HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_YELLOW1_RED2;
//				setTimer(0, c*1000);
//	             //  counter=0;
//	              setTimer(1, 500);
//	              setTimer(8,1000);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(6, 10000);
//				checkstatus=6;
//			}
//			break;
//		case AUTO_YELLOW1_RED2:
//			if(isTimerExpired(8)==1){
//				LED_YELLOW1_RED2();
//				setTimer(8,1000);
//			}
//			if(counter==0){
//			led7_segment_run13();
//			counter=1;
//			}
//			if(isTimerExpired(1)==1){
//				led7_segment_run02();
//				setTimer(1, 500);
//			}
//			if(isTimerExpired(2)==1){
//							led7_segment_run13();
//							setTimer(2, 1000);
//			}
//			if(isTimerExpired(0)==1){
//				status=AUTO_RED1_GREEN2;
//				setTimer(0, b*1000);
//				setTimer(8,1000);
////	              setTimer(1, 500);
////	               setTimer(2, 1000);
//			//	counter=0;
//	               setTimer(1, 500);
//	               setTimer(2, 1000);
//			}
//			if(isButtonPressed(0)==1){
//				status=MAN_RED;
//				setTimer(1, 500);
//				setTimer(2, 1000);
//				setTimer(3, 500);
//				setTimer(7, 10000);
//				checkstatus=7;
//			}
//			break;
//		default:
//			break;
//	}
//}
void fsm_automatic_run(){
	switch(status){
		case INIT:
			 //  counter=0;
               set_led();
               set_led7_segement();
       		if(counterred13==(countergreen13+counteryellow13)){
       			a=counterred13;
       			b=countergreen13;
       			c=counteryellow13;
       			idx_led13=0;
       			status=AUTO_RED1_GREEN2;
       			counter=0;
       			setTimer(0, b*1000);
       			setTimer(1, 487);
       			setTimer(2, 1000);
       		}
       		else{
       			counterred13=a;
       			countergreen13=b;
       			counteryellow13=c;
       			idx_led13=0;
       			status=AUTO_RED1_GREEN2;
       			counter=0;
                   setTimer(0, b*1000);
                   setTimer(1, 487);
                   setTimer(2, 1000);
       		}
//               status=AUTO_RED1_GREEN2;
//               setTimer(0, b*1000);
//               setTimer(1, 487);
//               setTimer(2, 1000);
			break;
		case AUTO_RED1_GREEN2:
			LED_RED1_GREEN2();
			if(counter==0){
			led7_segment_run13();
			counter=1;
			}
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 487);
			}
			if(isTimerExpired(2)==1){
					led7_segment_run13();
					setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_YELLOW2;
				//if(k1==0) {
					setTimer(0, c*1000);
				//	k1=1;
				//}
			//	else setTimer(0, (c+1)*1000);
	              // setTimer(1, 500);
	             //  setTimer(2, 1000);
				//counter=0;
			}
			if(isButtonPressed(0)==1){
		//		 HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				status=MAN_RED;
			//	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
				setTimer(1, 487);
				setTimer(2, 1000);
				setTimer(3, 500);
			//	setTimer(4, 10000);
			//	checkstatus=4;
				check=0;
				checksavered=0;
			}
			break;
		case AUTO_RED1_YELLOW2:
			LED_RED1_YELLOW2();
			if(counter==0){
			led7_segment_run13();
			counter=1;
			}
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 487);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_GREEN1_RED2;
				setTimer(0, (b+1)*1000);
			//	setTimer(0, (b)*1000);
	              // counter=0;
	              // setTimer(1, 500);
	             //  setTimer(2, 1000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				setTimer(1, 487);
				setTimer(2, 1000);
				setTimer(3, 500);
				setTimer(5, 10000);
				checkstatus=5;
				check=0;
			}
			break;
		case AUTO_GREEN1_RED2:
			LED_GREEN1_RED2();
			if(counter==0){
			led7_segment_run13();
			counter=1;
			}
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 487);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_YELLOW1_RED2;
//				if(k2==0) {
//					setTimer(0, c*1000);
//					k2=1;
//				}
				 setTimer(0, c*1000);
	              // setTimer(1, 500);
	             // setTimer(2, 1000);
	             //  counter=0;
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				setTimer(1, 487);
				setTimer(2, 1000);
				setTimer(3, 500);
				setTimer(6, 10000);
				checkstatus=6;
				check=0;
			}
			break;
//		case KEEP_AUTO_GREEN1_RED2:
//			LED_GREEN1_RED2();
//			if(isTimerExpired(0)==1){
//				setTimer(0, c*1000);
//			}
//			break;
		case AUTO_YELLOW1_RED2:
			LED_YELLOW1_RED2();
			if(counter==0){
			led7_segment_run13();
			counter=1;
			}
			if(isTimerExpired(1)==1){
				led7_segment_run02();
				setTimer(1, 487);
			}
			if(isTimerExpired(2)==1){
							led7_segment_run13();
							setTimer(2, 1000);
			}
			if(isTimerExpired(0)==1){
				status=AUTO_RED1_GREEN2;
				setTimer(0, (b+1)*1000);
			//	setTimer(0, (b)*1000);
	             //  setTimer(1, 500);
	             //  setTimer(2, 1000);
	            //   setTimer(1, 500);
	            //   setTimer(2, 1000);
			}
			if(isButtonPressed(0)==1){
				status=MAN_RED;
				setTimer(1, 487);
				setTimer(2, 1000);
				setTimer(3, 500);
				setTimer(7, 10000);
				checkstatus=7;
				check=0;
			}
			break;
		default:
			break;
	}
}
