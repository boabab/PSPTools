/*! \file
 * \brief User privileges specification used in part by the task manager.
 *
 * Contains the task manager interface functionality, specifying the respective rights of the
 * current user.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_USER_PRIVILEGES_H
#define _OS_USER_PRIVILEGES_H

#include "defines.h"
#include "os_scheduler.h"
#include <avr/pgmspace.h>
#include <stdint.h>
#include "os_memory.h"

//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! The response value that answers a permission request.
typedef enum {
    // TODO implement.
} AccessPermission;

typedef enum {
    // TODO implement.
} PermissionRequest;

//! Which member of the RequestArgument is set.
typedef enum {
    // TODO implement.
} RequestArgumentFlag;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

AccessPermission os_askPermission(PermissionRequest pr, RequestArgument ra, RequestArgumentFlag raf, const char **reason);

#endif
