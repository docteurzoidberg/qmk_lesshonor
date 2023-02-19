SRC += drzoid.c
MANUFACTURER= drzoid

DRZ_USE_SECRETS ?= yes
ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += $(USER_PATH)/secrets.c
  OPT_DEFS += -DDRZ_SECRETS_ENABLED
endif

DRZ_USE_LONGPRESS ?= yes
ifeq ($(strip $(DRZ_USE_LONGPRESS)), yes)
  SRC += $(USER_PATH)/process_longpress.c
  OPT_DEFS += -DDRZ_LONGPRESS_ENABLED
endif

DRZ_USE_MACROS ?= yes
ifeq ($(strip $(DRZ_USE_MACROS)), yes)
  OPT_DEFS += -DDRZ_MACROS_ENABLED
endif

DRZ_USE_DYNAMICMACROS ?= yes
ifeq ($(strip $(DRZ_USE_DYNAMICMACROS)), yes)
  DYNAMIC_MACRO_ENABLE = yes
  OPT_DEFS += -DDRZ_DYNAMICMACROS_ENABLED
endif

DRZ_USE_AUTOCORRECTION ?= yes
ifeq ($(strip $(DRZ_USE_AUTOCORRECTION)), yes)
  AUTOCORRECT_ENABLE = yes
  OPT_DEFS += -DDRZ_AUTOCORRECT_ENABLED
endif

DRZ_USE_UNICODE ?= yes
ifeq ($(strip $(DRZ_USE_UNICODE)), yes)
  UNICODE_ENABLE = yes
  OPT_DEFS += -DDRZ_UNICODE_ENABLED
endif

DRZ_USE_RGBMATRIX ?= no
ifeq ($(strip $(DRZ_USE_RGBMATRIX)), yes)
  RGB_MATRIX_CUSTOM_USER = yes
  OPT_DEFS += -DDRZ_RGBMATRIX_ENABLED
endif

DRZ_USE_RGBLIGHT ?= no
ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	ifeq ($(strip $(DRZ_USE_RGBLIGHT)), yes)
		SRC += $(USER_PATH)/rgb_light.c
		OPT_DEFS += -DDRZ_RGBLIGHT_ENABLED
	endif
endif

DRZ_USE_WPM ?= yes
ifeq ($(strip $(DRZ_USE_WPM)), yes)
  WPM_ENABLE = yes
  OPT_DEFS += -DDRZ_WPM_ENABLED
endif
