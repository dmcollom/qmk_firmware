#pragma message "You may need to add LAYOUT_planck_grid to your keymap layers - see default for an example"
#include "planck.h"
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

enum planck_layers {
    _DVORAK,
    _QWERTY,
    _NUMBERS,
    _SYMBOLS,
    _NAVIGATION,
    _ACTIONS
  };

enum planck_keycodes {
    DVORAK,
    QWERTY,
    NUMBERS,
    SYMBOLS,
    NAVIGATION,
    ACTIONS
};

enum tap_dance_codes {
    CT_SC_LP = 0,
    CT_Q_LBRC,
    CT_J_LBRK,
    CT_W_RBRK,
    CT_V_RBRC,
    CT_Z_RP,
    CT_DEL_ESC
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    //keyevent_t event = record->event;

    switch (id) {

    }
    return MACRO_NONE;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [0] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_LPRN),
    [1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_LCBR),
    [2] = ACTION_TAP_DANCE_DOUBLE(KC_J, KC_LBRC),
    [3] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_RBRC),
    [4] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_RCBR),
    [5] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_RPRN),
    [6] = ACTION_TAP_DANCE_DOUBLE(KC_Z, KC_LPRN),
    [7] = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_LCBR),
    [8] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_LBRC),
    [9] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_RBRC),
    [10] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_RCBR),
    [11] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_RPRN),
};


// TODO:
// Make LShift a 3-tap toggle to Qwerty/Dvorak
// Move paren/brace/bracket to ueo and htn going in to out starting with paren
// Make Number + Symbol go to actions
// Remove Dvorak/Qwerty toggle from actions layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Dvorak
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |  '"  |  ,<  |  .>  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  BS  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /?  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |LShift| ;:/( |  Q/{ |  J/[ |   K  |   X  |   B  |   M  |  W/] |  V/} |  Z/) |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Action| Ctrl |  GUI | Alt  |Number|    Space    |Symbol| Left | Down |  Up  | Right|
    * `-----------------------------------------------------------------------------------'
    */
    [_DVORAK] = LAYOUT_planck_grid(
        KC_TAB,        KC_QUOT,    KC_COMM,    KC_DOT,     KC_P,   KC_Y,      KC_F,        KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPACE,
        KC_ESC,        KC_A,       KC_O,       KC_E,       KC_U,   KC_I,      KC_D,        KC_H,   KC_T,    KC_N,    KC_S,  KC_SLASH,
        KC_LSFT,       TD(0),      TD(1),      TD(2),      KC_K,   KC_X,      KC_B,        KC_M,   TD(3),   TD(4),   TD(5), MT(MOD_RSFT, KC_ENT),
        MO(NAVIGATION),   KC_LCTRL,   KC_LGUI,    KC_LALT,    NUMBERS,    KC_SPACE, KC_SPACE,         SYMBOLS,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    ),

    /* QWERTY
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |  E   |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  BS  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ;:  |  '"  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |LShift|  Z/( |  X/{ |  C/[ |   V  |   B  |   N  |   M  | ,</] | .>/} | /?/) |RS/Ent|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |Action| Ctrl |  GUI | Alt  |Number|    Space    |Symbol| Left | Down |  Up  | Right|
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_TAB,        KC_Q,    KC_W,    KC_E,     KC_R,   KC_T,      KC_Y,        KC_U,   KC_I,    KC_O,    KC_P,  KC_BSPACE,
        KC_ESC,        KC_A,       KC_S,       KC_D,       KC_F,   KC_G,      KC_H,        KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
        KC_LSFT,       TD(6),      TD(7),      TD(8),      KC_K,   KC_X,      KC_B,        KC_M,   TD(9),   TD(10),   TD(11), MT(MOD_RSFT, KC_ENT),
        MO(NAVIGATION),   KC_LCTRL,   KC_LGUI,    KC_LALT,    NUMBERS,    KC_SPACE, KC_SPACE,         SYMBOLS,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    ),

    /* Numbers - Triggered by left modifier key
    * ,-----------------------------------------------------------------------------------.
    * |      |  F9  |  F10 |  F11 |  F12 |      |      |   7  |   8  |   9  |   *  |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |      |      |   4  |   5  |   6  |   -  |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |      |      |   1  |   2  |   3  |   +  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   0  |   0  |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUMBERS] = LAYOUT_planck_grid(
        _______,   KC_F9,      KC_F10,      KC_F11,      KC_F12,      _______,      _______,      KC_7,       KC_8,       KC_9,       KC_KP_ASTERISK, _______,
        _______,   KC_F5,      KC_F6,      KC_F7,      KC_F8,     _______,     _______,     KC_4,       KC_5,       KC_6,       KC_KP_MINUS,    _______,
        _______,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    _______,    _______,    KC_1,       KC_2,       KC_3,       KC_KP_PLUS,     _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       KC_0,       _______,    _______,        _______,
    ),

    /* Symbols - Triggered by right modifier key
    * ,-----------------------------------------------------------------------------------.
    * | `~   |  !   |  @   |  #   |   $  |   %  |   ^  |   &  |   *  |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   _  |   +  |      |      |  \|  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |   -  |   =  |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_SYMBOLS] = LAYOUT_planck_grid(
        KC_GRV,    KC_EXCLAIM, KC_AT,      KC_HASH,    KC_DOLLAR,  KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    _______,    _______,    _______,
        _______,   _______,    _______,     _______,    _______,    _______,    _______,    KC_UNDS,    KC_PLUS,    _______,    _______,    KC_BSLS,
        _______,   _______,    _______,     _______,    _______,    _______,    _______,    KC_MINUS,   KC_EQL,     _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    ),


    /* Navigation - Triggered by far left modifier key
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      | Home |  Up  | End  |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      | PgUp | Left | Down | Right|      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      | PgDn |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_NAVIGATION] = LAYOUT_planck_grid(
        _______,    _______, _______,      _______,    _______,  _______,    _______,    KC_HOME,    KC_UP,    KC_END,    _______,    _______,
        _______,   _______,    _______,     _______,    _______,    _______,    KC_PGUP,    KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,    _______,
        _______,   _______,    _______,     _______,    _______,    _______,    KC_PGDN,    _______,   _______,     _______,    _______,    _______,
        _______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    ),


    /* Actions - Triggered by left and right modifiers
    * ,-----------------------------------------------------------------------------------.
    * |  LED |      |      |      |      | Sleep|Reset |      |      |      |      | Del  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      | Undo | Redo |      |      |      |      |      | Play |  <<  |  >>  |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | Cut  | Copy | Paste|      |      |      |      | Mute | Vol- | Vol+ |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |Dvorak|QWERTY|      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ACTIONS] = LAYOUT_planck_grid(
        BL_STEP,   _______,    _______,    _______,    _______,    KC_SLEP,    RESET,      _______,    _______,    _______,    _______,    KC_DEL,
        _______,   LCTL(KC_Z),     LCTL(KC_Y),     _______,    _______,    _______,    _______,    _______,    KC_MPLY,    KC_MPRV,    KC_MNXT,    _______,
        _______,   LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     _______,    _______,    _______,    _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,
        _______,   _______,    _______,    _______,    _______,    DF(0),    DF(1),    _______,    _______,    _______,    _______,    _______,
    ),

    /* Special
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    // [_SPECIAL] = {
    //     {_______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
    //     {_______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
    //     {_______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
    //     {_______,   _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______},
    // }
};

static bool symbols_down = false;
static bool number_down = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case DVORAK:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_DVORAK);
        }
        return false;
        break;
      case QWERTY:
        if (record->event.pressed) {
          set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
      case SYMBOLS:
        if (record->event.pressed) {
          layer_on(_SYMBOLS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        } else {
          layer_off(_SYMBOLS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        }

        return false;
        break;
      case NUMBERS:
        if (record->event.pressed) {
          layer_on(_NUMBERS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        } else {
          layer_off(_NUMBERS);
          update_tri_layer(_NUMBERS, _SYMBOLS, _SPECIAL);
        }
        return false;
        break;
    }
    return true;
}
