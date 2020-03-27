#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST


GENERAL_FLAGES= -Wall -Werror -g -O0 -std=c99
OUTPUT_FILE = c1m2

ifeq ($(PLATFORM),HOST)
		CC = gcc
		LD =ld
		CFLAGS= $(GENERAL_FLAGES) $(INCLUDES)
else ifeq ($(PLATFORM),MSP432)	
		# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU =cortex-m4
	ARCH = thumb
	SPECS = nosys.specs

	# Compiler Flags and Defines
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	LDFLAGS = -Wl,-Map=$(OUTPUT_FILE).map -T $(LINKER_FILE) 
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m  -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(MSP432_INCLUDES) $(GENERAL_FLAGES)
endif

	CPPFLAGS = -D $(PLATFORM)
	
	OBJS = $(SOURCES:.c=.o)
	PRE = $(SOURCES:.c=.i)
	ASM = $(SOURCES:.c=.asm)
	



%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

%.asm: %.i
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS)  $(LDFLAGS) -o $@
	
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS)   $(LDFLAGS) -o $@ 

.PHONY: build
build: GEN_EXC

.PHONY: compile-all
compile-all : OBJ_GEN

.PHINY : clean
clean : CLEAN

.PHONY : all-files

OBJ_GEN: $(OBJS)

GEN_EXC: $(SOURCES)
	$(CC) $(SOURCES) $(CPPFLAGS) $(CFLAGS)  $(LDFLAGS)-o $(OUTPUT_FILE)

CLEAN : 
	rm -f $(OBJS) $(PRE) $(ASM) $(OUTPUT_FILE)*
	
all-files: $(SOURCES)
	make $(PRE) 
	make $(ASM)
	make compile-all
	make GEN_EXC
	