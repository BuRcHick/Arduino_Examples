#ifndef _CONTROLLER_API_H_
#define _CONTROLLER_API_H_
#include "../common.h"

typedef enum {
	up,
	down,
	left,
	right
}vector_t;

vector_t g_controller_vector;

void drv_controller_cb();

#endif //_CONTROLLER_API_H_
