/*! \file
 *
 * The main system core with initialization functions and error handling.
 *
 */

#include "os_core.h"
#include "defines.h"
#include "lcd.h"
#include "os_input.h"
#include "util.h"
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <stdio.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * In order for the Scheduler to work properly, it must have the chance to initialize its internal
 * data-structures and register.
 */
void os_initScheduler(void) {
    // TODO implement.
}

/*!
 * This method automatically runs to handle special initialization conditions: Saving the MCUSR for
 * later examination Disabling the watchdog timer in case it is enabled to keep the controller
 * usable
 */
void os_preInit(void) {
    // TODO implement.
}

/*!
 * Examines the saved MCU status register and possibly prints an error if the reset source is not
 * allowed.
 *
 * @param allowedSources Bitmask of reset sources which are accepted without pausing.
 */
void os_checkResetSource(uint8_t allowedSources) {
    // TODO implement.
}

/*!
 * Initializes the used timers.
 */
void os_init_timer(void) {
    // TODO implement.
}

/*!
 * Readies stack, scheduler and heap for first use. Additionally, the LCD is initialized. In order
 * to do those tasks, it calls the sub function os_initScheduler() .
 */
void os_init(void) {
    // TODO implement.
}

/*!
 * Terminates the OS and displays a corresponding error on the LCD.
 *
 * @param str      The error to be displayed
 */
void os_errorPStr(const char *str) {
    // TODO implement.
}
