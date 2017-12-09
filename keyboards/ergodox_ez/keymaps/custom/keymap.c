#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,

};

enum {
  BASE = 0,
  PUNC,
  NAV,
  NUMBERS,
  GAMING,
  MOUSE,
  MACRO,
};

#define SHIFT_ESCAPE SFT_T(KC_ESCAPE)
#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK

#define MAXIMISE LGUI(KC_UP)
#define SMALL_SCREEN LGUI(KC_DOWN)
#define LEFT_SCREEN LGUI(LSFT(KC_LEFT))
#define RIGHT_SCREEN LGUI(LSFT(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F11,
    KC_TAB,        KC_QUOTE,      KC_COMMA,      KC_DOT,        KC_P,          KC_Y,          KC_ENTER,
    SHIFT_ESCAPE,  KC_A,          KC_O,          KC_E,          KC_U,          KC_I,
    MEH_T(KC_NO),  KC_SCOLON,     KC_Q,          KC_J,          KC_K,          KC_X,          TG(GAMING),
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_LALT,       KC_LCTL,

    // Left Thumb Cluster
                                                                               PLAY_PAUSE,    KC_APPLICATION,
                                                                                              KC_LGUI,
                                                                KC_SPACE,      MO(NAV),       KC_LCTL,

    // Right hand
    KC_F12,        KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_PSCREEN,
    KC_TRNS,       KC_F,          KC_G,          KC_C,          KC_R,          KC_L,          KC_BSPACE,
                   KC_D,          KC_H,          KC_T,          KC_N,          KC_S,          KC_ENTER,
    KC_TRNS,       KC_B,          KC_M,          KC_W,          KC_V,          KC_Z,          KC_DELETE,
                                  KC_LGUI,       TT(MOUSE),     KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    PREV_TRACK,    NEXT_TRACK,
    KC_TRNS,
    KC_TRNS,       MO(NUMBERS),   MO(PUNC)
  ),

  [PUNC] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_DQUO,       KC_COMMA,      KC_LCBR,       KC_RCBR,       KC_HASH,       KC_TRNS,
    KC_GRAVE,      KC_1,          KC_EQUAL,      KC_LPRN,       KC_RPRN,       KC_QUES,
    KC_TRNS,       KC_COLN,       KC_CIRC,       KC_LBRACKET,   KC_RBRACKET,   KC_BSLASH,     KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       MO(NUMBERS),   KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_AT,         KC_LABK,       KC_MINUS,      KC_RABK,       KC_AMPR,       KC_TRNS,
                   KC_SLASH,      KC_UNDS,       KC_KP_PLUS,    KC_KP_ASTERISK,KC_0,          KC_TRNS,
    KC_TRNS,       KC_DLR,        KC_EXLM,       KC_PERC,       KC_TILD,       KC_PIPE,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [NAV] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    LSFT(KC_TAB),  KC_PGUP,       KC_HOME,       KC_UP,         KC_END,        KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_PGDOWN,     KC_LEFT,       KC_DOWN,       KC_RIGHT,      KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       MAXIMISE,      KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_TRNS,       LEFT_SCREEN,   SMALL_SCREEN,  RIGHT_SCREEN,  KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [NUMBERS] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [GAMING] = KEYMAP(
    // Left hand
    KC_ESCAPE,     KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_6,
    KC_TAB,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,
    KC_SCOLON,     KC_A,          KC_S,          KC_D,          KC_F,          KC_G,
    KC_LSHIFT,     KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_TRNS,
    KC_LCTL,       KC_U,          KC_P,          KC_LALT,       KC_SPACE,

    // Left Thumb Cluster
                                                                               KC_7,          KC_8,
                                                                                              KC_PGUP,
                                                                KC_0,          KC_9,          KC_PGDOWN,

    // Right hand
    KC_TRNS,       KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_EQUAL,
    KC_TRNS,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_TRNS,
                   KC_H,          KC_J,          KC_K,          KC_L,          KC_SCOLON,     KC_ENTER,
    KC_TRNS,       KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_SLASH,      KC_LSHIFT,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [MOUSE] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_MS_UP,      KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_MS_LEFT,    KC_MS_DOWN,    KC_MS_RIGHT,   KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_MS_ACCEL2,  KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_MS_WH_UP,   KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_TRNS,       KC_MS_BTN1,    KC_MS_BTN3,    KC_MS_BTN2,    KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       RESET,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

/*
  [MACRO] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_F11,        KC_F12,        KC_F13,        KC_F14,        KC_F15,        KC_TRNS,
    KC_TRNS,       KC_F6,         KC_F7,         KC_F8,         LALT(LSFT(KC_F9)),KC_F10,
    TO(0),         LALT(LSFT(KC_F1)),KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       LALT(LSFT(KC_1)),LALT(LSFT(KC_2)),KC_3,          KC_4,          KC_5,          KC_TRNS,
                   KC_F21,        KC_F22,        KC_F23,        KC_F24,        KC_0,          KC_TRNS,
    KC_TRNS,       LALT(LSFT(KC_F16)),KC_F17,        KC_F18,        KC_F19,        KC_F20,        KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),
*/

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case GAMING:
        ergodox_right_led_1_on();
        break;
      case MOUSE:
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
