/*
 * led7_segment.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */

#include "led7_segment.h"
int idx=0;
int idx_led02=0;
int idx_led13=0;
int counterred02=5;
int counteryellow02=2;
int countergreen02=3;
int counterred13=5;
int counteryellow13=2;
int countergreen13=3;
int savecounterred13,savecountergreen13,savecounteryellow13 =0;
int checkcounterred,checkcountergreen,checkcounteryellow=0;
int a=5;
int b=3;
int c=2;
void set_led7_segement(){
	HAL_GPIO_WritePin(GPIOB, SEG0X_Pin|SEG1X_Pin|SEG2X_Pin|EN3_Pin
		                          |SEG3X_Pin|SEG4X_Pin|SEG5X_Pin|SEG6X_Pin
		                          |EN0_Pin|EN1_Pin|EN2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, SEG0Y_Pin|SEG1Y_Pin|SEG2Y_Pin|SEG3Y_Pin|SEG4Y_Pin|SEG5Y_Pin|SEG6Y_Pin, GPIO_PIN_SET);
}
void display7SEGX(int num) {
      const uint8_t segmentMap[10] = {
          0b11111100,
          0b01100000,
          0b11011010,
          0b11110010,
          0b01100110,
          0b10110110,
          0b10111110,
          0b11100000,
          0b11111110,
          0b11110110
      };
      HAL_GPIO_WritePin(SEG0X_GPIO_Port, SEG0X_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG1X_GPIO_Port, SEG1X_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG2X_GPIO_Port, SEG2X_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG3X_GPIO_Port, SEG3X_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG4X_GPIO_Port, SEG4X_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG5X_GPIO_Port, SEG5X_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG6X_GPIO_Port, SEG6X_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }
void display7SEGY(int num) {
      const uint8_t segmentMap[10] = {
          0b11111100,
          0b01100000,
          0b11011010,
          0b11110010,
          0b01100110,
          0b10110110,
          0b10111110,
          0b11100000,
          0b11111110,
          0b11110110
      };
      HAL_GPIO_WritePin(SEG0Y_GPIO_Port, SEG0Y_Pin, (segmentMap[num] & 0b10000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG1Y_GPIO_Port, SEG1Y_Pin, (segmentMap[num] & 0b01000000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG2Y_GPIO_Port, SEG2Y_Pin, (segmentMap[num] & 0b00100000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG3Y_GPIO_Port, SEG3Y_Pin, (segmentMap[num] & 0b00010000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG4Y_GPIO_Port, SEG4Y_Pin, (segmentMap[num] & 0b00001000) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG5Y_GPIO_Port, SEG5Y_Pin, (segmentMap[num] & 0b00000100) ? GPIO_PIN_RESET : GPIO_PIN_SET);
      HAL_GPIO_WritePin(SEG6Y_GPIO_Port, SEG6Y_Pin, (segmentMap[num] & 0b00000010) ? GPIO_PIN_RESET : GPIO_PIN_SET);
  }
void led7_segment_run02(){

//	if(idx_led02>=10) idx_led02=0;
//	idx_led02++;
//	if(idx_led02<=3){
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//		display7SEGX(counterred02--);
//		display7SEGY(countergreen02--);
//	}
//	if(idx_led02>3&&idx_led02<=5){
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//		display7SEGX(counterred02--);
//		display7SEGY(counteryellow02--);
//			if(idx_led02>=5){
//				counterred02=5;
//				counteryellow02=2;
//				countergreen02=3;
//			}
//	}
//	if(idx_led02>5&&idx_led02<=8){
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//		display7SEGY(counterred02--);
//		display7SEGX(countergreen02--);
//	}
//	if(idx_led02>8&&idx_led02<=10){
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
//		display7SEGY(counterred02--);
//		display7SEGX(counteryellow02--);
//			if(idx_led02>=10){
//				counterred02=5;
//				counteryellow02=2;
//				countergreen02=3;
//			}
//	}
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			display7SEGX(0);
			display7SEGY(0);
}
void led7_segment_run13(){
	if(idx_led13>=(2*b+2*c+2)) idx_led13=0;
	idx_led13++;
	if(idx_led13<=b+1){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGX(counterred13--);
		display7SEGY(countergreen13--);
	}
	if(idx_led13>b+1&&idx_led13<=(b+c+1)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGX(counterred13--);
		display7SEGY(--counteryellow13);
			if(idx_led13>=(b+c+1)){
				counterred13=a;
				counteryellow13=c;
				countergreen13=b;
			}
	}
	if(idx_led13>(b+c+1)&&idx_led13<=(2*b+c+2)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGY(counterred13--);
		display7SEGX(countergreen13--);
	}
	if(idx_led13>(2*b+c+2)&&idx_led13<=(2*b+2*c+2)){
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		display7SEGY(counterred13--);
		display7SEGX(--counteryellow13);
			if(idx_led13>=(2*b+2*c+2)){
				counterred13=a;
				counteryellow13=c;
				countergreen13=b;
			}
	}
}
//void led7_segment_run13(int d){
//	switch(d){
//	case 0:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counterred13--);
//		display7SEGY(countergreen13--);
//	  break;
//	case 1:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counterred13--);
//		display7SEGY(counteryellow13--);
//			if(counterred13==0){
//				counterred13=a;
//				counteryellow13=c;
//				countergreen13=b;
//			}
//			break;
//	case 2:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(countergreen13--);
//		display7SEGY(counterred13--);
//	//	display7SEGX(countergreen13--);
//
//	break;
//	case 3:
//		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
//		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
//		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
//		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
//		display7SEGX(counteryellow13--);
//		display7SEGY(counterred13--);
//		//display7SEGX(counteryellow13--);
//			if(counterred13==0){
//				counterred13=a;
//				counteryellow13=c;
//				countergreen13=b;
//
//			}
//			break;
//	default:
//		break;
//	}
//}
void Save_led7_segment_run02(){
}
void Save_led7RED_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcounterred==0){
		savecounterred13=++counterred13;
		checkcounterred=1;
	}
	display7SEGX(savecounterred13++);
	display7SEGY(2);
	--savecounterred13;
}
void Increase_Save_led7RED_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	display7SEGX(++savecounterred13);
	display7SEGY(2);
}
void Save_led7GREEN_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcountergreen==0){
		savecountergreen13=++countergreen13;
		checkcountergreen=1;
	}
	display7SEGX(savecountergreen13++);
	display7SEGY(3);
	--savecountergreen13;
}
void Increase_Save_led7GREEN_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	display7SEGX(++savecountergreen13);
	display7SEGY(3);
}
void Save_led7YELLOW_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	if(checkcounteryellow==0){
		savecounteryellow13=counteryellow13;
		checkcounteryellow=1;
	}
	display7SEGX(savecounteryellow13);
	display7SEGY(4);
	//--savecounteryellow13;
}
void Increase_Save_led7YELLOW_segment_run13(){
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	display7SEGX(++savecounteryellow13);
	display7SEGY(4);
}
