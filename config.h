/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Sekigon

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define ENABLE_STARTUP_ADV_NOLIST

/* #ifndef CONFIG_H */
#define CONFIG_H

#define BLE_NUS_MIN_INTERVAL  30  // default 
#define BLE_NUS_MAX_INTERVAL  70  // 左右間の通信間隔(ms)　下げると消費電力が増える。default 70
#define BLE_HID_MAX_INTERVAL  80  // 端末との通信間隔(ms)　下げると消費電力が増える。default 90
#define BLE_HID_SLAVE_LATENCY  4  // 端末との通信パラメータ　下げると消費電力が増える。default  4

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define MANUFACTURER    foostan
#define PRODUCT         Crkbd Cherry
#define DESCRIPTION     A split keyboard with 3x6 vertically staggered keys and 3 thumb keys

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

//#define LAYOUT LAYOUT_CRKBD
#define LAYOUT LAYOUT_kc

#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE    1

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

#define PROGMEM // arm-gcc does not interpret PROGMEM
#define RGB_DI_PIN 1     // The pin the LED strip is connected to
#ifdef RGBLED_BACK
#define RGBLED_NUM 27

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
