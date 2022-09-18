#include QMK_KEYBOARD_H

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // layer 0 [WIN] (default)

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,            KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,           KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,             KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,             KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,             KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,             KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,             KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, LALT_T(KC_F14),                              KC_SPC,                             RALT_T(KC_F15),   MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),


    // layer 1 [WIN_FN]

    [1] = LAYOUT(
        XXXXXXX, KC_BRID, KC_BRIU, KC_CALC, KC_WHOM, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,            XXXXXXX,
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
        KC_LGUI, KC_LALT, LCTL_T(KC_LANG2),                            _______,                            RCTL_T(KC_LANG1), MO(3),   KC_RGUI, _______, _______, _______
    ),

    // layer 3 [MAC_FN]

    [3] = LAYOUT(
        XXXXXXX, KC_BRID, KC_BRIU, C(KC_UP), C(S(KC_UP)), RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,          XXXXXXX,
        XXXXXXX, RGB_TOG, RGB_HUI, RGB_HUD,  RGB_SAI,     RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,            XXXXXXX,
        XXXXXXX, TO(0),   XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,
        XXXXXXX,          XXXXXXX, RGB_HUI,  XXXXXXX,     XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, RGB_MOD, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                                 XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_RMOD, RGB_SPI
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
    return true;
}
#endif // ENCODER_ENABLE

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(RGB_RED);
    }
}
#endif // RGB_MATRIX_ENABLE
