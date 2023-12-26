// Copyright 2023 bluedrink9 (@bluedrink9)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define JOYSTICK_BUTTON_COUNT 1
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
#define JOYXPIN B0
#define JOYYPIN B1
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 12
#define JOYSTICK_AXIS_MAX 4095
#define ANALOG_JOYSTICK_CLICK_PIN A0

#define JOY_BUTTON_PIN B5
// #define JOY_BUTTON_KEY JS_0
#define JOY_BUTTON_KEY KC_X

#define DEBUG_MATRIX_SCAN_RATE
