/*
 * button.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "button.h"

#define MAX_COUNTER 10

int Button_flag[MAX_COUNTER];
int Button_counter[MAX_COUNTER];

int isButtonPressed(int index){
	if(Button_flag[index]==1){
		Button_flag[index]=0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	Button_flag[index]=1;
}

void getKeyInput(){

}
