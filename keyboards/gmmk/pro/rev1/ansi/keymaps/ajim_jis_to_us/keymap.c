/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

// shift+2  " -> @
const key_override_t kor_at = ko_make_with_layers(MOD_MASK_SHIFT, KC_2, JP_AT, 1);
// shift+6  & -> ^
const key_override_t kor_circ = ko_make_with_layers(MOD_MASK_SHIFT, KC_6, JP_CIRC, 1);
// shift+7  ' -> &
const key_override_t kor_ampr = ko_make_with_layers(MOD_MASK_SHIFT, KC_7, JP_AMPR, 1);
// shift+8  ( -> *
const key_override_t kor_astr = ko_make_with_layers(MOD_MASK_SHIFT, KC_8, JP_ASTR, 1);
// shift+9  ) -> (
const key_override_t kor_lprn = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, JP_LPRN, 1);
// shift+0    -> )
const key_override_t kor_rprn = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, JP_RPRN, 1);
// shift+-  = -> _
const key_override_t kor_unds = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, JP_UNDS, 1);
// =        ^ -> =
// shift+=  ~ -> +
const key_override_t kor_eql = ko_make_with_layers_and_negmods(0, JP_CIRC, JP_EQL, 1, MOD_MASK_SHIFT);
const key_override_t kor_plus = ko_make_with_layers(MOD_MASK_SHIFT, JP_CIRC, JP_PLUS, 1);
/* \        ] -> \ */
/* shift+\  } -> | */
const key_override_t kor_bsls = ko_make_with_layers_and_negmods(0, KC_BSLS, JP_BSLS, 1, MOD_MASK_SHIFT);
const key_override_t kor_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, JP_PIPE, 1);
// [        @ -> [
// shift+[  ` -> {
const key_override_t kor_lbrc = ko_make_with_layers_and_negmods(0, JP_AT, JP_LBRC, 1, MOD_MASK_SHIFT);
const key_override_t kor_lcbr = ko_make_with_layers(MOD_MASK_SHIFT, JP_AT, JP_LCBR, 1);
// ]        [ -> ]
// shift+]  { -> }
const key_override_t kor_rbrc = ko_make_with_layers_and_negmods(0, JP_LBRC, JP_RBRC, 1, MOD_MASK_SHIFT);
const key_override_t kor_rcbr = ko_make_with_layers(MOD_MASK_SHIFT, JP_LBRC, JP_RCBR, 1);
// shift+;  + -> :
const key_override_t kor_coln = ko_make_with_layers(MOD_MASK_SHIFT, KC_SCLN, JP_COLN, 1);
// '        : -> '
// shift+'  * -> "
const key_override_t kor_quot = ko_make_with_layers_and_negmods(0, KC_QUOT, JP_QUOT, 1, MOD_MASK_SHIFT);
const key_override_t kor_dquo = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, JP_DQUO, 1);
// `        全角半角 -> `
// shift+`  shift+全角半角 -> ~
const key_override_t kor_grv = ko_make_with_layers_and_negmods(0, JP_ZKHK, JP_GRV, 1, MOD_MASK_SHIFT);
const key_override_t kor_tild = ko_make_with_layers(MOD_MASK_SHIFT, JP_ZKHK, JP_TILD, 1);
// Caps     英数 -> Caps
const key_override_t kor_caps = ko_make_with_layers_and_negmods(0, JP_EISU, JP_CAPS, 1, MOD_MASK_SHIFT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &kor_at,
    &kor_circ,
    &kor_ampr,
    &kor_astr,
    &kor_lprn,
    &kor_rprn,
    &kor_unds,
    &kor_eql,
    &kor_plus,
    &kor_bsls,
    &kor_pipe,
    &kor_lbrc,
    &kor_lcbr,
    &kor_rbrc,
    &kor_rcbr,
    &kor_coln,
    &kor_quot,
    &kor_dquo,
    &kor_grv,
    &kor_tild,
    &kor_caps,
    NULL
};

enum custom_keycodes {
   LT_CAPS = SAFE_RANGE
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10             F11      F12	    Del            Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0               -        (=)	    BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P               [        ]        \                 End
//      Caps     A        S        D        F        G        H        J        K        L        ;               "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .               ?                 Sh_R     Up       PgDn
//      Ct_L     Win_L    Alt_L(ImeOff)                       SPACE                               Alt_R(ImeOn)    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

    // layer 0 [WIN] (default)

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,            KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,             KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,             KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        LT_CAPS, KC_A,    KC_S,             KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,             KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, LALT_T(JP_MHEN),                             KC_SPC,                             RALT_T(JP_HENK),  MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),


    // layer 1 [WIN_FN]

    [1] = LAYOUT(
        XXXXXXX, KC_BRID, KC_BRIU, KC_CALC, KC_WHOM, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, XXXXXXX, TO(2),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_RMOD, RGB_SPI
    ),


    // layer 2 [MAC]

    [2] = LAYOUT(
        _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______,
        _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______,
        _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,          _______,
        _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,          _______,
        _______,          _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, _______, _______,
        KC_LGUI, KC_LALT, LCTL_T(KC_LNG2),                             _______,                            RCTL_T(KC_LNG1),  MO(3),   KC_RGUI, _______, _______, _______
    ),

    // layer 3 [MAC_FN]

    [3] = LAYOUT(
        XXXXXXX, KC_BRID, KC_BRIU, C(KC_UP), C(S(KC_UP)), RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD,  RGB_SAI,     RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          XXXXXXX,
        XXXXXXX, TO(0),   XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, RGB_HUI,  XXXXXXX,     XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    // layer 4 [TENKEY]

    [4] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    JP_COLN, XXXXXXX,          _______,          XXXXXXX,
        XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                            KC_0,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),


};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;
}
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(RGB_RED);
    }
    if (layer_state_is(2)) {
        rgb_matrix_set_color_all(RGB_CYAN);
    }
    if (layer_state_is(4)) {
        rgb_matrix_set_color_all(RGB_SPRINGGREEN);
    }
    return false;
}
#endif

static bool caps_pressed = false;
static uint16_t caps_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT_CAPS:
      if (record->event.pressed) {
        caps_pressed = true;
        caps_pressed_time = record->event.time;

        layer_on(4);
      } else {
        layer_off(4);

        if (caps_pressed && (TIMER_DIFF_16(record->event.time, caps_pressed_time) < TAPPING_TERM)) {
          register_code(KC_LSFT);
          register_code(KC_CAPS);
          unregister_code(KC_CAPS);
          unregister_code(KC_LSFT);
        }
        caps_pressed = false;
      }
      return false;
      break;
  }
  return true;
}
