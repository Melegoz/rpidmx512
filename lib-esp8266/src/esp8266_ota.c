/**
 * @file esp8266_ota.c
 *
 */
/* Copyright (C) 2016 by Arjan van Vught mailto:info@raspberrypi-dmx.nl
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

#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#include "esp8266.h"
#include "esp8266_cmd.h"

/**
 *
 * @param server_ip_address
 */
void esp8266_ota_start(uint32_t server_ip_address) {
	esp8266_write_4bits((uint8_t) CMD_ESP_OTA_START);
	esp8266_write_word(server_ip_address);
}

/**
 *
 * @param status
 * @param len
 */
void esp8266_ota_status(char *status, uint16_t *len) {
	uint16_t i = 0;
	uint8_t ch;

	char *p = status;
	uint16_t max_len = *len;

	assert(status != NULL);
	assert(len != NULL);

	while ((ch = esp8266_read_byte()) != (uint8_t) 0) {
		if (i < max_len) {
			*p++ = (char) ch;
		}
		i++;
	}

	status[max_len] = '\0';
	*len = i;
}
