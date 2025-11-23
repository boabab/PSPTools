/*! \file
 * \brief Library for OS memory management.
 *
 * Contains heap management functionality for the OS.
 *
 */

#ifndef _OS_MEMORY_H
#define _OS_MEMORY_H

#include "os_mem_drivers.h"
#include "os_memheap_drivers.h"
#include "os_scheduler.h"

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Function used to allocate private memory.

//! Function used by processes to free their own allocated memory.

//! Frees the chunk iff it is owned by the given owner.

//! Function used to get the value of a single map entry, this is made public so the allocation strategies can use it.

//! Function that realises the garbage collection.

//! Get the size of the heap-map.

//! Get the size of the usable heap.

//! Get the start of the heap-map.

//! Get the start of the usable heap.

//! Get the size of a chunk on a given address.

//! Get the address of the first byte of chunk.

//! Changes the memory management strategy.

//! Returns the current memory management strategy.

#endif
