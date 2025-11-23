/*! \file
 * \brief Little helpers that don't fit elsewhere.
 *
 * Tools, Utilities and other useful stuff that we didn't bother to categorize.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _UTIL_H
#define _UTIL_H

#include <avr/pgmspace.h>
#include <stdbool.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

//! Handy define to specify assert calls directly (without PSTR(..))
#define assert(exp, errormsg) assertPstr(exp, PSTR(errormsg))

//! Saves the register context on the stack.
#define saveContext()

//! Restores the register context on the stack.
#define restoreContext()


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Resets system time back to 0.

//! Coarse system time in ms.

//! Precise system time in ms.

//! Waits for some milliseconds.

//! Simple assertion function that calls os_error if given expression is not true.
bool assertPstr(bool exp, const char *errormsg);

#endif
