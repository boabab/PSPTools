/*! \file
 * \brief Driver for AVRs SPI module.
 *
 * Basic functions for setup and use of the SPI module.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_SPI_H
#define _OS_SPI_H

#include "util.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>
#include <util/atomic.h>

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Configures relevant I/O registers/pins and initializes the SPI module.
void os_spi_init(void);

//! Performs a SPI send This method blocks until the data exchange is completed. Additionally, this method returns the byte which is received in exchange during the communication.
uint8_t os_spi_send(uint8_t data);

//! Performs a SPI read This method blocks until the exchange is completed.
uint8_t os_spi_receive();

#endif
