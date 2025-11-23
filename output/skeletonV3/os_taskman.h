/*! \file
 * \brief TaskManager library for the OS.
 *
 * Contains the user controlled task manager functionality.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include <stdbool.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Main loop for the TaskManager.
void os_taskManMain(void);

//! Returns true if the TaskManager is currently open.
bool os_taskManOpen(void);
