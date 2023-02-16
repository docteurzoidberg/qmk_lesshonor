SRC += drzoid.c
MANUFACTURER= drzoid

DRZ_USE_LONGPRESS ?= no
ifeq ($(strip $(DRZ_USE_LONGPRESS)), yes)
  SRC += process_longpress.c
  OPT_DEFS += -DDRZ_LONGPRESS_ENABLED
endif

DRZ_USE_AUTOCORRECTION ?= no
ifeq ($(strip $(DRZ_USE_AUTOCORRECTION)), yes)
  AUTOCORRECT_ENABLE = yes
  OPT_DEFS += -DDRZ_AUTOCORRECT_ENABLED
endif

DRZ_USE_UNICODE ?= no
ifeq ($(strip $(DRZ_USE_UNICODE)), yes)
  UNICODE_ENABLE = yes
  OPT_DEFS += -DDRZ_UNICODE_ENABLED
endif

DRZ_USE_RGB_MATRIX ?= no
ifeq ($(strip $(DRZ_USE_RGB_MATRIX)), yes)
  RGB_MATRIX_CUSTOM_USER = yes
  OPT_DEFS += -DDRZ_RGBMATRIX_ENABLED
endif
