#------------------------------------------------------------------------------
# Simple makefile that can compile multiple source files and support two platform targets my Host machine and MSP432 Plateform 
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#       <File>.i - Generate the preprocessed output of all c-program implementation files
#		<File>.asm - Generate assembly output of c-program implementation files and the final output executable
#		<File>.o - Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile.
#		compile-all - Compile all object files, but DO NOT link.
#		Build - Compile all object files and link into a final executable.
#		Clean - This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
#		all-files - Generate all the Comiplation process files and the map file as well the symbol table
# Platform Overrides:
#      PLATFORM - Cross or Native Comiplation ( HOST, MSP432)
#	   OUTPUT_FILE - the name of the last Excubtible file
#	   SRC - the source file as every platform hase it's on platform ( HOST_SRC, MSP432_SRC)
#	   CC - THE COMIPLER TOOL NAME (gcc, arm-none-eabi-gcc )
#	   LD - THE LINKER TOOL NAME (ld,arm-none-eabi-ld)
#	   OBHDUMP - THE OBJECT DUMB TOOL NAME (objdump , arm-none-eabi-objdump )
#	   CFLAGS  - paltform comipler flages
#	   LDFLAGS - paltform LINKER flages
#
3		
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

#Const. Variables at this project
GENERAL_FLAGES= -Wall -Werror -g -O0 -std=c99
OUTPUT_FILE = c1m2.out


ifeq ($(PLATFORM),HOST) #if the the Platform is Host

#the Source Files Names
		SRC= $(HOST_SRC)
#GNU Tool NAMES				
		CC = gcc
		LD =ld
		OBJDUMP = objdump
		
		#Cimpiler Flages for Sitting the Host name
		CFLAGS= $(GENERAL_FLAGES) $(INCLUDES)
		
else ifeq ($(PLATFORM),MSP432)	#if the the Platform is Host
	SRC= $(MSP432_SRC)
		# Architectures Specific Flags
	LINKER_FILE = ../msp432p401r.lds
	CPU =cortex-m4
	ARCH = thumb
	SPECS = nosys.specs

	#GNU Tool NAMES
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	OBJDUMP = arm-none-eabi-objdump
	
	#Comipler and Linker Flages
	LDFLAGS = -Wl,-Map=$(OUTPUT_FILE).map -T $(LINKER_FILE) 
	CFLAGS = -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m  -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) $(MSP432_INCLUDES) $(GENERAL_FLAGES)
	
endif
	
	#Pre Procceseor Flage to Define the Platform 
	CPPFLAGS = -D $(PLATFORM)
	
	#variables list of the source file and all the comiplation procceses file Ext 
	OBJS = $(SRC:.c=.o)
	PRE = $(SRC:.c=.i)
	ASM = $(SRC:.c=.asm)

#my PHONYS

.PHONY: build
build: GEN_EXC

.PHONY: compile-all
compile-all : OBJ_GEN

.PHINY : clean
clean : CLEAN

.PHONY : all-files
	


#My Targets
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS)  $(LDFLAGS) -o $@

%.asm: %.out
	$(OBJDUMP) -d $< >$@
		
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS)   $(LDFLAGS) -o $@ 


OBJ_GEN: $(OBJS)


GEN_EXC: $(SRC)
	$(CC) $(SRC) $(CPPFLAGS) $(CFLAGS)  $(LDFLAGS)-o $(OUTPUT_FILE)


CLEAN : 
	rm -f *.o *.asm *.i $(OUTPUT_FILE)*

	
all-files: $(SOURCES)
	make $(PRE) 
	make $(ASM)
	make compile-all
	make GEN_EXC
	$(OBJDUMP) -t $(OUTPUT_FILE).out > $(OUTPUT_FILE).symbol_table