#include<stdint.h>
#include<stdlib.h>
#include"matrix_driver.h"

void setup(){ 
	drv_matrix_init();
	Serial.begin(115200);
}

void loop(){
	drv_matrix_drawCell(matrix_cell_1);
	drv_matrix_releseCell(matrix_cell_1);
	drv_matrix_drawCell(matrix_cell_10);
        drv_matrix_releseCell(matrix_cell_10);
	drv_matrix_drawCell(matrix_cell_19);
        drv_matrix_releseCell(matrix_cell_19);
	drv_matrix_drawCell(matrix_cell_28);
        drv_matrix_releseCell(matrix_cell_28);
	drv_matrix_drawCell(matrix_cell_37);
        drv_matrix_releseCell(matrix_cell_37);
	drv_matrix_drawCell(matrix_cell_46);
        drv_matrix_releseCell(matrix_cell_46);
	drv_matrix_drawCell(matrix_cell_55);
        drv_matrix_releseCell(matrix_cell_55);
	drv_matrix_drawCell(matrix_cell_64);
        drv_matrix_releseCell(matrix_cell_64);
}
