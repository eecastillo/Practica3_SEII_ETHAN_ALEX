/*
 * dynamics.c
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */
#include "dynamics.h"
#define KEYBOARD_DELAY 2000000U

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
return ok;
}
uint8_t mouseLeft_and_click(uint8_t *hid_buffer)
{
return ok;
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
uint8_t keyboard_open_notes(uint8_t *bufferKey)
{
    static int x = 0;
    static uint8_t flag = not_ok;
    static uint8_t first_notepad = 0;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {KEY_LEFT_GUI, KEY_N, KEY_O, KEY_T, KEY_E, KEY_P, KEY_A, KEY_D, KEY_ENTER, KEY_LEFT_GUI};
    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if(x > 200){
            if(dir == START){
                bufferKey[3] = KEY_R;
            }
            if(dir == 8){
                if(first_notepad == 0){
                    bufferKey[3] = KEY_LEFTARROW;
                }
                if(first_notepad == 1){
                    bufferKey[3] = KEY_RIGHTARROW;
                }
            }
            bufferKey[2] = keys_array[dir];
            dir++;
            x = 0;
            if(dir == 12){
                first_notepad++;
                dir = START;
                if(first_notepad == 2)
                {
                    flag = ok;
                }
                bufferKey = 0;
            }
        }
    }
    return flag;
}
uint8_t keyboard_write_message(uint8_t *bufferKey)
{
    static int x = 0;
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {KEY_H, KEY_O, KEY_L, KEY_A, KEY_SPACEBAR, KEY_M, KEY_U, KEY_N, KEY_D, KEY_O, KEY_LEFTCONTROL, KEY_LEFTCONTROL};

    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if(x > 200){
            bufferKey[2] = keys_array[dir];
            if(dir == 11){
                bufferKey[3] = KEY_A;
            }
            if(dir == 12){
                bufferKey[3] = KEY_C;
            }
            if(dir == 13){
                dir = START;
                flag = ok;
                bufferKey[2] = 0;
            }
        }
    }
    return flag;
}
uint8_t keyboard_copy_message(uint8_t *bufferKey)
{
    static int x = 0;
    static uint8_t flag = not_ok;
    static uint8_t dir = START;
    static uint8_t keys_array[] = {KEY_LEFTCONTROL, KEY_ENTER};
    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if(x > 200){
            bufferKey[2] = keys_array[dir];
            dir++;
            x = 0;
            if(dir == 1){
                bufferKey[3] = KEY_V;
            }
            if(dir == 3){
                dir = START;
                flag = ok;
                bufferKey[2] = 0;
            }
        }
    }
    return flag;
}
uint8_t keyboard_paste_message(uint8_t *bufferKey)
{

}

estados_t get_program_state()
{
	return g_state;
}
