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
#include "action.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const action_t fn_actions[];

#define KEYMAP( \
    K00, K01, K02, K03,      K05,       \
    K10, K11, K12, K13, K14, K15, K16,  \
    K20, K21, K22, K23, K24, K25, K26,  \
    K30, K31, K32, K33, K34, K35, K36,  \
    K40, K41, K42, K43, K44, K45, K46,  \
    K50, K51, K52, K53, K54,            \
    K60, K61, K62, K63, K64, K65,       \
    K70, K71,      K73,      K75,       \
    K80, K81, K82, K83, K84,            \
    K90, K91, K92, K93, K94, K95,       \
    KA0, KA1, KA2, KA3, KA4, KA5, KA6,  \
    KB0, KB1, KB2, KB3, KB4, KB5, KB6,  \
    KC0, KC1, KC2, KC3, KC4, KC5, KC6,  \
    KD0, KD1, KD2, KD3,      KD5       \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_NO,    KC_##K05, KC_NO     }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16  }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26  }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36  }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46  }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_NO,    KC_NO     }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_NO     }, \
    { KC_##K70, KC_##K71, KC_NO,    KC_##K73, KC_NO,    KC_##K75, KC_NO     }, \
    { KC_##K80, KC_##K81, KC_##K82, KC_##K83, KC_##K84, KC_NO,    KC_NO     }, \
    { KC_##K90, KC_##K91, KC_##K92, KC_##K93, KC_##K94, KC_##K95, KC_NO     }, \
    { KC_##KA0, KC_##KA1, KC_##KA2, KC_##KA3, KC_##KA4, KC_##KA5, KC_##KA6  }, \
    { KC_##KB0, KC_##KB1, KC_##KB2, KC_##KB3, KC_##KB4, KC_##KB5, KC_##KB6  }, \
    { KC_##KC0, KC_##KC1, KC_##KC2, KC_##KC3, KC_##KC4, KC_##KC5, KC_##KC6  }, \
    { KC_##KD0, KC_##KD1, KC_##KD2, KC_##KD3, KC_NO,    KC_##KD5, KC_NO     } \
}

// vim: ts=4:sw=4:ai
