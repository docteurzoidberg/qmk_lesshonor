#WARNING avr uc ^^'
#-> disable many stuff as possible for firmware size

#drz custom user files features
DRZ_USE_LONGPRESS = yes
DRZ_USE_MACROS = yes
DRZ_USE_DYNAMICMACROS = no
DRZ_USE_AUTOCORRECTION = no
DRZ_USE_UNICODE = yes
DRZ_USE_SECRETS = yes
DRZ_USE_RGBLIGHT = yes
DRZ_USE_WPM = no

#qmk features
SWAP_HANDS_ENABLE = yes
LEADER_ENABLE = yes
TAPDANCE_ENABLE = yes
EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)
KEY_LOCK_ENABLE = yes

#board
SLEEP_LED_ENABLE = yes       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = yes
BACKLIGHT_LEVELS = 16

#disable
POINTING_DEVICE_ENABLE = no
MOUSEKEY_ENABLE = no         # Mouse keys(+4700)
COMMAND_ENABLE = no          # Commands for debug and configuration
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

#free spaaaaaaace
AVR_USE_MINIMAL_PRINTF = yes
LTO_ENABLE = yes
