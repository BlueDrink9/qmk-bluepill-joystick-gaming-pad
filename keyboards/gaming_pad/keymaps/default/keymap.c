#include QMK_KEYBOARD_H
#include "analog.h"
#include "print.h"
#include "joystick.h"


int16_t joyXMid = 512;
int16_t joyYMid = 512;

static uint8_t direct_pin_state = 0; // Store last state

void scan_joystick_button(void);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT(
        KC_ESC, KC_1, KC_2, KC_3, KC_4, LT(1, KC_5),
        KC_Q, KC_W, KC_E, KC_R,
        KC_TAB, KC_A, KC_S, KC_D, KC_F,
        KC_LSFT, KC_C,
        KC_LCTL, KC_LALT, KC_SPC
    ),
    LAYOUT(
        TO(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        QK_BOOT, KC_TRNS,
        KC_TRNS, KC_TRNS, QK_BOOT
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}


void keyboard_pre_init_user(void) {
    // Joystick setup
    setPinInputHigh(JOY_BUTTON_PIN);
    if ((joyXMid != analogReadPin(JOYXPIN))|(joyYMid != analogReadPin(JOYYPIN))) {
        joyXMid = analogReadPin(JOYXPIN);
        joyYMid = analogReadPin(JOYYPIN);
    }
}

void matrix_init_user(){
}

void matrix_scan_user(void) {
    scan_joystick_button();
};

void scan_joystick_button(){
    uint8_t current_state = readPin(JOY_BUTTON_PIN);
    // Check for state change from high to low (button press)
    if (direct_pin_state && !current_state) {
        // Button was high, now low: Key press
        register_code(JOY_BUTTON_KEY); // Replace with your desired key
    } else if (!direct_pin_state && current_state) {
        // Button was low, now high: Key release
        unregister_code(JOY_BUTTON_KEY); // Replace with your desired key
    }
    // Update last state
    direct_pin_state = current_state;
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(JOYXPIN, 1023, 512, 0), // X, Low(l) ~ High(R)
    JOYSTICK_AXIS_IN(JOYXPIN, 1023, 512, 0), // Y, Low(U) ~ High(D)
};


