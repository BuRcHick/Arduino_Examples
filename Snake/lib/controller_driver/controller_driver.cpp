#include"Arduino.h"
#include"controller_driver_api.h"
#include"Thread.h"
#define CONTROLLER_X	A0
#define CONTROLLER_Y	A1
void drv_controller_cb(){
	int curr_vall = analogRead(CONTROLLER_X);
	curr_vall = map(curr_vall, 0, 1023, 0, 255);
	curr_vall = constrain(curr_vall, 0, 255);
	if(curr_vall < 120 && vector != left){
		vector = left;
		return;
	}
	if(curr_vall > 130 && vector != right){
		vector = right;
		return;
	}
	curr_vall = analogRead(CONTROLLER_Y);
	curr_vall = map(curr_vall, 0, 1023, 0, 255);
	curr_vall = constrain(curr_vall, 0, 255);
	if(curr_vall < 120 && vector != up){
		vector = up;
		return;
	}
	if(curr_vall > 130 && vector != down){
		vector = down;
		return;
	}

}	
