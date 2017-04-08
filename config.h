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

#ifndef CONFIG_H
#define CONFIG_H


#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xBB00
#define MANUFACTURER    NicolasAgius
#define DEVICE_VER      0x0101
#define PRODUCT         ThinkMatrix Keyboard

#define DESCRIPTION     Custom mechanical Matrix keyboard

/* matrix size */
#define MATRIX_ROWS 14
#define MATRIX_COLS 7

/* Set 0 if need no debouncing */
#define DEBOUNCE    5

/* number of backlight levels */
#define BACKLIGHT_LEVELS 10

/* PWM intensity for front leds */
#define FRONTLED_LEVEL 20

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LALT) )\
)

#endif

// vim: ts=4:sw=4:ai
