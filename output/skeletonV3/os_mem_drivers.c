/*! \file
 *
 * Memory Driver structs and their functions. Note that all handy defines used to implement the
 * driver functions are hidden in the public version of this documentation.
 *
 */

#include "os_mem_drivers.h"
#include "defines.h"

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * This specific MemDriver is initialised in os_mem_drivers.c .
 */
MemDriver intSRAM__;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Pseudo-function to initialise the internal SRAM Actually, there is nothing to be done when
 * initialising the internal SRAM, but we create this function, because MemDriver expects one for
 * every memory device.
 */
void initSRAM_internal(void) {
    // TODO implement.
}

/*!
 * Returns The read value
 *
 * @param addr     The address to read the value from
 */
MemValue readSRAM_internal(MemAddr addr) {
    // TODO implement.
}

/*!
 * Private function to write a value to the internal SRAM It will not check if its call is valid.
 * This has to be done on a higher level.
 *
 * @param addr     The address the value shall be written to
 * @param value    The value to be written
 */
void writeSRAM_internal(MemAddr addr , MemValue value) {
    // TODO implement.
}

/*!
 * Initialise all memory devices.
 */
void initMemoryDevices(void) {
    // TODO implement.
}
