/*! \file
 * \brief CUSTOM CHAR PATTERNS.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _LED_PATTERNS_H
#define _LED_PATTERNS_H

#include <avr/pgmspace.h>

//----------------------------------------------------------------------------
// Macros
//----------------------------------------------------------------------------

//! Defines a custom CHAR out of eight rows passed as integer values.
#define LED_CUSTOM_CHAR(cc0, cc1, cc2, cc3, cc4, cc5, cc6, cc7) 0 |(((uint64_t)(cc0)) << 0 * 8) |(((uint64_t)(cc1)) << 1 * 8) |(((uint64_t)(cc2)) << 2 * 8) |(((uint64_t)(cc3)) << 3 * 8) |(((uint64_t)(cc4)) << 4 * 8) |(((uint64_t)(cc5)) << 5 * 8) |(((uint64_t)(cc6)) << 6 * 8) |(((uint64_t)(cc7)) << 7 * 8)

//! Helper macros to define a large (7x5) and small(5x3) character without padding. Will be aligned in the top-left corner of the resulting custom char.
#define LED_CUSTOM_CHAR_SMALL(row1, row2, row3, row4, row5) LED_CUSTOM_CHAR(row1 << 5, row2 << 5, row3 << 5, row4 << 5, row5 << 5, 0, 0, 0)


//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

//! Patterns for the letters and numbers.
const uint64_t PROGMEM led_small_letters [];

#endif
