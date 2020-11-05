/*
 * dynamics.c
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */
#include "dynamics.h"



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
    static int x = 0;
    static unit8_t flag = running;
    static uint8_t dir = step1;
    static uint8_t keys_array[] = {KEY_RIGTH_GUI, KEY_P, KEY_A, KEY_I, KEY_N, KEY_T, KEY_ENTER};

    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if ( x > 200){
            bufferKey[2] = keys_array[dir];
            dir ++;
            x = 0;
            if(dir == 8){
                dir = step1;
                flag = ready;
                bufferKey[2] = 0;
            }
        }
    }
    return flag;
}
uint8_t keyboard_open_notes(uint8_t *bufferKey)
{
    static int x = 0;
    static uint8_t flag = running;
    static first_notepad = 0;
    static uint8_t dir = step1;
    statis uint8_t keys_array[] = {KEY_LEFT_GUI, KEY_N, KEY_O, KEY_T, KEY_E, KEY_P, KEY_A, KEY_D, KEY_ENTER, KEY_LEFT_GUI};
    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if(x > 200){
            if(dir == step1){
                bufferKey[3] = KEY_R;
            }
            if(dir == step9){
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
                dir = step1;
                if(first_notepad == 2)
                {
                    flag = ready;
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
    static uint8_t flag = running;
    static uint8_t dir = step1;
    statis uint8_t keys_array[] = {KEY_H, KEY_O, KEY_L, KEY_A, KEY_SPACEBAR, KEY_M, KEY_U, KEY_N, KEY_D, KEY_O, KEY_LEFTCONTROL, KEY_LEFTCONTROL};

    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        if(x > 200){
            bufferKey[2] = keys_array[dir];
            if(dir == 11){
                bufferKey[3] = KEY_A;
            }
            if(dir == 12){
                bufferKey[3] KEY_C;
            }
            if(dir == 13){
                dir = step1;
                flag = ready;
                bufferKey[2] = 0;
            }
        }
    }
    return flag;
}
uint8_t keyboard_copy_message(uint8_t *bufferKey)
{
    static int x = 0;
    static uint8_t flag = running;
    static uint8_t dir step1;
    static uint8_t keys_array[] = {KEY_LEFTCONTROL, KEY_ENTER};
    bufferKey[2] = 0;
    if(flag == 0){
        x++;
        ix(x > 200){
            bufferKey[2] = keys_array[dir];
            dir++;
            x = 0;
            if(dir == 1){
                bufferKey[3] = KEY_V;
            }
            if(dir == 3){
                dir = step1;
                flag = ready;
                bufferKey[2] = 0;
            }
        }
    }
    return flag;
}
