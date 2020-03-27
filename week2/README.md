In the c2 folder you will see 2 directories and a file.

- msp432p401r.lds - The linker file you are to use for linking

**‘src’ folder** : contains five source files (*.c)

- Makefile - The makefile you are to edit for the assignment sources.mk - The source file you are to edit for the assignment
- main.c - Main file you are to work with
- memory.c - File that interacts with memory through an IO abstraction interface
- interrupts_msp432p401r_gcc.c - MSP432 specific C-file for interrupts
- startup_msp432p401r_gcc.c - MSP432 specific C-file for startup
- system_msp432p401r.c - MSP432 specific C-file for for system information

**‘include’ folder** : contains the three directories of supporting header files

- **common** - Contains common headers for both platform targets
- **msp432** - Contains MSP432 platform headers
- **CMSIS** - Contains ARM architecture specific headers

Inside the **common** folder, you have been provided a memory.h and a platform.h file. The platform.h file gives you an interface to printf using the macro PRINTF as a mechanism to reduce the dependencies on the stdio.h library.

**Platforms and Flag Support Guidelines**

I made a a make file that support two target platforms and their own specific compilers. These two platforms are the HOST and the MSP432. The host embedded system will use the native compiler, **gcc**. The target embedded system will use the cross compiler, **arm-none-eabi-gcc**. 