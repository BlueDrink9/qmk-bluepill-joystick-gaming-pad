// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, LT(1, KC_5),
        KC_Q, KC_W, KC_E, KC_R,
        KC_TAB, KC_A, KC_S, KC_D, KC_F,
        KC_LSFT, KC_C,
        KC_LCTL, KC_LALT, KC_SPC,
    ),

    LAYOUT(
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, RESET,
    )
};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(B0, 900, 575, 285), // X
    JOYSTICK_AXIS_IN(B1, 900, 575, 285), // Y
};

// JS_0 // TODO
