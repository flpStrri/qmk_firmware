/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>
The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
if that's your preference.

To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
it'll be back to normal when you plug it back in.

This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
*/

#include QMK_KEYBOARD_H
#define KC_CAPW LGUI(LSFT(KC_3))

enum layers { MAC_BASE = 0, MAC_FN };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC_BASE] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,     KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12,   KC_EJCT,           KC_MUTE,
        KC_GRV,   KC_1,    KC_2,    KC_3,      KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,   KC_BSPC,           KC_HOME,
        KC_TAB,   KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,  KC_BSLS,           KC_PGUP,
        KC_CAPS,  KC_A,    KC_S,    KC_D,      KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,                      KC_PGDN,
        KC_LSFT,           KC_Z,    KC_X,      KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,  KC_UP,             KC_END,
        KC_LCTL,  KC_LOPT, KC_LCMD,                              KC_SPC,                             KC_RCMD, MO(MAC_FN), KC_LCTL , KC_LEFT, KC_DOWN,  KC_RGHT
    ),

    [MAC_FN] = LAYOUT(
        _______,  KC_BRID, KC_BRIU, KC_MCTL,   KC_LPAD, RGB_VAD, RGB_VAI, KC_F7,   KC_F8,   KC_MRWD, KC_MPLY, KC_MFFD,    _______,  _______,           RGB_TOG,
        _______,  _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______, _______,    _______,  KC_DEL,            KC_CAPW ,
        _______,  RGB_HUI, RGB_VAI, RGB_SAI,   _______, _______, _______, _______, _______, _______, _______, _______,    _______,  QK_BOOT,           KC_F14,
        _______,  RGB_HUD, RGB_VAD, RGB_SAD,   _______, _______, _______, _______, _______, _______, _______, _______,              _______,           KC_F15,
        _______,           _______, _______,   _______, _______, _______, NK_TOGG, _______, _______, _______, _______,              _______, RGB_MOD,  KC_F16,
        _______,  _______, _______,                              _______,                            _______, _______,    _______,  RGB_SPD, RGB_RMOD, RGB_SPI
    ),

};

// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN) }
};
#endif