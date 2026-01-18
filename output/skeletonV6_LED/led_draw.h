/*! \file
 * \brief High level functions to draw premade things on the LED Panel.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _LED_DRAW_H
#define _LED_DRAW_H

#include <stdbool.h>
#include <stdint.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Used by Testtask to draw Arrow Symbol.
void draw_pattern(uint8_t x, uint8_t y, uint8_t height, uint8_t width, uint64_t pattern, Color color, bool overwrite);

//! Draws Decimal (0..9) on panel.
void draw_decimal(uint8_t dec, uint8_t x, uint8_t y, Color color, bool overwrite, bool large);

//! Draws capital letter on panel.
void draw_letter(char letter, uint8_t x, uint8_t y, Color color, bool overwrite, bool large);

//! Draws an integer on panel.
void draw_number(uint32_t number, bool right_align, uint8_t x, uint8_t y, Color color, bool overwrite, bool large);

//! Distributes bits of given color's channels r, g and b on layers of framebuffer.
void draw_setPixel(uint8_t x, uint8_t y, Color color);

//! Reconstructs RGB-Color from layers of framebuffer.
Color draw_getPixel(uint8_t x, uint8_t y);

//! Fills whole panel with given color.
void draw_fillPanel(Color color);

//! Sets every pixel's color to black.
void draw_clearDisplay();

//! Draws Rectangle.
void draw_filledRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color);

#endif
