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
CONSOLE_BAUDRATE  ?= 9600
STACK_SIZE        ?= 81920
HEAP              ?= BMPTK

# use the rtos
SEARCH            += ../rtos/
HEADERS           += ../rtos/coroutine.hpp ../rtos/switch_to.hpp
SOURCES           += ../rtos/coroutine.cpp ../rtos/switch_to.asm
HEADERS           += ../rtos/rtos.hpp
SOURCES           += ../rtos/rtos.cpp

# use hwlib
SEARCH            += ../hwlib
SOURCES           += ../hwlib/hwlib.cpp

SONG 			  = WEnd:d=4,o=5,b=225:2c,1f,2g.,8g#,8a#,1g#,2c.,c,2f.,g,g#,c,8g#.,8c.,8c6,1a#.,2c,2f.,g,g#.,8f,c.6,8g#,1f6,2f,8g#.,8g.,8f,2c6,8c.6,8g#.,8f,2c,8c.,8c.,8c,2f,8f.,8f.,8f,2f
export SONG

# set BMPTK to the bmptk subdirectory
BMPTK := $(BMPTK)../bmptk/

# Defer to the bmptk/Makefile.inc to do the work
include $(BMPTK)Makefile.inc
