/*! \file
 * \brief Functions to access joystick.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _JOYSTICK_H
#define _JOYSTICK_H

#include <stdbool.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! Possible joystick directions.
typedef enum {
    // TODO implement.
} Direction;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Initialize joystick registers.
void js_init();

//! Calculates a Direction from current joystick position.
Direction js_getDirection();

//! Read vertical joystick displacement.
uint16_t js_getVertical();

//! Read horizontal joystick displacement.
uint16_t js_getHorizontal();

//! Getter for the joystick button state.
bool js_getButton();

//! Read joystick displacement.
uint16_t os_getJoystick(uint8_t pin);

//! Blocks until joystick button is pressed.
void os_waitForJoystickButtonInput(void);

//! Blocks until joystick button is released.
void os_waitForNoJoystickButtonInput(void);

#endif
