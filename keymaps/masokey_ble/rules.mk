
# CRKBD_BLE keyboard customize
# you can edit following Variables
CRKBD_BLE_ROWS = 4              # CRKBD_BLE Rows is 4
LED_BACK_ENABLE = yes        # LED backlight (Enable WS2812 RGB underlight.)
LED_UNDERGLOW_ENABLE = no   # LED underglow (Enable WS2812 RGB underlight.)
LED_ANIMATIONS = yes        # LED animations

define CRKBD_BLE_CUSTOMISE_MSG
  $(info CRKBD_BLE customize)
  $(info -  OLED_ENABLE=$(OLED_ENABLE))
  $(info -  LED_BACK_ENABLE=$(LED_BACK_ENABLE))
  $(info -  LED_UNDERGLOW_ENABLE=$(LED_UNDERGLOW_ENABLE))
  $(info -  LED_ANIMATION=$(LED_ANIMATIONS))
  $(info -  IOS_DEVICE_ENABLE=$(IOS_DEVICE_ENABLE))
endef

ifneq ($(strip $(CRKBD_BLE_ROWS)), 4)
  ifneq ($(strip $(CRKBD_BLE_ROWS)), 5)
    $(error CRKBD_BLE_ROWS = $(strip $(CRKBD_BLE_ROWS)) is unexpected value)
  endif
endif
OPT_DEFS += -DCRKBD_BLE_ROWS=$(strip $(CRKBD_BLE_ROWS))

ifeq ($(strip $(LED_BACK_ENABLE)), yes)
  RGBLIGHT_ENABLE = yes
  OPT_DEFS += -DRGBLED_BACK
  ifeq ($(strip $(LED_UNDERGLOW_ENABLE)), yes)
    $(eval $(call CRKBD_BLE_CUSTOMISE_MSG))
    $(error LED_BACK_ENABLE and LED_UNDERGLOW_ENABLE both 'yes')
  endif
else ifeq ($(strip $(LED_UNDERGLOW_ENABLE)), yes)
  RGBLIGHT_ENABLE = yes
else
  RGBLIGHT_ENABLE = no
endif

ifeq ($(strip $(LED_ANIMATIONS)), yes)
    OPT_DEFS += -DRGBLIGHT_ANIMATIONS
endif

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend