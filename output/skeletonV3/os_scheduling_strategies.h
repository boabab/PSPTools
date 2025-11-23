/*! \file
 * \brief Scheduling library for the OS.
 *
 * Contains the scheduling strategies.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_SCHEDULING_STRATEGIES_H
#define _OS_SCHEDULING_STRATEGIES_H

#include "defines.h"
#include "os_scheduler.h"

//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! Structure used to store specific scheduling informations such as a time slice.
typedef struct SchedulingInformation SchedulingInformation;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Used to reset the SchedulingInfo for one process.

//! Used to reset the SchedulingInfo for a strategy.

//! Even strategy.

//! Random strategy.

//! RoundRobin strategy.

//! InactiveAging strategy.

//! RunToCompletion strategy.

#endif
