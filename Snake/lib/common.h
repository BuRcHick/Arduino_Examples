#ifndef _COMMON_H_
#define _COMMON_H_

typedef enum {
	DRV_OK,
	DRV_ERR,
}drv_err_t;

const char* err_2_stirng(drv_err_t);

#endif //_COMMON_H_
