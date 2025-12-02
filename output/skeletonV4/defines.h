/*! \file
 * \brief Simple definitions and assembler-macros, mostly 8/16-Bit values.
 *
 * All constant values that can be simply parsed into the code at compile time are stored in here.
 * These will reside in program memory at runtime.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _DEFINES_H
#define _DEFINES_H

#include "atmega644constants.h"

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

#define NULL ((void *)0)

//! The current id of the exercise (this must be changed every two weeks).
#define VERSUCH 4

#define MAX_NUMBER_OF_PROCESSES 8

//! Standard priority for newly created processes.
#define DEFAULT_PRIORITY 2

//! Default delay to read display values (in ms)
#define DEFAULT_OUTPUT_DELAY 100

//! Number to specify an invalid process.
#define INVALID_PROCESS 255

//! The stack size available for initialization and globals.
#define STACK_SIZE_MAIN 32

//! The scheduler's stack size.
#define STACK_SIZE_ISR 192

//! The stack size of a process.
#define STACK_SIZE_PROC (((AVR_MEMORY_SRAM / 2) - STACK_SIZE_MAIN - STACK_SIZE_ISR) / MAX_NUMBER_OF_PROCESSES)

//! The bottom of the main stack. That is the highest address.
#define BOTTOM_OF_MAIN_STACK (AVR_SRAM_LAST)

//! The bottom of the scheduler-stack. That is the highest address.
#define BOTTOM_OF_ISR_STACK (BOTTOM_OF_MAIN_STACK - STACK_SIZE_MAIN)

//! The bottom of the memory chunks for all process stacks. That is the highest address.
#define BOTTOM_OF_PROCS_STACK (BOTTOM_OF_ISR_STACK - STACK_SIZE_ISR)

//! The bottom of the memory chunk with number PID.
#define PROCESS_STACK_BOTTOM (PID)(BOTTOM_OF_PROCS_STACK -((PID)* STACK_SIZE_PROC))

//! Offset needed before the Heap starts, because global variables are put on the low addresses of the SRAM.
#define HEAPOFFSET 350

#endif
