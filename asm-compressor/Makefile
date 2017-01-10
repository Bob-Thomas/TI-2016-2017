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
SOURCES := compressed.asm decompress.asm

# header files in this project
HEADERS := 

# other places to look for files for this project
SEARCH  := 

compressed.asm : create-asm.exe wilhelmus.txt
	./create-asm.exe

create-asm.exe : generate-asm.cpp
	g++ -o create-asm.exe generate-asm.cpp -std=c++14

# set BMPTK to the next higher directory and defer to the Makefile.due
BMPTK := $(BMPTK)../
include $(BMPTK)Makefile.due
