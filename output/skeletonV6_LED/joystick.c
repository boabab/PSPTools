/*! \file
 * \brief Functions to access joystick.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "joystick.h"
#include <avr/io.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Initialize joystick registers.
 */
void js_init() {
    // TODO implement.
}

/*!
 * Getter for the joystick button state.
 */
bool js_getButton() {
    // TODO implement.
}

/*!
 * Blocks until joystick button is pressed.
 */
void os_waitForJoystickButtonInput() {
    // TODO implement.
}

/*!
 * Blocks until joystick button is released.
 */
void os_waitForNoJoystickButtonInput() {
    // TODO implement.
}

/*!
 * Returns Read value of the ADC
 *
 * @param pin      Multiplexer select to connect ADC
 */
uint16_t os_getJoystick(uint8_t pin) {
    // TODO implement.
}

/*!
 * Returns Read value of the ADC
 */
uint16_t js_getHorizontal() {
    // TODO implement.
}

/*!
 * Returns Read value of the ADC
 */
uint16_t js_getVertical() {
    // TODO implement.
}

/*!
 * Returns The evaluated Direction
 */
Direction js_getDirection() {
    // TODO implement.
}
