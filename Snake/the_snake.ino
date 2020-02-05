#include<stdint.h>
#include<stdlib.h>
#include"matrix_driver.h"
#include"display_api.h"
#include"Thread.h"

#define CONTROLLER_X	A0
#define CONTROLLER_Y	A1

typedef enum {
	up,
	down,
	left,
	right
}vector_t;

static matrix_cells_t s_arrow_up[] = {	matrix_cell_4, 
					matrix_cell_5,
					matrix_cell_11,
					matrix_cell_12,
					matrix_cell_13,
					matrix_cell_14,
					matrix_cell_18, 
					matrix_cell_19,
					matrix_cell_20,
					matrix_cell_21,
					matrix_cell_22,
					matrix_cell_23,
					matrix_cell_25, 
					matrix_cell_26,
					matrix_cell_27,
					matrix_cell_28,
					matrix_cell_29,
					matrix_cell_30,
					matrix_cell_31, 
					matrix_cell_32,
					matrix_cell_36,
					matrix_cell_37,
					matrix_cell_44,
					matrix_cell_45,
					matrix_cell_52, 
					matrix_cell_53,
					matrix_cell_60,
					matrix_cell_61};

static matrix_cells_t s_arrow_down[] = {matrix_cell_4, 
					matrix_cell_5,
					matrix_cell_12,
					matrix_cell_13,
					matrix_cell_20,
					matrix_cell_21,
					matrix_cell_28,
					matrix_cell_29,
					matrix_cell_33,
					matrix_cell_34, 
					matrix_cell_35,
					matrix_cell_36,
					matrix_cell_37,
					matrix_cell_38,
					matrix_cell_39,
					matrix_cell_40, 
					matrix_cell_42,
					matrix_cell_43,
					matrix_cell_44, 
					matrix_cell_45,
					matrix_cell_46,
					matrix_cell_47,
					matrix_cell_51,
					matrix_cell_52,
					matrix_cell_53,
					matrix_cell_54,
					matrix_cell_60,
					matrix_cell_61};

static matrix_cells_t s_arrow_left[] = {matrix_cell_4, 
					matrix_cell_11,
					matrix_cell_12,
					matrix_cell_18, 
					matrix_cell_19,
					matrix_cell_20,
					matrix_cell_25, 
					matrix_cell_26,
					matrix_cell_27,
					matrix_cell_28,
					matrix_cell_29,
					matrix_cell_30,
					matrix_cell_31, 
					matrix_cell_32,
					matrix_cell_33,
					matrix_cell_34,
					matrix_cell_35,
					matrix_cell_36,
					matrix_cell_37, 
					matrix_cell_38,
					matrix_cell_39,
					matrix_cell_40, 
					matrix_cell_42,
					matrix_cell_43,
					matrix_cell_44,
					matrix_cell_51,
					matrix_cell_52,
					matrix_cell_60};

static matrix_cells_t s_arrow_right[] ={matrix_cell_5, 
					matrix_cell_13,
					matrix_cell_14,
					matrix_cell_21,
					matrix_cell_22,
					matrix_cell_23,
					matrix_cell_25, 
					matrix_cell_26,
					matrix_cell_27,
					matrix_cell_28,
					matrix_cell_29,
					matrix_cell_30,
					matrix_cell_31, 
					matrix_cell_32,
					matrix_cell_33,
					matrix_cell_34,
					matrix_cell_35,
					matrix_cell_36,
					matrix_cell_37, 
					matrix_cell_38,
					matrix_cell_39,
					matrix_cell_40,
					matrix_cell_45,
					matrix_cell_46,
					matrix_cell_47, 
					matrix_cell_53,
					matrix_cell_54,
					matrix_cell_61};

static Thread s_controller_thread = Thread();
static vector_t vector = up;
static void s_controller_th_callback();
void setup(){ 
	drv_matrix_init();
	Serial.begin(115200);
	s_controller_thread.enabled = true;
	s_controller_thread.setInterval(100);
	s_controller_thread.onRun(s_controller_th_callback);
}
static void s_controller_th_callback(){
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


void loop(){
	if(s_controller_thread.shouldRun()) s_controller_thread.run();
	if(vector == up) display_draw(s_arrow_up, sizeof(s_arrow_up)/sizeof(s_arrow_up[0]));
	if(vector == down) display_draw(s_arrow_down, sizeof(s_arrow_down)/sizeof(s_arrow_down[0]));
	if(vector == left) display_draw(s_arrow_left, sizeof(s_arrow_left)/sizeof(s_arrow_left[0]));
	if(vector == right) display_draw(s_arrow_right, sizeof(s_arrow_right)/sizeof(s_arrow_right[0]));
}
