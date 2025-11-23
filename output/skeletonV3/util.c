/*! \file
 *
 * Contains basic utility functions used all over the system.
 *
 */

#include "util.h"
#include "atmega644constants.h"
#include "defines.h"
#include "lcd.h"
#include "os_core.h"
#include "os_input.h"
#include <avr/interrupt.h>
#include <avr/io.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * Variable to store TIMER0 overflows used to calculate wall-time in os_systemTime_[coarse|precise]
 * functions.
 */
Time os_systemTime_overflows = 0 static;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * ISR that counts the number of occurred Timer 0 overflows for the os_systemTime_[coarse|precise]
 * functions.
 */
ISR(TIMER0_OVF_vect) {
    // TODO implement.
}

/*!
 * Function to reset os_systemTime_overflows to 0, effectively resetting the internal system time
 */
void os_systemTime_reset(void) {
    // TODO implement.
}

/*!
 * Function that returns the current systemtime in ms based on the interrupt counts alone
 * (Difference ROUNDED after ~80s by 1s to os_systemTime_precise) Returns The converted system time
 * in ms calculation performed: os_systemTime_overflows*1000 /(F_CPU/TC0_PRESCALER/256) timercounts
 * | mult to get ms | to get from freq to time
 */
Time os_systemTime_coarse(void) {
    // TODO implement.
}

/*!
 * Function augments os_systemTime_overflows to increase precision to approx 13 us (presc/f_cpu =
 * 256/20MHz) Returns os_systemTime_overflows scaled by cpu speed , timer prescaler as well as
 * register size in case Interrupts are off and the overflow flag is activated we simulate the
 * overflow interrupt. The flag signalizes, that an overflow occurred. This would have been handled
 * by the ISR immediately but since the interrupts are off, the controller will wait until they come
 * back on. However, until that point yet another overflow could occur, which we would then be
 * unable to detect. here comes the actual job of this routine. We take the coarse system time which
 * has a resolution of 3.3 ms and augment it with the current TCNT0 counter register, yielding a
 * resolution of ~ 13 us.
 */
static Time os_systemTime_augment(void) static {
    // TODO implement.
}

/*!
 * Function that returns the current systemtime in ms augmented by additional timer registers,
 * leading to higher accuracy at expense of performance. If not needed better use
 * os_systemTime_coarse() (Difference ROUNDED after ~80s by 1s to os_systemTime_coarse) Returns The
 * converted system time in ms augmented by TCNT0 counter register calculation performed:
 * os_systemTime_augment() *1000 /(F_CPU/TC0_PRESCALER/256) / 256 timercounts + TCNT0 counter | mult
 * to get ms | to get from freq to time | to account for shift by os_systemTime_augment() this can
 * be simplified to :
 */
Time os_systemTime_precise(void) {
    // TODO implement.
}

/*!
 * Function that may be used to wait for specific time intervals. Therefore, we calculate the
 * relative time to wait. This value is added to the current system time in order to get the
 * destination time. Then, we wait until a temporary variable reaches this value. We have to
 * distinguish two cases: 1.) If the startTime is smaller than the destinationTime, we can wait
 * until the current time (= now) is bigger than startTime but smaller than the destinationTime.
 * Keep waiting if the value of now is anywhere in the sections marked with + 0
 * |-------------—S+++++++++++++++D----—| max time 2.) If we detect an overflow (startTime >
 * destinationTime) then we have to wait for now reaching maxtime (the overflow) and afterwards now
 * reaching destinationTime Keep waiting if now is anywhere in the sections marked with + 0
 * |++++++++++++++++D------------—S+++++++| max time
 *
 * @param ms       The time to be waited in milliseconds (max. 2^32 = 4294967296 ms ~= 7 weeks)
 */
void delayMs(Time ms) {
    // TODO implement.
}

/*!
 * Simple assertion function that is used to ensure specific behavior Note that there is a define
 * assert(exp,errormsg) that simplifies the usage of this function. Returns True, iff the given
 * expression is true
 *
 * @param exp      The boolean expression that is expected to be true.
 * @param errormsg The string that shall be shown as an error message if the given expression is
 *                false.
 */
bool assertPstr(bool exp , const char * errormsg) {
    // TODO implement.
}
