/*! \file
 * \brief Core of the OS.
 *
 * Contains functionality to for core OS operations.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_CORE_H
#define _OS_CORE_H

#include <avr/pgmspace.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

//! Allowed reset sources that are not considered erroneous resetting of the MCU.
#define OS_ALLOWED_RESET_SOURCES(_BV(JTRF) | _BV(BORF) | _BV(EXTRF) | _BV(PORF))

//! Handy define to specify error messages directly.
#define os_error(str) os_errorPStr(PSTR(str))


//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

//! Needed to determine where the heap may start in order not to crush global variables unknowingly.
const uint8_t __heap_start;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Initializes timers.

//! Examines the saved MCU status register and possibly prints an error if the reset source is not allowed.

//! Initializes OS.

//! Shows error on display and terminates program.

#endif
