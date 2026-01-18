/*! \file
 * \brief High level functions to draw premade things on the LED Panel.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "led_draw.h"
#include "led_paneldriver.h"
#include "led_patterns.h"
#include "util.h"

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Distributes bits of given color's channels r, g and b on layers of framebuffer.
 */
void draw_setPixel(uint8_t x, uint8_t y, Color color) {
    // TODO implement.
}

/*!
 * Reconstructs RGB-Color from layers of framebuffer.
 */
Color draw_getPixel(uint8_t x, uint8_t y) {
    // TODO implement.
}

/*!
 * Fills whole panel with given color.
 */
void draw_fillPanel(Color color) {
    // TODO implement.
}

/*!
 * Sets every pixel's color to black.
 */
void draw_clearDisplay() {
    // TODO implement.
}

/*!
 * Draws Rectangle.
 */
void draw_filledRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, Color color) {
    // TODO implement.
}

/*!
 * Used by Testtask to draw Arrow Symbol.
 *
 * @param x        Column of left upper corner
 * @param y        Row of left upper corner
 * @param height   Height to be used for the pattern
 * @param width    Width to be used for the pattern
 * @param pattern  The given pattern. Has a maximum span of 8x8 pixel
 * @param color    RGB color used to draw the pattern with
 * @param overwrite Delete pixels in picture that are black in the pattern if set to true
 */
void draw_pattern(uint8_t x, uint8_t y, uint8_t height, uint8_t width, uint64_t pattern, Color color, bool overwrite) {
    // TODO implement.
}

/*!
 * Draws capital letter on panel.
 *
 * @param letter   A character of [0-9A-Za-z]. Note: small letters cannot be drawn, the
 *                corresponding capital letter will be drawn instead.
 * @param x        Column of left upper corner
 * @param y        Row of left upper corner
 * @param color    RGB color to draw letter with
 * @param overwrite Delete pixels in picture that are black in the pattern if set to true
 */
void draw_letter(char letter, uint8_t x, uint8_t y, Color color, bool overwrite, bool large) {
    // TODO implement.
}

/*!
 * Draws Decimal (0..9) on panel.
 *
 * @param dec      Decimal number (from 0 to 9)
 * @param x        Row of left upper corner
 * @param y        Column of left upper corner
 * @param color    Color to draw number with
 * @param overwrite Delete pixels in picture that are black in the pattern if set to true
 * @param large    Draws large numbers when set to true, otherwise small (small: 5x3 px, large: 7x5
 *                px)
 */
void draw_decimal(uint8_t dec, uint8_t x, uint8_t y, Color color, bool overwrite, bool large) {
    // TODO implement.
}

/*!
 * Draws an integer on panel.
 *
 * @param number   The number to draw
 * @param right_align if true, the least-significant digit of the number will be drawn at x,y;
 *                otherwise, the number will start at this position
 * @param x        Column of the top-left corner of either the first or the last digit, depending on
 *                right_align
 * @param y        Row of the top-left corner of either the first or the large digit, depending on
 *                right_align
 * @param overwrite Delete pixels in picture that are black in the pattern if set to true
 * @param large    Draws large numbers when set to true, otherwise small (small: 5x3 px, large: 7x5
 *                px)
 */
void draw_number(uint32_t number, bool right_align, uint8_t x, uint8_t y, Color color, bool overwrite, bool large) {
    // TODO implement.
}
