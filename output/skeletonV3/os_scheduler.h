/*! \file
 * \brief Scheduling module for the OS.
 *
 * Contains the scheduler and process switching functionality for the OS.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_SCHEDULER_H
#define _OS_SCHEDULER_H

#include "defines.h"
#include "os_process.h"
#include <stdbool.h>

//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! The enum specifying which scheduling strategies exist.
typedef enum SchedulingStrategy SchedulingStrategy;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Get a pointer to the process structure by process ID.

//! Starts the scheduler.

//! Executes a process by instantiating a program.

//! Initializes scheduler arrays.

//! Returns the currently active process.

//! Sets the scheduling strategy.

//! Gets the current scheduling strategy.

//! Calculates the checksum of the stack for the corresponding process of pid.

//! Used to kill a running process and clear the corresponding process slot.

//! Enters a critical code section.

//! Leaves a critical code section.

#endif
