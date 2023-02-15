SRC += drzoid.c
MANUFACTURER= drzoid

DRZ_USE_LONGPRESS ?= no
ifeq ($(strip $(DRZ_USE_LONGPRESS)), yes)
  LONGPRESS_ENABLE = yes
  SRC += process_longpress.c
endif

DRZ_USE_AUTOCORRECTION ?= no
ifeq ($(strip $(DRZ_USE_AUTOCORRECTION)), yes)
  AUTOCORRECT_ENABLE = yes
endif

DRZ_USE_UNICODE ?= no
ifeq ($(strip $(DRZ_USE_UNICODE)), yes)
  UNICODE_ENABLE = yes
endif

DRZ_USE_RGB_MATRIX ?= no
ifeq ($(strip $(DRZ_USE_RGB_MATRIX)), yes)
  RGB_MATRIX_CUSTOM_USER = yes
endif
