/*************************************************************************
 *
 * This file is part of tmk_thinkmatrix keyboard firmware.
 * Copyleft 2016 Nicolas Agius <nicolas.agius@lps-it.fr>
 * Original code Copyright 2012 Jun Wako <wakojun@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * ***********************************************************************/


#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "backlight.h"


static uint8_t debouncing = DEBOUNCE;

static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];
static matrix_row_t read_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);


inline
uint8_t matrix_rows(void)
{
	return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
	return MATRIX_COLS;
}


/* Column pin configuration
 * col: 0	1	2	3	4	5	6 
 * pin: B2	B0	B1	E6	B3	B7	D0
 */
static void  init_cols(void)
{
	// Input with pull-up(DDR:0, PORT:1)
	DDRB  &= ~( 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7 );
	PORTB |=  ( 1<<0 | 1<<1 | 1<<2 | 1<<3 | 1<<7 );

	DDRE  &= ~( 1<<6 );
	PORTE |=  ( 1<<6 );

	DDRD  &= ~( 1<<0 );
	PORTD |=  ( 1<<0 );
}


static matrix_row_t read_cols(void)
{
	return (PINB&(1<<2) ? 0 : (1<<0)) |
		   (PINB&(1<<0) ? 0 : (1<<1)) |
		   (PINB&(1<<1) ? 0 : (1<<2)) |
		   (PINE&(1<<6) ? 0 : (1<<3)) |
		   (PINB&(1<<3) ? 0 : (1<<4)) |
		   (PINB&(1<<7) ? 0 : (1<<5)) |
		   (PIND&(1<<0) ? 0 : (1<<6));
}

/* Row pin configuration
 * row: 0	1	2	3	4	5	6	7	8	9	10	11	12	13
 * pin: F0	F1	F4	B4	F5	D3	D2	C7	F7	B6	B5	D5	D4	C6
 */
static void unselect_rows(void)
{
	// Hi-Z(DDR:0, PORT:0) to unselect
	DDRF  &= ~( 1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<7 );
	PORTF &= ~( 1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<7 );
	DDRD  &= ~( 1<<2 | 1<<3 | 1<<4 | 1<<5 );
	PORTD &= ~( 1<<2 | 1<<3 | 1<<4 | 1<<5 );
	DDRC  &= ~( 1<<6 | 1<<7 );
	PORTC &= ~( 1<<6 | 1<<7 );
	DDRB  &= ~( 1<<4 | 1<< 5 | 1<<6 );
	PORTB &= ~( 1<<4 | 1<< 5 | 1<<6 );
}

static void select_row(uint8_t row)
{
	// Output low(DDR:1, PORT:0) to select
	switch (row) {
		case 0:
			DDRF  |= (1<<0);
			PORTF &= ~(1<<0);
			break;
		case 1:
			DDRF  |= (1<<1);
			PORTF &= ~(1<<1);
			break;
		case 2:
			DDRF  |= (1<<4);
			PORTF &= ~(1<<4);
			break;
		case 3:
			DDRF  |= (1<<5);
			PORTF &= ~(1<<5);
			break;
		case 4:
			DDRD  |= (1<<3);
			PORTD &= ~(1<<3);
			break;
		case 5:
			DDRD  |= (1<<2);
			PORTD &= ~(1<<2);
			break;
		case 6:
			DDRC  |= (1<<7);
			PORTC &= ~(1<<7);
			break;
		case 7:
			DDRF  |= (1<<7);
			PORTF &= ~(1<<7);
			break;
		case 8:
			DDRB  |= (1<<6);
			PORTB &= ~(1<<6);
			break;
		case 9:
			DDRB  |= (1<<5);
			PORTB &= ~(1<<5);
			break;
		case 10:
			DDRB  |= (1<<4);
			PORTB &= ~(1<<4);
			break;
		case 11:
			DDRD  |= (1<<5);
			PORTD &= ~(1<<5);
			break;
		case 12:
			DDRD  |= (1<<4);
			PORTD &= ~(1<<4);
			break;
		case 13:
			DDRC  |= (1<<6);
			PORTC &= ~(1<<6);
			break;
	}
}

void matrix_init(void)
{
	// initialize rows
	unselect_rows();

	init_cols();
//	init_leds();
	init_backlight();

	// initialize matrix state: all keys off
	for (uint8_t i=0; i < MATRIX_ROWS; i++) {
		matrix[i] = 0;
		matrix_debouncing[i] = 0;
	}
}

uint8_t matrix_scan(void)
{
	for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
		select_row(i);
		_delay_us(30);	// without this wait read unstable value.
		matrix_row_t cols = read_cols();
		if (matrix_debouncing[i] != cols) {
			matrix_debouncing[i] = cols;
			if (debouncing) {
				debug("bounce!: "); debug_hex(debouncing); debug("\n");
			}
			debouncing = DEBOUNCE;
		}
		unselect_rows();
	}

	if (debouncing) {
		if (--debouncing) {
			_delay_ms(1);
		} else {
			for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
				matrix[i] = matrix_debouncing[i];
			}
		}
	}

	return 1;
}

bool matrix_is_modified(void)
{
	if (debouncing) return false;
	return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
	return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
	return matrix[row];
}

void matrix_print(void)
{
	print("\nr/c 01234567\n");
	for (uint8_t row = 0; row < matrix_rows(); row++) {
		phex(row); print(": ");
		pbin_reverse(matrix_get_row(row));
		print("\n");
	}
}

// vim: ts=4:sw=4:ai
