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
#include "stdint.h"
#include "led.h"

void init_leds()
{
	// Timer4 initialized in backlight.c
	// Init compare register at 0 for C7 and B6
	OCR4A = 0x0;
	OCR4B = 0x0;

	// Configure port C7 (OC4A), B6 (OC4B) and D6 as output
	DDRC |= (1<<7);
	DDRB |= (1<<6);
	DDRD |= (1<<6);
}

void led_set(uint8_t usb_led)
{
	if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
		PORTD |= (1<<6);
	} else {
		PORTD &= ~(1<<6);
	}

	if (usb_led & (1<<USB_LED_NUM_LOCK)) {
		OCR4A = FRONTLED_LEVEL;
	} else {
		OCR4A = 0x0;
	}
}


void hook_layer_change(uint32_t layer_state)
{
	// Switch on led when layer 1 is active
	if(layer_state & (1UL<<1)) {
		OCR4B = FRONTLED_LEVEL;
	} else {
		OCR4B = 0x0;
	}
}

// vim: ts=4:sw=4:ai
