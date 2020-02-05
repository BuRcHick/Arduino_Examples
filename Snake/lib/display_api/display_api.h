#ifndef _DISPLAY_API_H_
#define _DISPLAY_API_H_
#include "stdint.h"
#include "../common.h"
#include "../matrix_driver/matrix_driver.h"

drv_err_t display_draw(const matrix_cells_t*, const uint8_t);
drv_err_t display_erase();

#endif //_DISPLAY_API_H_
