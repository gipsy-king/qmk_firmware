#include QMK_KEYBOARD_H

// Allow printing version info
#include "version.h"

// Layers
#define _QWERTY 0
#define _COLEMDH 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 16
// Aliases
#define KC_     KC_TRNS
#define KC_XXXX KC_NO
#define KC_QWER TG(_QWERTY)
#define KC_COLH TG(_COLEMDH)
#define KC_ADJU MO(_ADJUST)
#define KC_RST  RESET
#define KC_DBUG DEBUG
// Shift when held, Backspace  when tapped
#define KC_LSBS LSFT_T(KC_BSPC)
#define KC_RSBS RSFT_T(KC_BSPC)
// Shift when held, Enter when tapped
#define KC_LSEN LSFT_T(KC_ENT)
#define KC_RSEN RSFT_T(KC_ENT)
// Lower when held, Space when tapped
#define KC_LOSP LT(_LOWER, KC_SPC)
// Alt when held, Tab when tapped
#define KC_ALTA LALT_T(KC_TAB)
// Raise when held, Delete when tapped
#define KC_RADE LT(_RAISE, KC_DEL)
// Cut/Paste shortcuts
#define KC_CPY LCTL(KC_INS)
#define KC_PST RSFT(KC_INS)
#define KC_CUT LSFT(KC_DEL)

// Macros
enum custom_keycodes {
  KC_VER = SAFE_RANGE,
  KC_PULL,
  KC_PUSH,
  KC_LS,
  KC_INCL
};

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,QUOT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSBS, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,RSEN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, Z  , X  , C  , V  , B  ,                N  , M  ,COMM,DOT ,SLSH,RGUI,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                         ALTA,LOSP,               RSBS,RADE
  //                    `----+----'              `----+----'
  ),

  [_COLEMDH] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , F  , P  , B  ,                J  , L  , U  , Y  ,SCLN,QUOT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSBS, A  , R  , S  , T  , G  ,                M  , N  , E  , I  , O  ,RSEN,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LCTL, Z  , X  , C  , D  , V  ,                K  , H  ,COMM,DOT ,SLSH,RGUI,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                         ALTA,LOSP,               RSBS,RADE
  //                    `----+----'              `----+----'
  ),

  [_LOWER] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,F11 ,F12 ,WH_U,CUT ,PST ,               BTN1,MS_U,BTN2,BTN3,PGUP,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,HOME,WH_L,WH_D,WH_R,INS ,               MS_L,MS_D,MS_R, UP ,PGDN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,END ,ACL0,ACL1,ACL2,DEL ,               HOME,END ,LEFT,DOWN,RGHT,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,    ,               ENT ,
  //                    `----+----'              `----+----'
  ),

  [_RAISE] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,F11 ,F12 ,MPRV,MNXT,VOLU,               TILD,UNDS,PLUS,LCBR,RCBR,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,MSTP,MPLY,VOLD,               GRV ,MINS,EQL ,LBRC,RBRC,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MUTE,INCL,PULL,PUSH,LS  ,               BSLS,PIPE,    ,    ,    ,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                         ADJU,    ,                   ,
  //                    `----+----'              `----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     RST ,QWER,COLH,VER ,    ,    ,               DBUG,    ,    ,    ,    ,PSCR,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DBUG,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     CAPS,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,CAPS,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //`----+----+----+----+----+----|              |----+----+----+----+----+----'
                             ,    ,                   ,
  //                    `----+----'              `----+----'
  )

};

// Macros
// Sendstring keycodes: https://github.com/qmk/qmk_firmware/blob/master/quantum/send_string_keycodes.h
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case KC_INCL:
        SEND_STRING("#include <>"SS_TAP(X_LEFT));
        return false;
      case KC_PULL:
        SEND_STRING("git pull"SS_TAP(X_ENTER));
        return false;
      case KC_PUSH:
        SEND_STRING("git push"SS_TAP(X_ENTER));
        return false;
      case KC_LS:
        SEND_STRING("ls -la"SS_TAP(X_ENTER));
        return false;
      case KC_VER:
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
        return false;
    }
  }
  return true;
};

// Change the receiver led
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);
  switch (layer) {
    case _QWERTY:
      set_led_green;
      break;
    case _COLEMDH:
      set_led_green;
      break;
    case _LOWER:
      set_led_blue;
      break;
    case _RAISE:
      set_led_red;
      break;
    case _ADJUST:
      set_led_magenta;
  }
};
