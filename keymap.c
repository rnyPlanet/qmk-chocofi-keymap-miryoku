#include QMK_KEYBOARD_H
#include <stdio.h>
#include <keymap_russian.h>
#include <enums.h>

#define XXXXXXX KC_NO

#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)
#define HOME_J LSFT_T(KC_J)
#define HOME_K LCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN LGUI_T(KC_SCLN)

#define RALT_X RALT_T(KC_X)
#define RALT_DOT RALT_T(KC_DOT)

enum {
    TD_LSFT_CAPS,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#define TD_LSFT_CAPS TD(TD_LSFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         HOME_A,  HOME_S,  HOME_D,  HOME_F,    KC_G,                         KC_H,  HOME_J,  HOME_K,  HOME_L,HOME_SCLN,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_Z,  RALT_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,RALT_DOT, KC_SLSH,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                LT(_F, KC_TAB),
                                    LT(_ARROWS, KC_ESC),
                                        LT(_NUMS, KC_ENT),
                                                                        LT(_MOUSE, KC_SPC),
                                                                            KC_BSPC,
                                                                               KC_DEL
                                //`--------------------------'  `--------------------------'
    ),

    [_ARROWS] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_PSCR,                      KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_CAPS,                      KC_CAPS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_INS,                       KC_INS, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                        _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [_NUMS] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
         KC_EQL,    KC_9,    KC_8,    KC_7, KC_MINS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_LBRC,    KC_6,    KC_5,    KC_4, KC_RBRC,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_BSLS,    KC_3,    KC_2,    KC_1,    KC_0,                       KC_GRV, XXXXXXX, XXXXXXX, KC_RALT, KC_QUOT,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [_F] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
         KC_F12,   KC_F9,   KC_F8,   KC_F7, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_F11,   KC_F6,   KC_F5,   KC_F4, XXXXXXX,                      XXXXXXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_F10,   KC_F3,   KC_F2,   KC_F1, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_RALT, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                            _______, _______, _______,    _______, _______, _______
                                        //`--------------------------'  `--------------------------'
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.                    ,--------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX, KC_RALT, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
    //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                                            _______, _______, _______,    KC_BTN1, KC_BTN3, KC_BTN2
                                        //`--------------------------'  `--------------------------'
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            // Detect the activation of only Left Alt
            if ((get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                if (record->event.pressed) {
                    // No need to register KC_LALT because it's already active.
                    // The Alt modifier will apply on this KC_TAB.
                    register_code(KC_TAB);
                } else {
                    unregister_code(KC_TAB);
                }
                // Do not let QMK process the keycode further
                return false;
            }
            // Else, let QMK process the KC_ESC keycode as usual
            return true;


        case KC_PASTE:
            if (record->event.pressed) {
                    unregister_code(KC_PASTE);

                    register_code(KC_LCTL);
                    register_code(KC_V);

                    unregister_code(KC_LCTL);
                    unregister_code(KC_V);
            } else {
                unregister_code(KC_PASTE);
                unregister_code(KC_LCTL);
                unregister_code(KC_V);
            }
            return false;

        case KC_COPY:
            if (record->event.pressed) {
                    unregister_code(KC_COPY);

                    register_code(KC_LCTL);
                    register_code(KC_C);

                    //register_code(KC_COPY);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_C);
            } else {
                unregister_code(KC_COPY);
                unregister_code(KC_LCTL);
                unregister_code(KC_C);
            }
            return false;

        case KC_CUT:
            if (record->event.pressed) {
                    unregister_code(KC_CUT);

                    register_code(KC_LCTL);
                    register_code(KC_X);

                    unregister_code(KC_LCTL);
                    unregister_code(KC_X);
            } else {
                unregister_code(KC_CUT);
                unregister_code(KC_LCTL);
                unregister_code(KC_X);
            }
            return false;

        case KC_UNDO:
            if (record->event.pressed) {
                unregister_code(KC_UNDO);

                register_code(KC_LCTL);
                register_code(KC_Z);

                //register_code(KC_UNDO);
                unregister_code(KC_LCTL);
                unregister_code(KC_Z);
            } else {
                unregister_code(KC_UNDO);
                unregister_code(KC_LCTL);
                unregister_code(KC_Z);
            }
            return false;

        default:
            return true;

    }

    return true;
}
