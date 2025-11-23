/*! \file
 * \brief Drivers for OS heap management.
 *
 * Contains management of several logical heaps, each associated with one MemDriver .
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_MEMHEAP_DRIVERS_H
#define _OS_MEMHEAP_DRIVERS_H

#include "os_mem_drivers.h"
#include <stddef.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

//! Realises a pointer to the Heap intHeap__.
#define intHeap(& intHeap__)


//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! The structure of a heap driver which consists of a low level memory driver and heap specific information such as start, size etc...
typedef struct Heap Heap;


//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

//! The Heap structure for the internal Heap .
Heap intHeap__;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Initialises all Heaps.

//! Needed for Taskmanager interaction.

//! Needed for Taskmanager interaction.

#endif
