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
typedef struct {
    // TODO implement.
} Heap;

//! All available heap allocation strategies.
typedef enum {
    // TODO implement.
} AllocStrategy;


//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

//! The Heap structure for the internal Heap .
Heap intHeap__;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Initialises all Heaps.
void os_initHeaps(void);

//! Needed for Taskmanager interaction.
Heap *os_lookupHeap(uint8_t index);

//! Needed for Taskmanager interaction.
size_t os_getHeapListLength(void);

#endif
