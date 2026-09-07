/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_FUNCTION,
    LAYER_NAVIGATION,
    LAYER_MEDIA,
    LAYER_POINTER,
    LAYER_NUMERAL,
    LAYER_SYMBOLS,
};

#define ESC_MED LT(LAYER_MEDIA, KC_ESC)
#define SPC_NAV LT(LAYER_NAVIGATION, KC_SPC)
#define TAB_FUN LT(LAYER_FUNCTION, KC_TAB)
#define ENT_SYM LT(LAYER_SYMBOLS, KC_ENT)
#define BSP_NUM LT(LAYER_NUMERAL, KC_BSPC)
#define _L_PTR(KC) LT(LAYER_POINTER, KC)

/*
 * BastardKB pointing-device keycodes.
 *
 * Current bk_pointing_device uses module keycode space. These values are
 * BastardKB's compatibility values for the old Charybdis aliases.
 *
 * Keep the #ifndef guards so this continues to work if the module exposes
 * the names directly in a future/current build.
 */
#ifdef POINTING_DEVICE_ENABLE

#    ifndef DPI_MOD
#        define DPI_MOD 0x7E00
#    endif

#    ifndef DPI_RMOD
#        define DPI_RMOD 0x7E01
#    endif

#    ifndef S_D_MOD
#        define S_D_MOD 0x7E02
#    endif

#    ifndef S_D_RMOD
#        define S_D_RMOD 0x7E03
#    endif

#    ifndef SNIPING
#        define SNIPING 0x7E04
#    endif

#    ifndef SNP_TOG
#        define SNP_TOG 0x7E05
#    endif

#    ifndef DRGSCRL
#        define DRGSCRL 0x7E06
#    endif

#    ifndef DRG_TOG
#        define DRG_TOG 0x7E07
#    endif

#else

#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define DPI_RMOD KC_NO
#    define S_D_MOD KC_NO
#    define S_D_RMOD KC_NO
#    define SNIPING KC_NO
#    define SNP_TOG KC_NO
#    define DRG_TOG KC_NO

#endif

// clang-format off

/**
 * Base layer.
 *
 * Swedish OS layout:
 * KC_QUOT -> Ä
 * KC_SLSH -> -
 */
#define LAYOUT_LAYER_BASE                                                                     \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
                      ESC_MED, SPC_NAV, TAB_FUN, ENT_SYM, BSP_NUM


/** Convenience row shorthands. */
#define _______________DEAD_HALF_ROW_______________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ______________HOME_ROW_GACS_L______________ KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX
#define ______________HOME_ROW_GACS_R______________ XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI


/**
 * Function layer.
 */
#define LAYOUT_LAYER_FUNCTION                                                                 \
    _______________DEAD_HALF_ROW_______________, KC_PSCR, KC_F7, KC_F8, KC_F9, KC_F12,       \
    ______________HOME_ROW_GACS_L______________, KC_SCRL, KC_F4, KC_F5, KC_F6, KC_F11,       \
    _______________DEAD_HALF_ROW_______________, KC_PAUS, KC_F1, KC_F2, KC_F3, KC_F10,       \
                      XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX


/**
 * Media + RGB matrix controls.
 */
#define LAYOUT_LAYER_MEDIA                                                                    \
    XXXXXXX, RM_PREV, RM_TOGG, RM_NEXT, XXXXXXX, XXXXXXX, RM_PREV, RM_TOGG, RM_NEXT, XXXXXXX, \
    KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT, KC_MPRV, KC_VOLD, KC_MUTE, KC_VOLU, KC_MNXT, \
    XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR, QK_BOOT, QK_BOOT, EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX,   \
                      _______, KC_MPLY, KC_MSTP, KC_MSTP, KC_MPLY


/**
 * Pointer layer.
 *
 * Bindings kept in the same positions as your old layout.
 */
#define LAYOUT_LAYER_POINTER                                                                  \
    QK_BOOT, EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR, QK_BOOT,  \
    ______________HOME_ROW_GACS_L______________, ______________HOME_ROW_GACS_R______________, \
    _______, DRGSCRL, SNIPING, DPI_MOD, DPI_RMOD, S_D_MOD, S_D_RMOD, SNIPING, DRGSCRL, _______, \
                      MS_BTN2, MS_BTN1, MS_BTN3, MS_BTN3, MS_BTN1


/**
 * Navigation layer.
 *
 * CW_TOGG replaces normal Caps Lock.
 */
#define LAYOUT_LAYER_NAVIGATION                                                               \
    _______________DEAD_HALF_ROW_______________, CW_TOGG, KC_INS, XXXXXXX, XXXXXXX, XXXXXXX, \
    ______________HOME_ROW_GACS_L______________, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_PGUP,  \
    _______________DEAD_HALF_ROW_______________, LALT(KC_LEFT), LALT(KC_RGHT), KC_HOME, KC_END, KC_PGDN, \
                      XXXXXXX, _______, XXXXXXX, KC_ENT, KC_DEL


/**
 * Numeral layer.
 *
 * Kept exactly in your Swedish-layout-oriented arrangement.
 *
 * Swedish examples:
 * RALT(KC_NUBS)   -> |
 * LSFT(KC_EQL)    -> `
 */
#define LAYOUT_LAYER_NUMERAL                                                                  \
    KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6, KC_7, KC_8, KC_9, KC_0,            \
    ______________HOME_ROW_GACS_L______________,      KC_MINS, LSFT(KC_EQL), KC_EQL, KC_RBRC, LSFT(KC_NUHS), \
    RALT(KC_NUBS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, KC_SLSH, \
                      KC_DOT, KC_0, KC_MINS, XXXXXXX, _______


/**
 * Symbols layer.
 *
 * Swedish-layout-oriented keycodes kept from your layout.
 * Å = KC_LBRC
 * Ö = KC_SCLN
 */
#define LAYOUT_LAYER_SYMBOLS                                                                  \
    LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5),                              \
    LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0),                              \
                                                                                               \
    XXXXXXX, RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),                                 \
    LSFT(KC_MINS), XXXXXXX, RALT(KC_RBRC), LSFT(KC_RBRC), KC_NUHS,                           \
                                                                                               \
    KC_NUBS, LSFT(KC_NUBS), KC_LBRC, KC_SCLN, XXXXXXX,                                       \
    RALT(KC_7), RALT(KC_0), RALT(KC_8), RALT(KC_9), RALT(KC_MINS),                           \
                                                                                               \
                      KC_LPRN, KC_RPRN, KC_UNDS, _______, XXXXXXX


/**
 * Add Home Row mods to base layer.
 */
#define _HOME_ROW_MOD_GACS(                                            \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,                \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,                \
    ...)                                                               \
             L00,         L01,         L02,         L03,         L04, \
             R05,         R06,         R07,         R08,         R09, \
      LGUI_T(L10), LALT_T(L11), LCTL_T(L12), LSFT_T(L13),        L14, \
             R15,  RSFT_T(R16), RCTL_T(R17), LALT_T(R18), RGUI_T(R19), \
      __VA_ARGS__

#define HOME_ROW_MOD_GACS(...) _HOME_ROW_MOD_GACS(__VA_ARGS__)


/**
 * Z and the right-most bottom-row key become pointer-layer holds.
 */
#define _POINTER_MOD(                                                 \
    L00, L01, L02, L03, L04, R05, R06, R07, R08, R09,               \
    L10, L11, L12, L13, L14, R15, R16, R17, R18, R19,               \
    L20, L21, L22, L23, L24, R25, R26, R27, R28, R29,               \
    ...)                                                              \
             L00,         L01,         L02,         L03,         L04, \
             R05,         R06,         R07,         R08,         R09, \
             L10,         L11,         L12,         L13,         L14, \
             R15,         R16,         R17,         R18,         R19, \
      _L_PTR(L20),        L21,         L22,         L23,         L24, \
             R25,         R26,         R27,         R28, _L_PTR(R29), \
      __VA_ARGS__

#define POINTER_MOD(...) _POINTER_MOD(__VA_ARGS__)


#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT_wrapper(
        POINTER_MOD(HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE))
    ),

    [LAYER_FUNCTION]   = LAYOUT_wrapper(LAYOUT_LAYER_FUNCTION),
    [LAYER_NAVIGATION] = LAYOUT_wrapper(LAYOUT_LAYER_NAVIGATION),
    [LAYER_MEDIA]      = LAYOUT_wrapper(LAYOUT_LAYER_MEDIA),
    [LAYER_NUMERAL]    = LAYOUT_wrapper(LAYOUT_LAYER_NUMERAL),
    [LAYER_POINTER]    = LAYOUT_wrapper(LAYOUT_LAYER_POINTER),
    [LAYER_SYMBOLS]    = LAYOUT_wrapper(LAYOUT_LAYER_SYMBOLS),
};

// clang-format on