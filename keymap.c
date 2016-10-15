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

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "keymap.h"


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,---------------------------------------------------------------------.
     * | Esc|  F1|  F2|  F3|  F4|  F5| DEL|  F6|  F7|  F8|  F9| F10| F11| F12|
     * |---------------------------------------------------------------------|
     * |  ` |   1|   2|   3|   4|   5|    |   6|   7|   8|   9|   0|  - |  = |
     * |-----------------------------|Back|----------------------------------|
     * | Tab|  Q |  W |  E |  R |  T |    |  Y |  U |  I |  O |  P |  [ |  ] |
     * |---------------------------------------------------------------------|
     * |    |  A |  S |  D |  F |  G |    |  H |  J |  K |  L |  ; |  ' |    |
     * |Shft|------------------------|Ent |-----------------------------|Shft|
     * |    |  Z |  X |  C |  V |  B |    |  N |  M |  , |  . |  / |  \ |    |
     * |---------------------------------------------------------------------|
     * |    | App|PgUp| FnL|Space/Fn |    |  Space  | Gui|Home| Up | End|    |
     * |Ctrl|------------------------|Shft|-----------------------------|Ctrl|
     * |    | Gui|PgDn| Alt|         |    |         | Alt|Left|Down|Rght|    |
     * `-------------------'         `----'         `------------------------'
	 *
	 * Note that this matrix has been flipped as the diode are the other
	 * way around.
     */


    KEYMAP( F12, EQL, RBRC, RSFT,     RCTL, \
            F11, MINS, LBRC, QUOT, BSLS, END, RGHT, \
            F10, 0, P, SCLN, SLSH, UP, DOWN, \
            F9, 9, O, L, DOT, HOME, LEFT, \
            F8, 8, I, K, COMM, RGUI, RALT, \
            F7, 7, U, J, M, \
            F6, 6, Y, H, N, SPC, \
            DEL, BSPC, ENT, LSFT, \
            F5, 5, T, G, B, \
            F4, 4, R, F, V, FN0, \
            F3, 3, E, D, C, FN1, LALT, \
            F2, 2, W, S, X, PGUP, PGDN, \
            F1, 1, Q, A, Z, APP, LGUI, \
            ESC, GRV, TAB, LSFT, LCTL ),

    /* Layer 1: Function Layer
     * ,---------------------------------------------------------------------.
     * |    |    |    |Nclk|    |    | Ins|Ejct| Pwr|Slep|Wake|PSCR|SLCK|Paus|
     * |---------------------------------------------------------------------|
     * |    |    |    |    |    |    | Vol|    |    |    |    |    |    |    |
     * |-----------------------------|  Up|----------------------------------|
     * |    |    |    |    | Bl+|    |    |    |    |PgUp| Tab|  / |  * |  - |
     * |---------------------------------------------------------------------|
     * |    |    |    |    | Bl~|    | Vol|    |    |PgDn|  7 |  8 |  9 |    |
     * |Caps|------------------------|Down|-----------------------------|  + |
     * |    |    |    |    | Bl-|    |    |    |    |    |  4 |  5 |  6 |    |
     * |---------------------------------------------------------------------|
     * |    |    |    |    |         |    |  Mute   | Del|  1 |  2 |  3 |    |
     * |    |------------------------|    |-----------------------------| Ent|
     * |    |    |    |    |         |    |         |    |  0 | 00 |  . |    |
     * `-------------------'         `----'         `------------------------'
	 */

    KEYMAP( PAUS, TRNS, PMNS, PPLS, PENT, \
            SLCK, TRNS, PAST, P9, P6, P3, PDOT, \
            PSCR, TRNS, PSLS, P8, P5, P2, P0, \
            WAKE, TRNS, TAB,  P7, P4, P1, P0, \
            SLEP, TRNS, PGUP, PGDN, TRNS, DELETE, TRNS, \
            PWR,  TRNS, TRNS, TRNS, TRNS, \
            EJCT, TRNS, TRNS, TRNS, TRNS, MUTE, \
            INS,  VOLU, VOLD, TRNS, \
            TRNS, TRNS, TRNS, TRNS, TRNS, \
            TRNS, TRNS, FN3,  FN2,  FN4,  TRNS, \
            NLCK, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
            TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
            TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, \
            TRNS, TRNS, TRNS, CAPS, TRNS ), 
};

/*
 * Fn action definition
 */
const action_t PROGMEM fn_actions[] = {
	ACTION_LAYER_TAP_KEY(1, KC_SPACE),   // FN0
	ACTION_LAYER_TOGGLE(1),              // FN1
	ACTION_BACKLIGHT_TOGGLE(),           // FN2
	ACTION_BACKLIGHT_INCREASE(),         // FN3
	ACTION_BACKLIGHT_DECREASE()          // FN4
};

// vim: ts=4:sw=4:ai
