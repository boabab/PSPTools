/*! \file
 * \brief Struct specifying a process.
 *
 * Contains the struct that bundles all properties of a running process.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_PROCESS_H
#define _OS_PROCESS_H

#include <stdbool.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

#define REGISTER_AUTOSTART(PROGRAM_FUNCTION)


//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! The type for the ID of a running process.
typedef uint8_t ProcessID;

//! This is the type of a program function (not the pointer to one!).
typedef void Program(void);

//! The type of the priority of a process.
typedef uint8_t Priority;

//! The age of a process (scheduler specific property).
typedef uint16_t Age;

//! The type for the checksum used to check stack consistency.
typedef uint8_t StackChecksum;

//! Type for the state a specific process is currently in.
typedef enum {
    // TODO implement.
} ProcessState;

typedef union {
    // TODO implement.
} StackPointer;

typedef struct {
    // TODO implement.
} Process;

//! Type for the state a specific process is currently in.
typedef enum {
    // TODO implement.
} ProcessState;


//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

struct program_linked_list_node * autostart_head extern;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Returns whether the passed process can be selected to run.
bool os_isRunnable(const Process *process);

#endif
