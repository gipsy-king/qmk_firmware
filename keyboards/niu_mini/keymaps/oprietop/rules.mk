AUDIO_ENABLE = no
CONSOLE_ENABLE = no
UNICODE_ENABLE = no
RGBLIGHT_ENABLE = yes
BACKLIGHT_ENABLE = yes
MOUSEKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = no
TAP_DANCE_ENABLE = yes

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
