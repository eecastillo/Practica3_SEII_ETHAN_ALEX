/*
 * dynamics.c
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */
#include "dynamics.h"

estados_t g_state = open_paint;

uint8_t dibujar5(uint8_t *hid_buffer)
{

}
uint8_t mouseRight_and_click(uint8_t *hid_buffer)
{

}
uint8_t mouseLeft_and_click(uint8_t *hid_buffer)
{

}
uint8_t keyboard_open_paint(uint8_t *bufferKey)
{

}
uint8_t keyboard_open_notes(uint8_t *bufferKey)
{

}
uint8_t keyboard_write_message(uint8_t *bufferKey)
{

}
uint8_t keyboard_copy_message(uint8_t *bufferKey)
{

}
estados_t get_program_state()
{
	return g_state;
}
