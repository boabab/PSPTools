/*! \file
 *
 * Everything that is necessary to get the input from the Buttons in a clean format.
 *
 */

#include "os_input.h"
#include <avr/io.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * A simple "Getter"-Function for the Buttons on the evaluation board. Returns The state of the
 * button(s) in the lower bits of the return value. example: 1 Button: -pushed: 00000001 -released:
 * 00000000 4 Buttons: 1,3,4 -pushed: 000001101
 */
uint8_t os_getInput(void) {
    // TODO implement.
}

/*!
 * Initializes DDR and PORT for input
 */
void os_initInput(void) {
    // TODO implement.
}

/*!
 * Endless loop as long as at least one button is pressed.
 */
void os_waitForNoInput(void) {
    // TODO implement.
}

/*!
 * Endless loop until at least one button is pressed.
 */
void os_waitForInput(void) {
    // TODO implement.
}
