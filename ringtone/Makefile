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

HEADERS 		  += player.h lsp_player.h song_player.h

song 			  = assets/rem-loosingmyreligion.txt

build: generate decode

decode:
	./generate $(song)

generate: generate.o
	g++ generate.o -o generate

generate.o: generate.cpp
	g++ generate.cpp -c -Wall -Wmultichar -pedantic -std=c++14

# set BMPTK to the bmptk subdirectory
BMPTK := $(BMPTK)../bmptk/

# Defer to the bmptk/Makefile.inc to do the work
include $(BMPTK)Makefile.inc
