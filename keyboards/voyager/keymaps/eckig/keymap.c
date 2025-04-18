#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "sendstring_german.h"

// super alt-tab
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  MT_DLR  = SAFE_RANGE + 1,
  MT_EXLM = SAFE_RANGE + 2,
  DEMO    = SAFE_RANGE + 3,
};

#define LT1_ENTER  LT(1,KC_ENTER)
#define LT1_DELETE LT(1,KC_DELETE)
#define LT2_SPACE  LT(2,KC_SPACE)
#define LT2_BSPC   LT(2,KC_BSPC)
#define LT3_C      LT(3,KC_C)
#define MT_CTL_ESC MT(MOD_LCTL, KC_ESCAPE)
#define MT_CTL_MIN MT(MOD_RCTL, DE_MINS)
#define MT_ALT_DLR MT(MOD_LALT, MT_DLR)
#define MT_ALT_EXC MT(MOD_RALT, MT_EXLM)
#define MT_SHIFT_U MT(MOD_LSFT, KC_U)
#define MT_SHIFT_H MT(MOD_RSFT, KC_H)

const custom_shift_key_t custom_shift_keys[] = {
  {DE_SCLN, DE_COLN}, // ; :
  {KC_COMM, DE_LABK}, // , <
  {KC_DOT , DE_RABK}, // . >
  {DE_QUOT, DE_DQUO}, // ' "
  {DE_SLSH, DE_QUES}, // / ?
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    MT_ALT_DLR, KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_NO,                 KC_PSCR, DEMO,       KC_NO,   KC_NO,   KC_NO,   MT_ALT_EXC,
    KC_TAB,     DE_SCLN, KC_COMM, KC_DOT,  KC_P,       DE_Y,                  KC_F,    KC_G,       LT3_C,   KC_R,    KC_L,    DE_SLSH,
    MT_CTL_ESC, KC_A,    KC_O,    KC_E,    MT_SHIFT_U, KC_I,                  KC_D,    MT_SHIFT_H, KC_T,    KC_N,    KC_S,    MT_CTL_MIN,
    KC_LGUI,    DE_QUOT, KC_Q,    KC_J,    KC_K,       KC_X,                  KC_B,    KC_M,       KC_W,    KC_V,    DE_Z,    QK_REP,
                                                 LT2_BSPC, LT1_DELETE,                 LT1_ENTER, LT2_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,                 KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,                 KC_NO,   KC_7,       KC_8,    KC_9,    KC_NO,   KC_TRNS,
    KC_TRNS,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      CW_TOGG,               KC_NO,   KC_4,       KC_5,    KC_6,    KC_NO,   KC_TRNS,
    KC_TRNS,    KC_NO,   KC_NO,   KC_DOWN, KC_UP,      KC_NO,                 KC_NO,   KC_1,       KC_2,    KC_3,    KC_NO,   QK_AREP,
                                                 KC_LEFT,  KC_RIGHT,                   ALT_TAB,   KC_0
  ),
  [2] = LAYOUT_voyager(
    RGB_TOG,TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,KC_NO,RGB_VAD,RGB_VAI,        KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
    KC_TRNS,    DE_DEG,  KC_NO,   KC_NO,   KC_NO,      DE_GRV,                DE_AMPR, DE_LBRC,    DE_RBRC, DE_EURO, KC_NO,   KC_TRNS,
    KC_TRNS,    DE_CIRC, DE_BSLS, DE_PLUS, DE_EQL,     DE_HASH,               DE_PIPE, DE_LPRN,    DE_RPRN, DE_PERC, KC_NO,   KC_TRNS,
    KC_TRNS,    DE_SECT, KC_NO,   DE_ASTR, KC_NO,      KC_NO,                 DE_TILD, DE_LCBR,    DE_RCBR, DE_AT,   KC_NO,   QK_AREP,
                                                 KC_LEFT,  KC_RIGHT,                   KC_HOME,   KC_END
  ),
  [3] = LAYOUT_voyager(
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    DE_ADIA, DE_ODIA, DE_UDIA, DE_SS,      KC_TRNS,               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,               KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 KC_TRNS,  KC_TRNS,                   KC_TRNS,    KC_TRNS
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;

    case MT_ALT_DLR:
      if (record->event.pressed && record->tap.count > 0) {
          tap_code16(DE_DLR);
          return false;
      }
    break;

    case MT_ALT_EXC:
      if (record->event.pressed && record->tap.count > 0) {
          tap_code16(DE_EXLM);
          return false;
      }
    break;

    case MT_CTL_MIN:
      if(record->event.pressed && is_caps_word_on()) {
        tap_code16(DE_UNDS);
        return false;
      }
    break;

    case DEMO:
      if (record->event.pressed) {
        SEND_STRING("admin\tAdmin#123\n");
      }
    break;

  }

  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_A: return C(KC_C);  // Ctrl+A -> Ctrl+C
      case KC_C: return C(KC_V);  // Ctrl+C -> Ctrl+V
      case DE_Y: return C(DE_Z);  // Ctrl+Y -> Ctrl+Z
      case DE_Z: return C(DE_Y);  // Ctrl+Z -> Ctrl+Y
    }
  }
  return KC_TRNS;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 600) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

