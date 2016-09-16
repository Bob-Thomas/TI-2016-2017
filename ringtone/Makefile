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

# use hwlib
SEARCH            += ../hwlib
SOURCES           += ../hwlib/hwlib.cpp

HEADERS 		  += player.h lsp_player.h song_player.h

song 			  = assets/ymca.txt
#song 			  = Poison:d=4,o=5,b=112:8d,8d,8a,8d,8e6,8d,8d6,8d,8f\#,8g,8c6,8f\#,8g,8c6,8e,8d,8d,8d,8a,8d,8e6,8d,8d6,8d,8f\#,8g,8c6,8f\#,8g,8c6,8e,8d,8c,8d,8a,8d,8e6,8d,8d6,8d,8f\#,8g,8c6,8f\#,8g,8c6,8e,8d,8c,8d,8a,8d,8e6,8d,8d6,8d,8a,8d,8e6,8d,8d6,8d,2a,8d

clean: project

project:
	rm *.o

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
