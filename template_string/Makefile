#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES :=

# header files in this project
HEADERS := template_string.h

# other places to look for files for this project
SEARCH  :=


SERIAL_PORT     ?= COM3


runAvr:
	sudo stty -F /dev/ttyACM0 speed 1200 cs8 -cstopb -parenb && make build && sudo bossac --info --port "ttyACM0" --erase --write --verify --reset --debug --boot -U false ./main.bin && sudo platformio serialports monitor -b 38400
runNative:
	g++ -o template ../Catch/single_include/catch.hpp catch_include.h template_string.h native_test.h main.cpp -std=c++14 && ./template

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due

