/*! \file
 * \brief Functions to draw premade things on the LED Panel.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "led_paneldriver.h"
#include "defines.h"
#include "util.h"
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Starts interrupts.
 */
void panel_startTimer(void) {
    // TODO implement.
}

/*!
 * Stops interrupts.
 */
void panel_stopTimer(void) {
    // TODO implement.
}

/*!
 * Initalizes interrupt timer.
 */
void panel_initTimer(void) {
    // TODO implement.
}

/*!
 * Initializes registers.
 */
void panel_init() {
    // TODO implement.
}

/*!
 * ISR to refresh LED panel, trigger 1 compare match interrupts.
 */
ISR(TIMER1_COMPA_vect) {
    // TODO implement.
}
