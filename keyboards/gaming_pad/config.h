// Copyright 2023 bluedrink9 (@bluedrink9)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define JOYSTICK_BUTTON_COUNT 1
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
#define JOYXPIN B0
#define JOYYPIN B1
// Min 8, max 16
// #define JOYSTICK_AXIS_RESOLUTION 10
#define ANALOG_JOYSTICK_CLICK_PIN A0

#define JOY_BUTTON_PIN B5
#define JOY_BUTTON_KEY KC_X

#define DEBUG_MATRIX_SCAN_RATE
