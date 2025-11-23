/*! \file
 * \brief Library for LCD use.
 *
 * Contains all the essential functionalities to comfortably work with the LCD on the evaluation
 * board.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "lcd.h"
#include "util.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/atomic.h>
#include <util/delay.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * Global var, stores character count.
 */
uint8_t charCtr;

/*!
 * LCD output stream.
 */
FILE * lcdout = &(FILE)FDEV_SETUP_STREAM(lcd_writeWrapper, NULL , _FDEV_SETUP_WRITE);


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Internally used to turn on LCD Pin EN (Enable) for 1us.
 */
void lcd_enable(void) {
    // TODO implement.
}

/*!
 * Prepares the LCD to be used with the defined output-port. Delay times as specified with some
 * reserve
 */
void lcd_init(void) {
    // TODO implement.
}

/*!
 * Moves the cursor to the first character of the first line of the LCD.
 */
void lcd_line1(void) {
    // TODO implement.
}

/*!
 * Moves the cursor to the first character of the second line of the LCD.
 */
void lcd_line2(void) {
    // TODO implement.
}

/*!
 * Moves the cursor one step back.
 */
void lcd_back(void) {
    // TODO implement.
}

/*!
 * Moves the cursor one step forward.
 */
void lcd_forward(void) {
    // TODO implement.
}

/*!
 * Moves the cursor to the first char
 */
void lcd_home(void) {
    // TODO implement.
}

/*!
 * Relatively moves the cursor on the LCD.
 *
 * @param row      Advance this many rows.
 * @param column   Advance this many columns.
 */
void lcd_move(char row , char column) {
    // TODO implement.
}

/*!
 * Moves the cursor to a specific position on the LCD. Row and column start counting at 1, so (1,1)
 * is top left, (2,16) is bottom right.
 *
 * @param row      The row to jump to (may be 1 or 2).
 * @param column   The column to jump to (may be 1...16).
 */
void lcd_goto(unsigned char row , unsigned char column) {
    // TODO implement.
}

/*!
 * Sends a stream to the LCD. The stream is a two-char pair which either holds a command or a
 * printable char. This function is used by lcd_command and lcd_writeChar.
 *
 * @param firstByte The first value to send.
 * @param secondByte The second value to send.
 */
void lcd_sendStream(uint8_t firstByte , uint8_t secondByte) {
    // TODO implement.
}

/*!
 * Sends a specific command to the LCD. This function is only used internally. There is no need to
 * explicitly call it as its functionality is encapsulated within the other functions.
 *
 * @param command  The command to be executed.
 */
void lcd_command(uint8_t command) {
    // TODO implement.
}

/*!
 * Writes an 8-Bit UTF-8-like-value to the LCD. Supports automatic line breaks.
 *
 * @param character The character to be written.
 */
void lcd_writeChar(char character) {
    // TODO implement.
}

/*!
 * Erases the LCD and positions the cursor at the top left corner.
 */
void lcd_clear(void) {
    // TODO implement.
}

/*!
 * Erases one line of the LCD. Cursor will not be changed.
 *
 * @param line     the line which will be erased (may be 1 or 2).
 */
void lcd_erase(uint8_t line) {
    // TODO implement.
}

/*!
 * Writes a hexadecimal half-byte (one nibble)
 *
 * @param number   The number to be written.
 */
void lcd_writeHexNibble(uint8_t number) {
    // TODO implement.
}

/*!
 * Writes a hexadecimal byte (equals two chars)
 *
 * @param number   The number to be written.
 */
void lcd_writeHexByte(uint8_t number) {
    // TODO implement.
}

/*!
 * Writes a hexadecimal word (equals two bytes)
 *
 * @param number   The number to be written.
 */
void lcd_writeHexWord(uint16_t number) {
    // TODO implement.
}

/*!
 * Writes a hexadecimal word, without adding leading zeros.
 *
 * @param number   The number to be written.
 */
void lcd_writeHex(uint16_t number) {
    // TODO implement.
}

/*!
 * Writes a 16 bit integer as a decimal number without leading zeros.
 *
 * @param number   The number to be written.
 */
void lcd_writeDec(uint16_t number) {
    // TODO implement.
}

/*!
 * Writes a string of 8-Bit ASCII-values to the LCD. This function supports automated line breaks.
 * If you reach the end of one line, the next line will be erased and the cursor will jump to the
 * beginning of the next line. The string needs to be null terminated correctly.
 *
 * @param text     The string to be written (a pointer to the first character).
 */
void lcd_writeString(const char * text) {
    // TODO implement.
}

/*!
 * Writes a draw bar
 *
 * @param percent  Percent of draw bar to be drawn
 */
void lcd_drawBar(uint8_t percent) {
    // TODO implement.
}

/*!
 * Writes a string of 8-Bit ASCII-values from the program flash memory to the LCD. This function
 * features automated line breaks as long as you don't manually do something with the cursor. This
 * works fine in concert with lcd_write_char without messing up anything. After 32 character have
 * been written, the LCD will be erased and the cursor starts again at the first character of the
 * first line. So the function will automatically seize output after 32 characters. This is a mighty
 * tool for saving SRAM memory.
 *
 * @param string   The string to be written (a pointer to the first character).
 */
void lcd_writeProgString(const char * string) {
    // TODO implement.
}

/*!
 * Writes an error string of 8-Bit ASCII-values from the program flash memory to the LCD. For
 * details see lcd_writeProgString.
 *
 * @param string   The string to be written (a pointer to the first character).
 */
void lcd_writeErrorProgString(const char * string) {
    // TODO implement.
}

/*!
 * Registers a custom char with the LCD CGRAM. Note that only 5 distinct chars will be stored at a
 * time. The sixth char will override the first.
 *
 * @param addr     is the address where the character is to be stored. This value is interpreted
 *                modulo 8.
 * @param chr      The passed value is one 64 bit integer witch holds all rows of the character.
 */
void lcd_registerCustomChar(uint8_t addr , uint64_t chr) {
    // TODO implement.
}

/*!
 * Writes a 32bit Number as Hex
 *
 * @param number   is the number to write
 */
void lcd_write32bitHex(uint32_t number) {
    // TODO implement.
}

/*!
 * Write a voltage with valueUpperBound as float voltage with voltUpperBound.
 *
 * @param voltage  Binary voltage value.
 * @param valueUpperBound Upper bound of the binary voltage value (i.e. 1023 for 10-bit value).
 * @param voltUpperBound Upper bound of the float voltage value (i.e. 5 for 5V).
 */
void lcd_writeVoltage(uint16_t voltage , uint16_t valueUpperBound , uint8_t voltUpperBound) {
    // TODO implement.
}
