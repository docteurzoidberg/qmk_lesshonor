ifndef QUANTUM_DIR
	include ../../../../../Makefile
endif


DRZ_USE_UNICODE = yes
DRZ_USE_LONGPRESS = yes

SWAP_HANDS_ENABLE = yes
LEADER_ENABLE = yes

BACKLIGHT_LEVELS = 16
BACKLIGHT_ENABLE = yes
POINTING_DEVICE_ENABLE = no
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no         # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes        # Audio control and System control(+450)
CONSOLE_ENABLE = no          # Console for debug(+400)
COMMAND_ENABLE = no          # Commands for debug and configuration
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
MIDI_ENABLE = no             # MIDI support (+2400 to 4200, depending on config)
AUDIO_ENABLE = no            # Audio output on port C6
UNICODE_ENABLE = yes         # Unicode
BLUETOOTH_ENABLE = no        # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
SLEEP_LED_ENABLE = yes       # Breathing sleep LED during USB suspend
TAPDANCE_ENABLE = yes
AVR_USE_MINIMAL_PRINTF = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
