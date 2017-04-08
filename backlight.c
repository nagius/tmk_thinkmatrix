/*************************************************************************
 *
 * This file is part of tmk_thinkmatrix keyboard firmware.
 * Copyleft 2016 Nicolas Agius <nicolas.agius@lps-it.fr>
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

#include <avr/io.h>
#include "backlight.h"


void init_backlight()
{
	// Set 8-bit fast PWM mode with no prescaling on Timer4
	// for output OC4A (C7), OC4B (B6) and OC4D (D7)
	TCCR4A = (1 << PWM4A)|(1 << PWM4B)|(1 << COM4A1)|(1 << COM4B1);
	TCCR4B = (1 << CS40);
	TCCR4C = (1 << PWM4D)|(1 << COM4D1)|(1 << COM4A1S)|(1 << COM4B1S);
	TCCR4D = (0 << WGM41)|(0 << WGM40);

	// Init compare register at 0 for D7
	OCR4D = 0x0;

	//Initialize port D7 (OC4D) as output
	DDRD|=(1 << 7);
}


void backlight_set(uint8_t level)
{
	// Set Timer4 compare register to the requested backlight level
	OCR4D=(uint8_t)((BACKLIGHT_MAX/BACKLIGHT_LEVELS)*level);
}

// vim: ts=4:sw=4:ai
