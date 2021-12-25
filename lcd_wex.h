/*
 * lcd_wex.h
 *
 *  Created on: Aug 25, 2021
 *      Author: am
 */

#ifndef SRC_LCD_WEX_H_
#define SRC_LCD_WEX_H_

void lcd_wex_wake(void);
void lcd_wex_sleep(void);
void lcd_wex_write_byte(uint8_t byte, uint8_t type);
void lcd_wex_write_char(uint8_t symbol);
void lcd_wex_write_string(unsigned char *string, uint8_t length);

#endif /* SRC_LCD_WEX_H_ */
