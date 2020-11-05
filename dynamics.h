/*
 * dynamics.h
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */

#ifndef DYNAMICS_H_
#define DYNAMICS_H_

#define CLICK 0x01

typedef enum{
	open_paint,
	draw_5,
	open_notes_left,
	open_notes_right,
	mouse_left,
	hello_world,
	copy_txt,
	mouse_right,
	paste_txt,
	finish
}estados_t;

typedef enum{not_ok, ok} ready_t;

uint8_t dibujar5(uint8_t *hid_buffer);
uint8_t mouseRight_and_click(uint8_t *hid_buffer);
uint8_t mouseLeft_and_click(uint8_t *hid_buffer);
uint8_t keyboard_open_paint(uint8_t *bufferKey);
uint8_t keyboard_open_notes(uint8_t *bufferKey);
uint8_t keyboard_write_message(uint8_t *bufferKey);
uint8_t keyboard_copy_message(uint8_t *bufferKey);
uint8_t keyboard_paste_message(uint8_t *bufferKey);
estados_t get_program_state();

#endif /* DYNAMICS_H_ */
