#############################################################################
#
# makefile.due common settings for Arduino Due projects
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# settings for Arduino Due projects
TARGET            ?= arduino_due
SERIAL_PORT       ?= COM2
CONSOLE_BAUDRATE  ?= 38400
STACK_SIZE        ?= 81920
HEAP              ?= BMPTK

# use hwlib
SEARCH            += hwlib
SOURCES           += hwlib/hwlib.cpp

# use the rtos
SEARCH            += rtos/
HEADERS           += rtos/coroutine.hpp rtos/switch_to.hpp
SOURCES           += rtos/coroutine.cpp rtos/switch_to.asm
HEADERS           += rtos/rtos.hpp
SOURCES           += rtos/rtos.cpp

# set BMPTK to the bmptk subdirectory
BMPTK := $(BMPTK)bmptk/

# Defer to the bmptk/Makefile.inc to do the work
include $(BMPTK)Makefile.inc
