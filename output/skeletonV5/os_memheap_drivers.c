/*! \file
 *
 * Heap Driver structs and some initialisation functions. Some small functions needed by the
 * Taskmanager are also placed here. Note that some instantiations are hidden in the public version
 * of this documentation
 *
 */

#include "os_memheap_drivers.h"
#include "defines.h"
#include "os_memory_strategies.h"
#include <avr/pgmspace.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * The Heap structure for the internal Heap .
 */
Heap intHeap__;

/*!
 * The Heap structure for the external Heap .
 */
Heap extHeap__;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * This function clears the Heapmap of a specific heap.
 *
 * @param heap     The heap to be initialised
 */
void os_initHeap(Heap *heap) {
    // TODO implement.
}

/*!
 * Initialises all Heaps. This function clears the Heapmap of all Heaps used by the OS.
 */
void os_initHeaps(void) {
    // TODO implement.
}

/*!
 * Function needed by the Taskmanager, returns a Heap depending on which index was passed. Returns
 * Returns the heap that corresponds to the given index (e.g intHeap if the index was 0)
 *
 * @param index    Index of the desired Heap
 */
Heap *os_lookupHeap(uint8_t index) {
    // TODO implement.
}

/*!
 * Function needed by the Taskmanager, returns the number of Heaps. Returns The number of Heaps
 * existing, e.g. 1 if there is only the intHeap
 */
size_t os_getHeapListLength(void) {
    // TODO implement.
}
