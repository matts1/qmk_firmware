#include "ergodox_ez.h"
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
  CRITIQUE,
  GMAIL,
  GMM,
  JCG,
  CODE_SEARCH,
  CHROME_TAB,
  GOLINK,
  BUG,
  SENS_R_MIN,
  SENS_L_MIN,
  SENS_R_LOW,
  SENS_L_LOW,
  SENS_R_MED,
  SENS_L_MED,
  SENS_R_HIGH,
  SENS_L_HIGH,
  OUTPUT_SENS,
};

enum {
  BASE = 0,
  PUNC,
  GAMING,
  QWERTY,
  NAV,
  MOUSE,
  SENSITIVITY_CALIBRATION,
};

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
    KC_TRNS,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_F11,
    KC_TAB,        KC_QUOTE,      KC_COMMA,      KC_DOT,        KC_P,          KC_Y,          KC_ENTER,
    KC_LSHIFT,     KC_A,          KC_O,          KC_E,          KC_U,          KC_I,
    KC_ESC,        KC_SCOLON,     KC_Q,          KC_J,          KC_K,          KC_X,          KC_BSPACE,
    MEH_T(KC_NO),  KC_TRNS,       KC_TRNS,       KC_EQUAL,      KC_LCTL,

    // Left Thumb Cluster
                                                                               KC_6,          KC_7,
                                                                                              KC_8,
                                                                KC_SPACE,      MO_NAV_LAYER,  KC_LCTL,

    // Right hand
    KC_F12,        KC_6,          KC_7,          KC_8,          KC_9,          KC_0 ,         KC_PSCREEN,
    KC_TRNS,       KC_F,          KC_G,          KC_C,          KC_R,          KC_L,          KC_BSPACE,
                   KC_D,          KC_H,          KC_T,          KC_N,          KC_S,          KC_ENTER,
    TG(GAMING),    KC_B,          KC_M,          KC_W,          KC_V,          KC_Z,          KC_DELETE,
                                  KC_LGUI,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    TG(QWERTY),    TG(SENSITIVITY_CALIBRATION),
    KC_TRNS,
    TT(MOUSE),     KC_LALT,       MO(PUNC)
  ),

  [PUNC] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F11,
    KC_TRNS,       KC_DQUO,       KC_COMMA,      KC_LCBR,       KC_RCBR,       KC_AT,         KC_TRNS,
    KC_NO,         KC_1,          KC_EQUAL,      KC_LPRN,       KC_RPRN,       KC_QUES,
    KC_TRNS,       KC_COLN,       KC_CIRC,       KC_LBRACKET,   KC_RBRACKET,   KC_BSLASH,     KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_F12,        KC_F6,         KC_F7,         KC_F8,         KC_F9,         KC_F10,        KC_GRAVE,
    KC_TRNS,       KC_HASH,       KC_PERC,       KC_LABK,       KC_RABK,       KC_AMPR,       KC_TRNS,
                   KC_SLASH,      KC_UNDS,       KC_PLUS,       KC_ASTERISK,   KC_0,          KC_TRNS,
    KC_TRNS,       KC_DLR,        KC_MINUS,      KC_EXLM,       KC_TILD,       KC_PIPE,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [GAMING] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_K,          KC_1,          KC_2,          KC_3,          KC_4,          KC_5,
    KC_TRNS,       KC_I,          KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,
    KC_J,          KC_G,          KC_A,          KC_S,          KC_D,          KC_F,
    KC_ESCAPE,     KC_LSHIFT,     KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,
    KC_0,          KC_TRNS,       KC_TRNS,       KC_L,          KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       MO_NAV_LAYER,  KC_TRNS,

    // Right hand
    KC_TRNS,       KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_EQUAL,
    KC_TRNS,       KC_Y,          KC_U,          KC_UP,         KC_O,          KC_P,          KC_TRNS,
                   KC_H,          KC_LEFT,       KC_DOWN,       KC_RIGHT,      KC_SCOLON,     KC_ENTER,
    KC_TRNS,       KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_SLASH,      KC_LSHIFT,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_NO,         KC_NO,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [QWERTY] = KEYMAP(
    // Left hand
    KC_ESCAPE,     KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_6,
    KC_TAB,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_ENTER,
    KC_SCOLON,     KC_A,          KC_S,          KC_D,          KC_F,          KC_G,
    KC_LSHIFT,     KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_N,
    KC_0,          KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_EQUAL,
    KC_TRNS,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_TRNS,
                   KC_H,          KC_J,          KC_K,          KC_L,          KC_SCOLON,     KC_ENTER,
    KC_NO,         KC_N,          KC_M,          KC_COMMA,      KC_DOT,        KC_SLASH,      KC_LSHIFT,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_TRNS,       KC_NO,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [NAV] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    ALTTAB,        KC_PGUP,       KC_HOME,       KC_UP,         KC_END,        KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_PGDOWN,     KC_LEFT,       KC_DOWN,       KC_RIGHT,      KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       JCG,           GMM,           KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       GOLINK,        CRITIQUE,      KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_TRNS,       KC_TRNS,       CHROME_TAB,    KC_TRNS,       CODE_SEARCH,   KC_TRNS,
    KC_TRNS,       BUG,           GMAIL,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
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
    KC_NO,         KC_TRNS,       KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       RESET,         KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_NO,         KC_NO,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
  ),

  [SENSITIVITY_CALIBRATION] = KEYMAP(
    // Left hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       SENS_L_MIN,    SENS_L_LOW,    SENS_L_MED,    SENS_L_HIGH,   KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Left Thumb Cluster
                                                                               KC_TRNS,       KC_TRNS,
                                                                                              KC_TRNS,
                                                                KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right hand
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                   KC_TRNS,       SENS_R_HIGH,   SENS_R_MED,    SENS_R_LOW,    SENS_R_MIN,    OUTPUT_SENS,
    KC_NO,         KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

    // Right Thumb Cluster
    KC_NO,         KC_TRNS,
    KC_TRNS,
    KC_TRNS,       KC_TRNS,       KC_TRNS
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

inline void switch_to_chrome(void) {
  SEND_STRING(SS_LGUI("1"));
}

inline bool key_pressed(uint16_t keycode) {
  return keyboard_report->mods & MOD_BIT(keycode);
}

inline bool shift_pressed(void) {
  return key_pressed(KC_LSHIFT);
}

void prepare_switch_to_tab(const char* s) {
  switch_to_chrome();
  wait_ms(10);
  SEND_STRING(SS_TAP(X_ESCAPE));
  wait_ms(40);
  SEND_STRING(SS_LCTRL("<")); // CTRL SHIFT ,
  wait_ms(80);
  send_string(s);
}

void switch_to_tab(const char* s) {
  prepare_switch_to_tab(s);
  wait_ms(80);
  SEND_STRING(SS_TAP(X_ENTER));
}

inline void prepare_open_tab(const char* s) {
  switch_to_chrome();
  SEND_STRING(SS_LCTRL("t"));
  send_string(s);
}

inline void open_tab(const char* s) {
  prepare_open_tab(s);
  SEND_STRING(SS_TAP(X_ENTER));
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

    case GMAIL:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          switch_to_tab("google calendar");
          register_code(KC_LSHIFT);
        } else {
          switch_to_tab("google mail");
        }
      }
      return false;

    case CRITIQUE:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          open_tab("cl/");
          register_code(KC_LSHIFT);
        } else {
          prepare_switch_to_tab("critique ");
        }
      }
      return false;

    case GMM:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          SEND_STRING("javatests/com/google/android/apps/gmm/");
          register_code(KC_LSHIFT);
        } else {
          SEND_STRING("java/com/google/android/apps/gmm/");
        }
      }
      return false;

    case JCG:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          SEND_STRING("javatests/com/google/");
          register_code(KC_LSHIFT);
        } else {
          SEND_STRING("java/com/google/");
        }
      }
      return false;
      break;

    case CODE_SEARCH:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          prepare_open_tab("c ");
          register_code(KC_LSHIFT);
        } else {
          prepare_switch_to_tab("code search ");
        }
      }
      return false;

    case CHROME_TAB:
      if (record->event.pressed) {
        if (shift_pressed()) {
          unregister_code(KC_LSHIFT);
          prepare_open_tab("");
          register_code(KC_LSHIFT);
        } else {
          prepare_switch_to_tab("");
        }
      }
      return false;

    case GOLINK:
      if (record->event.pressed) {
        prepare_open_tab("go/");
      }
      return false;

    case BUG:
      if (record->event.pressed) {
        open_tab("b/");
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
