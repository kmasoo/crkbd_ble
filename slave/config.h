#ifndef SLAVE_CONFIG_H_
#define SLAVE_CONFIG_H_

#include "custom_board.h"

#define MATRIX_ROW_PINS { PIN7, PIN8, PIN9, PIN10 }
#define MATRIX_COL_PINS { PIN20, PIN19, PIN18, PIN17, PIN16, PIN15, PIN14 }

#define IS_LEFT_HAND  false

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLIGHT_TIMER
#define RGBLED_NUM 12    // Number of LEDs
#define ws2812_PORTREG  PORTD
#define ws2812_DDRREG   DDRD

#endif /* SLAVE_CONFIG_H_ */
