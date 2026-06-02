#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _GAME,
    _ADJUST,
};

enum {
    TD_CTRL_GUI,
    TD_LOW_LOFF,
    TD_RAIS_LON,
};

typedef enum { TD_NONE, TD_UNKNOWN, TD_SINGLE_TAP, TD_SINGLE_HOLD, TD_DOUBLE_TAP } td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void td_lower_lang_off_finished(tap_dance_state_t *state, void *user_data);
void td_lower_lang_off_reset(tap_dance_state_t *state, void *user_data);
void td_raise_lang_on_finished(tap_dance_state_t *state, void *user_data);
void td_raise_lang_on_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | CTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |      |      |      |      |      |      |   [   |    |    ]  |      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | GUI  | LALT |LOWER | /Space  /       \Enter \  |RAISE |BackSP| DEL  |
     *                   |      |      |IMEOFF|/       /         \      \ |IMEON |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                           KC_LGUI, KC_LALT, TD(TD_LOW_LOFF),  KC_SPC,  KC_ENT,  TD(TD_RAIS_LON), KC_BSPC, KC_DEL
        ),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |      |      |      |      |      |      |   [   |    |    ]  |      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______
        ),
    /* RAISE
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   =  |   +  |   -  |   *  |   /  |   \  |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_EQL,  KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_BSLS,
                                   _______, _______, _______, _______, _______, _______, _______, _______
        ),

    /* GAME
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |CTRL  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |      |      |      |      |      |      |   [   |    |    ]  |      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______
        ),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      | BRIU |      |                    |      | VOL- | MUTE | VOL+ |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      | BRID |GAME  |-------.    ,-------|      | PREV | PLAY | NEXT |      |      |
     * |      |      |      |      |      |      |                    |      |      | PAUSE|      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX,                   XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, TG(_GAME),                 XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, _______, _______, _______, _______
        ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed)
            return TD_SINGLE_TAP;
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2)
        return TD_DOUBLE_TAP;
    else
        return TD_UNKNOWN;
}

static td_tap_t td_lower_lang_off_tap_state = {.is_press_action = true, .state = TD_NONE};

static td_tap_t td_raise_lang_on_tap_state = {.is_press_action = true, .state = TD_NONE};

void td_lower_lang_off_finished(tap_dance_state_t *state, void *user_data) {
    td_lower_lang_off_tap_state.state = cur_dance(state);
    switch (td_lower_lang_off_tap_state.state) {
        case TD_DOUBLE_TAP:
            tap_code(KC_LNG1);
            break;
        default:
            layer_on(_LOWER);
            break;
    }
}

void td_lower_lang_off_reset(tap_dance_state_t *state, void *user_data) {
    // if (td_lower_lang_off_tap_state.state == TD_SINGLE_HOLD) {
    layer_off(_LOWER);
    // }
    td_raise_lang_on_tap_state.state = TD_NONE;
}

void td_raise_lang_on_finished(tap_dance_state_t *state, void *user_data) {
    td_raise_lang_on_tap_state.state = cur_dance(state);
    switch (td_raise_lang_on_tap_state.state) {
        case TD_DOUBLE_TAP:
            tap_code(KC_LNG2);
            break;
        default:
            layer_on(_RAISE);
            break;
    }
}

void td_raise_lang_on_reset(tap_dance_state_t *state, void *user_data) {
    // if (td_raise_lang_on_tap_state.state == TD_SINGLE_HOLD) {
    layer_off(_RAISE);
    // }
    td_raise_lang_on_tap_state.state = TD_NONE;
}
tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRL_GUI] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_LGUI),
    [TD_LOW_LOFF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_lower_lang_off_finished, td_lower_lang_off_reset),
    [TD_RAIS_LON] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_raise_lang_on_finished, td_raise_lang_on_reset),
};
