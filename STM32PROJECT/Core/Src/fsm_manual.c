/*
 * fsm_manual.c
 *
 *  Created on: 29 thg 10, 2024
 *      Author: ADMIN
 */
#include "fsm_manual.h"
#include "global.h"

void fsm_manual_run(){
	switch(status){
	case MODE1:
		set_led();
		if(isButtonPressed(0)==1){
			status= MODE2;
		}
		status=AUTO_RED1_GREEN2;
		setTimer(0, 3000);
		break;
	case MODE2:
		break;
	case MODE3:
		break;
	case MODE4:
		break;
	}
}
