#include "matrix_driver.h"
#include "Arduino.h"
#include <assert.h>
//Matrix 8*8 pins to arduino UNO board pins
#define MATRIX_1_PIN	10
#define MATRIX_2_PIN	11
#define MATRIX_3_PIN	2
#define	MATRIX_4_PIN	3
#define MATRIX_5_PIN	12
#define MATRIX_6_PIN	4
#define MATRIX_7_PIN	13
#define MATRIX_8_PIN	19
#define MATRIX_9_PIN	18
#define MATRIX_10_PIN	5
#define MATRIX_11_PIN	6
#define MATRIX_12_PIN	17
#define MATRIX_13_PIN	7
#define MATRIX_14_PIN	16
#define MATRIX_15_PIN	8
#define MATRIX_16_PIN	9

//Hight State pins
#define MATRIX_ROW_1	MATRIX_9_PIN
#define MATRIX_ROW_2	MATRIX_14_PIN
#define MATRIX_ROW_3	MATRIX_8_PIN
#define MATRIX_ROW_4	MATRIX_12_PIN
#define MATRIX_ROW_5	MATRIX_1_PIN
#define MATRIX_ROW_6	MATRIX_7_PIN
#define MATRIX_ROW_7	MATRIX_2_PIN
#define MATRIX_ROW_8	MATRIX_5_PIN

//Low State pins
#define MATRIX_COL_1	MATRIX_13_PIN
#define MATRIX_COL_2	MATRIX_3_PIN
#define MATRIX_COL_3	MATRIX_4_PIN
#define MATRIX_COL_4	MATRIX_10_PIN
#define MATRIX_COL_5	MATRIX_6_PIN
#define MATRIX_COL_6	MATRIX_11_PIN
#define MATRIX_COL_7	MATRIX_15_PIN
#define MATRIX_COL_8	MATRIX_16_PIN

#define CELL_STRUCT_ITEM(h, l) {.lowStatePin = l, .hightStatePin = h}

#define CHECK_ERR(e) if((e)) return DRV_ERR;

typedef struct {
	uint32_t lowStatePin;
	uint32_t hightStatePin;
}cell_t;

static cell_t s_matrix[] = {
		CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_1),
		CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_2),
		CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_1, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_2, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_3, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_4, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_5, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_6, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_7, MATRIX_COL_8),
		CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_1),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_2),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_3),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_4),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_5),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_6),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_7),
                CELL_STRUCT_ITEM(MATRIX_ROW_8, MATRIX_COL_8)};

const drv_err_t drv_matrix_isEmptyCell(const matrix_cells_t cell, bool* is_empty){
	CHECK_ERR(cell >= matrix_size);
	assert(is_empty);
	*is_empty = (bool)(!digitalRead(s_matrix[cell].hightStatePin) | digitalRead(s_matrix[cell].lowStatePin));
	return DRV_OK;
}

const drv_err_t drv_matrix_drawCell(const matrix_cells_t cell){
	CHECK_ERR(cell >= matrix_size);
	bool is_empty = false;
	CHECK_ERR(drv_matrix_isEmptyCell(cell, &is_empty) != DRV_OK);
	CHECK_ERR(!is_empty);
	Serial.println(s_matrix[cell].lowStatePin);
	Serial.println(s_matrix[cell].hightStatePin);;
	digitalWrite(s_matrix[cell].lowStatePin, LOW);
	digitalWrite(s_matrix[cell].hightStatePin, HIGH);
	return DRV_OK;
}

const drv_err_t drv_matrix_releseCell(const matrix_cells_t cell){
	CHECK_ERR(cell >= matrix_size); 
	digitalWrite(s_matrix[cell].lowStatePin, HIGH);
	digitalWrite(s_matrix[cell].hightStatePin, LOW);
	return DRV_OK;
};

const drv_err_t drv_matrix_init(){
	for(uint8_t i = 0; i < matrix_size; ++i){
		pinMode(s_matrix[i].hightStatePin, OUTPUT);
		pinMode(s_matrix[i].lowStatePin, OUTPUT);
	}
	for(uint8_t i = 0; i < matrix_size; ++i){
		digitalWrite(s_matrix[i].hightStatePin, LOW);
		digitalWrite(s_matrix[i].lowStatePin, HIGH);
	}
	return DRV_OK;
}
