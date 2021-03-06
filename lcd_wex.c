/*
 * lcd_wex.c
 *
 *  Author : Bio_Unit
 *  Version : 1.0
 *  About library :
 *  	This library made for OLED display on SSD1305 display controller IC and tested only on WEX012864GLPP3N10000.
 *
 */

#include "main.h"
#include "lcd_wex.h"

const uint8_t font_6x8[192][6] =
{
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			// space
		{0x00, 0x00, 0x9E, 0x9E, 0x00, 0x00},			// !
		{0x01, 0x01, 0x01, 0x01, 0x01, 0x00},			// _
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x10, 0x10, 0x10, 0x10, 0x00},			// -
		{0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00},			// .
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x7C, 0xA2, 0x92, 0x8A, 0x7C, 0x00},			// 0
		{0x10, 0x08, 0x04, 0xFE, 0x00, 0x00},			// 1
		{0xF2, 0x92, 0x92, 0x92, 0x9E, 0x00},			// 2
		{0x82, 0x92, 0x92, 0x92, 0xFE, 0x00},			// 3
		{0x1E, 0x10, 0x10, 0x10, 0xFE, 0x00},			// 4
		{0x9E, 0x92, 0x92, 0x92, 0xF2, 0x00},			// 5
		{0xFE, 0x92, 0x92, 0x92, 0xF2, 0x00},			// 6
		{0x02, 0xE2, 0x12, 0x0A, 0x06, 0x00},			// 7
		{0xFE, 0x92, 0x92, 0x92, 0xFE, 0x00},			// 8
		{0x9E, 0x92, 0x92, 0x92, 0xFE, 0x00},			// 9
		{0x00, 0x00, 0x44, 0x00, 0x00, 0x00},			// :
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0xFC, 0x22, 0x22, 0x22, 0xFC, 0x00},			// A
		{0xFE, 0x92, 0x92, 0x9E, 0xF0, 0x00},			// B
		{0xFE, 0x82, 0x82, 0x82, 0xC6, 0x00},			// C
		{0xFE, 0x82, 0x82, 0x44, 0x38, 0x00},			// D
		{0xFE, 0x92, 0x92, 0x92, 0x82, 0x00},			// E
		{0xFE, 0x12, 0x12, 0x12, 0x02, 0x00},			// F
		{0xFE, 0x82, 0xB2, 0x92, 0xF2, 0x00},			// G
		{0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00},			// H
		{0x00, 0x82, 0xFE, 0x82, 0x82, 0x00},			// I
		{0xC0, 0x80, 0x82, 0x82, 0x7E, 0x00},			// J
		{0xFE, 0x10, 0x28, 0x44, 0x82, 0x00},			// K
		{0xFE, 0x80, 0x80, 0x80, 0xC0, 0x00},			// L
		{0xFE, 0x0C, 0x18, 0x0C, 0xFE, 0x00},			// M
		{0xFE, 0x08, 0x10, 0x20, 0xFE, 0x00},			// N
		{0xFE, 0x82, 0x82, 0x82, 0xFE, 0x00},			// O
		{0xFE, 0x12, 0x12, 0x12, 0x1E, 0x00},			// P
		{0xFE, 0x82, 0xA2, 0x42, 0xBE, 0x00},			// Q
		{0xFE, 0x12, 0x32, 0x52, 0x9E, 0x00},			// R
		{0xDE, 0x92, 0x92, 0x92, 0xF6, 0x00},			// S
		{0x02, 0x02, 0xFE, 0x02, 0x02, 0x00},			// T
		{0x7E, 0x80, 0x80, 0x80, 0x7E, 0x00},			// U
		{0x3E, 0x40, 0x80, 0x40, 0x3E, 0x00},			// V
		{0xFE, 0x60, 0x30, 0x60, 0xFE, 0x00},			// W
		{0x82, 0x44, 0x38, 0x44, 0x82, 0x00},			// X
		{0x0E, 0x10, 0xE0, 0x10, 0x0E, 0x00},			// Y
		{0xC2, 0xA2, 0x92, 0x8A, 0x86, 0x00},			// Z
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},			//
		{0xFC, 0x22, 0x22, 0x22, 0xFC, 0x00},			// ?
		{0xFE, 0x92, 0x92, 0x92, 0x62, 0x00},			// ?
		{0xFE, 0x92, 0x92, 0x9E, 0xF0, 0x00},			// ?
		{0xFE, 0x02, 0x02, 0x02, 0x06, 0x00},			// ?
		{0xE0, 0x1E, 0x12, 0x1E, 0xE0, 0x00},			// ?
		{0xFE, 0x92, 0x92, 0x92, 0x82, 0x00},			// E
		{0xFE, 0x10, 0xFE, 0x10, 0xFE, 0x00},			// ?
		{0xF0, 0x9E, 0x92, 0x92, 0xC6, 0x00},			// ?
		{0xFE, 0x40, 0x20, 0x10, 0xFE, 0x00},			// ?
		{0xFE, 0x40, 0x22, 0x10, 0xFE, 0x00},			// ?
		{0xFE, 0x10, 0x28, 0x44, 0x82, 0x00},			// ?
		{0x80, 0xFE, 0x02, 0x02, 0xFE, 0x00},			// ?
		{0xFE, 0x0C, 0x18, 0x0C, 0xFE, 0x00},			// ?
		{0xFE, 0x10, 0x10, 0x10, 0xFE, 0x00},			// ?
		{0xFE, 0x82, 0x82, 0x82, 0xFE, 0x00},			// ?
		{0xFE, 0x02, 0x02, 0x02, 0xFE, 0x00},			// ?
		{0xFE, 0x12, 0x12, 0x12, 0x1E, 0x00},			// ?
		{0xFE, 0x82, 0x82, 0x82, 0xC6, 0x00},			// ?
		{0x02, 0x02, 0xFE, 0x02, 0x02, 0x00},			// ?
		{0x9E, 0x90, 0x90, 0x90, 0xFE, 0x00},			// ?
		{0x3E, 0x22, 0xFE, 0x22, 0x3E, 0x00},			// ?
		{0x82, 0x44, 0x38, 0x44, 0x82, 0x00},			// ?
		{0x7E, 0x40, 0x40, 0x7E, 0xC0, 0x00},			// ?
		{0x1E, 0x10, 0x10, 0x10, 0xFE, 0x00},			// ?
		{0xFE, 0x80, 0xFC, 0x80, 0xFE, 0x00},			// ?
		{0x7E, 0x40, 0x7C, 0x40, 0xFE, 0x00},			// ?
		{0x02, 0xFE, 0x90, 0x90, 0xF0, 0x00},			// ?
		{0xFE, 0x90, 0xF0, 0x00, 0xFE, 0x00},			// ?
		{0x00, 0xFE, 0x90, 0x90, 0xF0, 0x00},			// ?
		{0xC6, 0x92, 0x92, 0x92, 0xFE, 0x00},			// ?
		{0xFE, 0x10, 0xFE, 0x82, 0xFE, 0x00},			// ?
		{0x9E, 0x52, 0x32, 0x12, 0xFE, 0x00},			// ?
};

/*
 *
 */
void lcd_wex_write_byte(uint8_t byte, uint8_t type)
{
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 0);			// CS pin asserted
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, type);		// Command or data transfer

	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (byte & 0b00000001) );	// converting input data to parallel 8080 data bus
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (byte & 0b00000010) );	// -
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (byte & 0b00000100) );	// -
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (byte & 0b00001000) );	// -
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (byte & 0b00010000) );	// -
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (byte & 0b00100000) ); 	// -
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (byte & 0b01000000) );	// -
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (byte & 0b10000000) );	// -

	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);		// initiate write operation
	//for(uint8_t b=0; b<200; b++) {}							// Very small delay
	HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 1);		// end up write operation
	//for(uint8_t b=0; b<200; b++) {}							// Very small delay
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 1);		// CS pin deasserted
}

/*
 *
 */
void lcd_wex_clear(void)
{
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 0);			// CS pin asserted
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, 1);		// Command or data transfer

	HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, 0);	// converting input data to parallel 8080 data bus
	HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, 0);	// -
	HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, 0);	// -
	HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, 0);	// -
	HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, 0);	// -
	HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, 0); // -
	HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, 0);	// -
	HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, 0);	// -

	for(uint16_t a=0; a<1054; a++)
	{
		HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);		// initiate write operation
		HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 1);		// end up write operation
	}
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 1);		// CS pin deasserted
}

void lcd_wex_write_char(uint8_t symbol)
{
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 0);			// CS pin asserted
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, 1);		// Command or data transfer

	for(uint8_t size=0; size<6; size++)
	{
		HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (font_6x8[symbol-32][size] & 0b00000001) );	// converting input data to parallel 8080 data bus
		HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (font_6x8[symbol-32][size] & 0b00000010) );	// -
		HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (font_6x8[symbol-32][size] & 0b00000100) );	// -
		HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (font_6x8[symbol-32][size] & 0b00001000) );	// -
		HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (font_6x8[symbol-32][size] & 0b00010000) );	// -
		HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (font_6x8[symbol-32][size] & 0b00100000) ); 	// -
		HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (font_6x8[symbol-32][size] & 0b01000000) );	// -
		HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (font_6x8[symbol-32][size] & 0b10000000) );	// -

		HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);		// initiate write operation
		HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 1);		// end up write operation
	}
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 1);		// CS pin deasserted
}

void lcd_wex_write_string(unsigned char *string, uint8_t length)
{
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 0);			// CS pin asserted
	HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, 1);		// Command or data transfer

	for(uint8_t symbol=0; symbol<length; symbol++)
	{
		for(uint8_t size=0; size<6; size++)
		{
			HAL_GPIO_WritePin(LCD_D0_GPIO_Port, LCD_D0_Pin, (font_6x8[string[symbol]-32][size] & 0b00000001) );	// converting input data to parallel 8080 data bus
			HAL_GPIO_WritePin(LCD_D1_GPIO_Port, LCD_D1_Pin, (font_6x8[string[symbol]-32][size] & 0b00000010) );	// -
			HAL_GPIO_WritePin(LCD_D2_GPIO_Port, LCD_D2_Pin, (font_6x8[string[symbol]-32][size] & 0b00000100) );	// -
			HAL_GPIO_WritePin(LCD_D3_GPIO_Port, LCD_D3_Pin, (font_6x8[string[symbol]-32][size] & 0b00001000) );	// -
			HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (font_6x8[string[symbol]-32][size] & 0b00010000) );	// -
			HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (font_6x8[string[symbol]-32][size] & 0b00100000) ); 	// -
			HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (font_6x8[string[symbol]-32][size] & 0b01000000) );	// -
			HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (font_6x8[string[symbol]-32][size] & 0b10000000) );	// -

			HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 0);		// initiate write operation
			HAL_GPIO_WritePin(LCD_RW_GPIO_Port, LCD_RW_Pin, 1);		// end up write operation
		}
	}
	HAL_GPIO_WritePin(LCD_CS_GPIO_Port, LCD_CS_Pin, 1);		// CS pin deasserted
}

/*
 *
 */
void lcd_wex_wake(void)
{
	HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 0);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, 1);
	HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 1);
	lcd_wex_write_byte(0xAF, 0);							// Command to switch on display
	HAL_Delay(100);
	lcd_wex_write_byte(0x20, 0);							// Enter to address mode register
	lcd_wex_write_byte(0x00, 0);							// Set horizontal mode addressing
	//lcd_wex_write_byte(0xC8, 0);							// Set reverse scan direction
	lcd_wex_write_byte(0xA1, 0);							// Set SEGMENT remap
	//lcd_wex_write_byte(0xDA, 0);							// Enter hardware COM pin register
	//lcd_wex_write_byte(0x02, 0);							// Set left/right ADDRESS remap
	lcd_wex_write_byte(0xFF, 1);							// Put a stick to the beginning
	lcd_wex_clear();										// clear an LCD
	//lcd_wex_write_command(0xA5);							// All LEDs are ON
	//HAL_Delay(1000);
}

/*
 *
 */
void lcd_wex_sleep(void)
{
	lcd_wex_write_byte(0xAE, 0);
	HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 0);
	//HAL_GPIO_WritePin(LCD_RST_GPIO_Port, LCD_RST_Pin, 0);
}
