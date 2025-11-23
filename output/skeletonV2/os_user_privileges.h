/*! \file
 * \brief User privileges specification used in part by the task manager.
 *
 * Contains the task manager interface functionality, specifying the respective rights of the
 * current user.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "defines.h"
#include "os_scheduler.h"
#include <avr/pgmspace.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

AccessPermission os_askPermission(PermissionRequest pr , RequestArgument ra , RequestArgumentFlag raf , const char ** reason);
