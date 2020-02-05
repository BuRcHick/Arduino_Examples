#include "display_api.h"
#include "Arduino.h"
#include "assert.h"
#define CHECK_ERR(e) if((e)) return DRV_ERR;

drv_err_t display_draw(const matrix_cells_t* figure, const uint8_t size){
	assert(figure);
	CHECK_ERR(size < 0 || size >= matrix_size);
	for(uint8_t i = 0; i < size; ++i){
		drv_matrix_drawCell(figure[i]);
		drv_matrix_releseCell(figure[i]);
	}	
	return DRV_OK;
}
