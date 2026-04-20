#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "report.h"
#include "host.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  MO_NAV_LAYER,
  ALTTAB,
  SENS_R_MIN,
  SENS_L_MIN,
  SENS_R_LOW,
  SENS_L_LOW,
  SENS_R_MED,
  SENS_L_MED,
  SENS_R_HIGH,
  SENS_L_HIGH,
  OUTPUT_SENS,
  MO_MEDIA_LAYER,

  // The following require shift to be removed if it was previously pressed.
  // Otherwise, if you type "!=", for example, and press = before lifting the !,
  // the = will be sent before shift up is sent, and thus you will get "!+".
  EQUAL,
  MINUS,
  COMMA,
  DOT,
  SLASH,
  SCLN,
  QUOTE,
  BSLS,
  LBRC,
  RBRC,
};

enum {
  BASE = 0,
  // Qwerty has to come before other layers, because you can only transition to a higher layer.
  QWERTY,
  PUNC,
  GAMING,
  NAV,
  MOUSE,
  SENSITIVITY_CALIBRATION,
  MEDIA,
};

#define PLAY_PAUSE KC_MEDIA_PLAY_PAUSE
#define PREV_TRACK KC_MEDIA_PREV_TRACK
#define NEXT_TRACK KC_MEDIA_NEXT_TRACK

#define MAXIMISE LGUI(KC_UP)
#define SMALL_SCREEN LGUI(KC_DOWN)
#define LEFT_SCREEN LGUI(LSFT(KC_LEFT))
#define RIGHT_SCREEN LGUI(LSFT(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_F11,                       KC_F12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PSCR,
    KC_TAB,  KC_QUOTE,KC_COMMA, KC_DOT,  KC_P,    KC_Y,    KC_ENTER,                     KC_TRNS, KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_LSFT, KC_A,    KC_O,     KC_E,    KC_U,    KC_I,                                           KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENTER,
    KC_ESC,  KC_SCLN, KC_Q,     KC_J,    KC_K,    KC_X,    KC_BSPC,                      TG(GAMING), KC_B, KC_M,    KC_W,    KC_V,    KC_Z,    KC_DELETE,
    MO_MEDIA_LAYER, KC_TRNS, KC_TRNS, KC_EQUAL, KC_LCTL,                                          KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_6,    KC_7,                 TG(QWERTY), TG(SENSITIVITY_CALIBRATION),
                                                                   KC_8,                 KC_TRNS,
                                                 KC_SPACE, MO_NAV_LAYER, KC_LCTL,        TT(MOUSE), KC_LALT, MO(PUNC)
  ),

  [PUNC] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F11,                       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_GRAVE,
    KC_TRNS, KC_DQUO, COMMA,    KC_LCBR, KC_RCBR, KC_AT,   KC_TRNS,                      KC_TRNS, KC_HASH, KC_PERC, KC_LABK, KC_RABK, KC_AMPR, KC_TRNS,
    KC_NO,   KC_1,    EQUAL,    KC_LPRN, KC_RPRN, KC_QUES,                                        SLASH,   KC_UNDS, KC_PLUS, KC_ASTR, KC_0,    KC_TRNS,
    KC_TRNS, KC_COLN, KC_CIRC,  LBRC,    RBRC,    BSLS,    KC_TRNS,                      KC_TRNS, KC_DLR,  MINUS,   KC_EXLM, KC_TILD, KC_PIPE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,              KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [GAMING] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_K,    KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                         KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
    KC_TRNS, KC_I,    KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                         KC_TRNS, KC_Y,    KC_U,    KC_UP,   KC_O,    KC_P,    KC_TRNS,
    KC_J,    KC_G,    KC_A,     KC_S,    KC_D,    KC_F,                                           KC_H,    KC_LEFT, KC_DOWN, KC_RIGHT,KC_SCLN,  KC_ENTER,
    KC_ESCAPE, KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,                         KC_TRNS, KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH,KC_LSFT,
    KC_0,    KC_TRNS, KC_TRNS,  KC_L,    KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_NO,   KC_NO,
                                                                   KC_TRNS,              KC_TRNS,
                                                 KC_TRNS, MO_NAV_LAYER, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [QWERTY] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_ESCAPE, KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_6,                         KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQUAL,
    KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_ENTER,                     KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
    KC_CAPS, KC_A,    KC_S,     KC_D,    KC_F,    KC_G,                                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENTER,
    KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,                         KC_NO,   KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLASH,KC_DELETE,
    KC_0,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_TRNS, KC_NO,
                                                                   KC_TRNS,              KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [NAV] = LAYOUT_ergodox_pretty(
    // Left hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    ALTTAB,  KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                 KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                          KC_TRNS,     KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MOUSE] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, MS_UP,   KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, MS_WHLU, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS,                                         KC_TRNS, MS_BTN1, MS_BTN3, MS_BTN2, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_NO,   KC_TRNS, MS_WHLL, MS_WHLD, MS_WHLR, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_NO,   KC_NO,
                                                                   KC_TRNS,              KC_TRNS,
                                                 MS_ACL2, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [SENSITIVITY_CALIBRATION] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, SENS_L_MIN, SENS_L_LOW, SENS_L_MED, SENS_L_HIGH, KC_TRNS,                            KC_TRNS, SENS_R_HIGH, SENS_R_MED, SENS_R_LOW, SENS_R_MIN, OUTPUT_SENS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_NO,   KC_TRNS,
                                                                   KC_TRNS,              KC_TRNS,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [MEDIA] = LAYOUT_ergodox_pretty(
    // Left hand                                                                         // Right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_VOLD, KC_MPRV, KC_TRNS, KC_MNXT, KC_TRNS,                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                                          KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,
                                                                   KC_TRNS,              KC_TRNS,
                                                 KC_MPLY, KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS, KC_TRNS
  ),



/*
  [EMPTY] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
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


void matrix_init_user(void) {
};


static inline bool key_pressed(uint16_t keycode) {
  return (keyboard_report->mods & MOD_BIT(keycode)) != 0;
}

static inline bool shift_pressed(void) {
  return key_pressed(KC_LSFT);
}

static void send_key_without_shift(keyrecord_t *record, uint16_t keycode) {
  if (record->event.pressed) {
    if (shift_pressed()) {
      unregister_mods(MOD_MASK_SHIFT);
    }
    register_code(keycode);
  } else {
    unregister_code(keycode);
  }
}

static report_mouse_t mouse_report = {};
static int32_t mouse_total_x;
void move_mouse_single(int8_t x) {
  mouse_report.x = x;
  host_mouse_send(&mouse_report);
  mouse_total_x += x;
}

void move_mouse(int32_t x) {
  while (x > 127) {
    move_mouse_single(127);
    x -= 127;
  }
  while (x < -127) {
    move_mouse_single(-127);
    x -= -127;
  }
  move_mouse_single(x);
}

bool alttab_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO_MEDIA_LAYER:
      if (record->event.pressed) {
        layer_on(MEDIA);
        add_mods(MOD_MEH);
      } else {
        layer_off(MEDIA);
        del_mods(MOD_MEH);
      }
      return false;

    case EQUAL:
      send_key_without_shift(record, KC_EQUAL);
      return false;
    case MINUS:
      send_key_without_shift(record, KC_MINUS);
      return false;
    case COMMA:
      send_key_without_shift(record, KC_COMMA);
      return false;
    case DOT:
      send_key_without_shift(record, KC_DOT);
      return false;
    case SLASH:
      send_key_without_shift(record, KC_SLASH);
      return false;
    case SCLN:
      send_key_without_shift(record, KC_SCLN);
      return false;
    case QUOTE:
      send_key_without_shift(record, KC_QUOTE);
      return false;
    case BSLS:
      send_key_without_shift(record, KC_BSLS);
      return false;
    case LBRC:
      send_key_without_shift(record, KC_LBRC);
      return false;
    case RBRC:
      send_key_without_shift(record, KC_RBRC);
      return false;

    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;

    case MO_NAV_LAYER:
      if (record->event.pressed) {
        layer_on(NAV);
      } else {
        layer_off(NAV);
        if (alttab_enabled) {
          alttab_enabled = false;
          unregister_code(KC_LALT);
        }
      }
      return false;

    case ALTTAB:
      if (record->event.pressed) {
        register_code(KC_LALT);
        register_code(KC_TAB);
        alttab_enabled = true;
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case SENS_R_MIN:
      if (record->event.pressed) {
        move_mouse(1);
      }
      return false;
    case SENS_L_MIN:
      if (record->event.pressed) {
        move_mouse(-1);
      }
      return false;
    case SENS_R_LOW:
      if (record->event.pressed) {
        move_mouse(16);
      }
      return false;
    case SENS_L_LOW:
      if (record->event.pressed) {
        move_mouse(-16);
      }
      return false;
    case SENS_R_MED:
      if (record->event.pressed) {
        move_mouse(256);
      }
      return false;
    case SENS_L_MED:
      if (record->event.pressed) {
        move_mouse(-256);
      }
      return false;
    case SENS_R_HIGH:
      if (record->event.pressed) {
        move_mouse(4096);
      }
      return false;
    case SENS_L_HIGH:
      if (record->event.pressed) {
        move_mouse(-4096);
      }
      return false;
      
    case OUTPUT_SENS:
      if (record->event.pressed) {
        char s[12]; // '-', 4e9, '\0'
        sprintf(s, "%ld", mouse_total_x);
        mouse_total_x = 0;
        send_string(s);
        return false;
      }
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case GAMING:
        ergodox_right_led_1_on();
        break;
      case QWERTY:
        ergodox_right_led_2_on();
        break;
      case MOUSE:
        ergodox_right_led_3_on();
        break;
      case SENSITIVITY_CALIBRATION:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
