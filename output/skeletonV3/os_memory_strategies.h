/*! \file
 * \brief Memory allocation library for the OS.
 *
 * Contains the memory allocation strategies for the *malloc routines.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "os_memheap_drivers.h"

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! First-fit strategy.
MemAddr os_Memory_FirstFit(Heap * heap , size_t size);

//! Next-fit strategy.
MemAddr os_Memory_NextFit(Heap * heap , size_t size);

//! Best-fit strategy.
MemAddr os_Memory_BestFit(Heap * heap , size_t size);

//! Worst-fit strategy.
MemAddr os_Memory_WorstFit(Heap * heap , size_t size);
