/*
 * dynamics.h
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */

#ifndef DYNAMICS_H_
#define DYNAMICS_H_

#define CLICK 0x01


uint8_t dibujar5(uint8_t *hid_buffer);
uint8_t mouseRight_and_click(uint8_t *hid_buffer);
uint8_t mouseLeft_and_click(uint8_t *hid_buffer);
uint8_t keyboard_open_paint(uint8_t *bufferKey);
uint8_t keyboard_open_notes(uint8_t *bufferKey);
uint8_t keyboard_write_message(uint8_t *bufferKey);
uint8_t keyboard_copy_message(uint8_t *bufferKey);

#endif /* DYNAMICS_H_ */
