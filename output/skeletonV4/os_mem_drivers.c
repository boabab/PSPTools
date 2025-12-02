/*! \file
 *
 * Memory Driver structs and their functions. Note that all handy defines used to implement the
 * driver functions are hidden in the public version of this documentation.
 *
 */

#include "os_mem_drivers.h"
#include "defines.h"
#include "os_scheduler.h"
#include "os_spi.h"
#include "util.h"
#include <avr/interrupt.h>
#include <avr/io.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * This specific MemDriver is initialised in os_mem_drivers.c .
 */
MemDriver intSRAM__;

/*!
 * This specific MemDriver is initialised in os_mem_drivers.c .
 */
MemDriver extSRAM__;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Activates the external SRAM as SPI slave.
 */
void select_memory() {
    // TODO implement.
}

/*!
 * Deactivates the external SRAM as SPI slave.
 */
void deselect_memory() {
    // TODO implement.
}

/*!
 * Sets the operation mode of the external SRAM.
 *
 * @param mode     The desired operation mode
 */
void set_operation_mode(uint8_t mode) {
    // TODO implement.
}

/*!
 * Transmitts a 24bit memory address to the external SRAM.
 *
 */
void transfer_address(MemAddr addr) {
    // TODO implement.
}

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
void writeSRAM_internal(MemAddr addr, MemValue value) {
    // TODO implement.
}

/*!
 * Initialisation of the external SRAM board. This function performs actions such as setting the
 * respective Data Direction Register etc..
 */
void initSRAM_external(void) {
    // TODO implement.
}

/*!
 * Returns The read value
 *
 * @param addr     The address to read the value from
 */
MemValue readSRAM_external(MemAddr addr) {
    // TODO implement.
}

/*!
 * Private function to write a single byte to the external SRAM It will not check if its call is
 * valid. This has to be done on a higher level.
 *
 * @param addr     The address to write to
 * @param value    The value to be written
 */
void writeSRAM_external(MemAddr addr, MemValue value) {
    // TODO implement.
}

/*!
 * Initialise all memory devices.
 */
void initMemoryDevices(void) {
    // TODO implement.
}
