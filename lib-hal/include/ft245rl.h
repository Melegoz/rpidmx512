/**
 * @file ft245rl.h
 *
 */
/* Copyright (C) 2015, 2016 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef FT245RL_H_
#define FT245RL_H_

#include <stdint.h>
#include <stdbool.h>

#include "bcm2835.h"

extern void FT245RL_init(void);
extern void FT245RL_write_data(uint8_t);
extern uint8_t FT245RL_read_data();

/**
 * @ingroup ft245rl
 *
 * Read RXF#
 *
 * @return
 */
inline static bool FT245RL_data_available(void) {
	return (!(BCM2835_GPIO->GPLEV0 & (1 << 25)));
}

/**
 * @ingroup ft245rl
 *
 * Read TXE#
 *
 * @return
 */
inline static bool FT245RL_can_write(void) {
	return (!(BCM2835_GPIO->GPLEV0 & (1 << 24)));
}

#endif /* FT245RL_H_ */
