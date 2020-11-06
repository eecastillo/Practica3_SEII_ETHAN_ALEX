/*
 * dynamics.c
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */
#include "dynamics.h"
#define KEYBOARD_DELAY 2000000U
#define MOUSE_DELAY 1000000U

estados_t g_state = open_paint;
static int8_t g_x = 0U;
static int8_t g_y = 0U;

static void delay(uint32_t max)
{
	uint32_t delay_counter = 0;
	while (max > delay_counter)
		delay_counter++;
}

uint8_t dibujar5(uint8_t *hid_buffer)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;

    if(flag == not_ok)
    {
    	switch (dir)
		{
			case 0:
				/* Move left */
				hid_buffer[1] = 1U;
				hid_buffer[2] = (uint8_t) (-2);
				hid_buffer[3] = 0U;
				g_x++;
				if (g_x > 99U) {
					dir++;
					g_x = 0;
				}
				break;
			case 1:
				/* Move down */
				hid_buffer[1] = 1U;
				hid_buffer[2] = 0U;
				hid_buffer[3] = 2U;
				g_y++;
				if (g_y > 99U) {
					dir++;
					g_y = 0;
				}
				break;
			case 2:
				/* Move right */
				hid_buffer[1] = 1U;
				hid_buffer[2] = 2U;
				hid_buffer[3] = 0U;

				g_x++;
				if (g_x > 99U) {
					dir++;
					g_x = 0;
				}
				break;

			case 3:
				/* Move down */
				hid_buffer[1] = 1U;
				hid_buffer[2] = 0U;
				hid_buffer[3] = 2U;
				g_y++;
				if (g_y > 99U) {
					dir++;
					g_y = 0;
				}
				break;
			case 4:
				/* Move left */
				hid_buffer[1] = 1U;
				hid_buffer[2] = (uint8_t) (-2);
				hid_buffer[3] = 0U;
				g_x++;
				if (g_x > 99U) {
					dir++;
					g_x = 0;
					g_state++;
					hid_buffer[1] = 0U;
					hid_buffer[2] = 0U;
					hid_buffer[3] = 0U;
				}
				break;
			default:
				break;
			}
    }
    return flag;
}
uint8_t mouseRight_and_click(uint8_t *hid_buffer)
{
	 static uint8_t flag = not_ok;
	    static uint8_t dir = START;

	    if(flag == not_ok)
	    {
	    	switch (dir)
			{
				case 0:
					/* Move left */
					hid_buffer[1] = 0U;
					hid_buffer[2] = 2U;
					hid_buffer[3] = 0U;
					g_x++;
					if (g_x > 200U) {
						dir++;
						g_x = 0;
					}
					break;
				case 1:
					/*Click izquierdo*/
					hid_buffer[1] = 1U;
					hid_buffer[2] = 0;
					hid_buffer[3] = 0U;
					delay(MOUSE_DELAY);
					dir++;
					break;
				case 2:
					hid_buffer[1] = 0U;
					hid_buffer[2] = 0U;
					hid_buffer[3] = 0U;
					delay(MOUSE_DELAY);
					g_state++;
					flag = ok;
					break;
			}
	    }
	return flag;
}
uint8_t mouseLeft_and_click(uint8_t *hid_buffer)
{
	 static uint8_t flag = not_ok;
		    static uint8_t dir = START;

		    if(flag == not_ok)
		    {
		    	switch (dir)
				{
					case 0:
						/* Move left */
						hid_buffer[1] = 0U;
						hid_buffer[2] = (uint8_t) (-2);
						hid_buffer[3] = 0U;
						g_x++;
						if (g_x > 99U) {
							dir++;
							g_x = 0;
						}
						break;
					case 1:
						/*Click izquierdo*/
						hid_buffer[1] = 1U;
						hid_buffer[2] = 0;
						hid_buffer[3] = 0U;
						dir++;
						break;
					case 2:
						hid_buffer[1] = 0U;
						hid_buffer[2] = 0U;
						hid_buffer[3] = 0U;
						g_state++;
						flag = ok;
						break;
				}
		    }
		return flag;
}
uint8_t keyboard_open_paint(uint8_t *bufferKey)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {START, MODIFERKEYS_LEFT_GUI, KEY_M, KEY_S,
    							   KEY_P, KEY_A, KEY_I, KEY_N, KEY_T, KEY_ENTER};
    if(flag == not_ok){
		if(dir == START){
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		else if(dir == CONTROL_BYTE){
			bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_R;
			delay(KEYBOARD_DELAY);
		}
		else{
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		dir++;
		if(dir == ENTER){
			dir = START;
			flag = ok;
			bufferKey[3] = 0X00U;
			g_state++;
			delay(KEYBOARD_DELAY);
		}
    }
    return flag;
}
uint8_t keyboard_open_notes_left(uint8_t *bufferKey)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {START, MODIFERKEYS_LEFT_GUI, KEY_N, KEY_O,
        							   KEY_T, KEY_E, KEY_P, KEY_A, KEY_D, KEY_ENTER, MODIFERKEYS_LEFT_GUI};
    if(flag == 0){
		if(dir == START){
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		else if(dir == 1){
			bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_R;
			delay(KEYBOARD_DELAY);
		}
		else if(dir == 10){
			bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_LEFTARROW;
			delay(KEYBOARD_DELAY);
		}
		else{
			bufferKey[1] = 0x00;
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		dir++;
		if(dir == 11){
			dir = START;
			flag = ok;
			g_state++;
			delay(KEYBOARD_DELAY);
		}
    }
    return flag;
}
uint8_t keyboard_open_notes_right(uint8_t *bufferKey)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {START, MODIFERKEYS_LEFT_GUI, KEY_N, KEY_O,
        							   KEY_T, KEY_E, KEY_P, KEY_A, KEY_D, KEY_ENTER, MODIFERKEYS_LEFT_GUI};
    if(flag == 0){
		if(dir == START){
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		else if(dir == 1){
			bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_R;
			delay(KEYBOARD_DELAY);
		}
		else if(dir == 10){
			bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_RIGHTARROW;
			delay(KEYBOARD_DELAY);
		}
		else{
			bufferKey[1] = 0x00;
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}

		dir++;
		if(dir == 12){
			dir = START;
			flag = ok;
			bufferKey[1] = 0x00;
			bufferKey[3] = 0x00;
			g_state++;
			delay(KEYBOARD_DELAY);
		}

    }
    return flag;
}

uint8_t keyboard_write_message(uint8_t *bufferKey)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {START, KEY_H, KEY_O, KEY_L, KEY_A, KEY_SPACEBAR,
    		                       KEY_M, KEY_U, KEY_N, KEY_D, KEY_O};
    if(flag == not_ok){
		if(dir == START){
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		else{
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
		dir++;
		if(dir == 12){
			dir = START;
			flag = ok;
			bufferKey[3] = 0X00U;
			g_state++;
			delay(KEYBOARD_DELAY);
		}
    }
    return flag;
}
uint8_t keyboard_copy_message(uint8_t *bufferKey)
{
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {START,KEY_LEFTCONTROL};
    bufferKey[2] = 0;
    if(flag == 0){
    	if(dir == START){
			bufferKey[3] = keys_array[dir];
			delay(KEYBOARD_DELAY);
		}
    	else if(dir == CONTROL_BYTE){
    		bufferKey[1] = keys_array[dir];
			bufferKey[3] = KEY_C;
			delay(KEYBOARD_DELAY);
        }

		dir++;
		if(dir == 2)
		{
			bufferKey[3] = 0X00U;
			g_state++;
			delay(KEYBOARD_DELAY);
		}
    }
    return flag;
}
uint8_t keyboard_paste_message(uint8_t *bufferKey)
{
	static uint8_t flag = not_ok;
	    static uint8_t dir = START;
	    static uint8_t keys_array[] = {START,KEY_LEFTCONTROL};
	    bufferKey[2] = 0;
	    if(flag == 0){
	    	if(dir == START){
				bufferKey[3] = keys_array[dir];
				delay(KEYBOARD_DELAY);
			}
	    	else if(dir == CONTROL_BYTE){
	    		bufferKey[1] = keys_array[dir];
				bufferKey[3] = KEY_V;
				delay(KEYBOARD_DELAY);
	        }

			dir++;
			if(dir == 2)
			{
				bufferKey[3] = 0X00U;
				g_state++;
				delay(KEYBOARD_DELAY);
			}
	    }
	    return flag;
}

uint8_t keyboard_select_all(uint8_t *bufferKey)
{
	static uint8_t flag = not_ok;
	    static uint8_t dir = START;
	    static uint8_t keys_array[] = {START,KEY_LEFTCONTROL};
	    bufferKey[2] = 0;
	    if(flag == 0){
	    	if(dir == START){
				bufferKey[3] = keys_array[dir];
				delay(KEYBOARD_DELAY);
			}
	    	else if(dir == CONTROL_BYTE){
	    		bufferKey[1] = keys_array[dir];
				bufferKey[3] = KEY_A;
				delay(KEYBOARD_DELAY);
	        }

			dir++;
			if(dir == 2)
			{
				bufferKey[3] = 0X00U;
				g_state++;
				delay(KEYBOARD_DELAY);
			}
	    }
	    return flag;
}
estados_t get_program_state()
{
	return g_state;
}
