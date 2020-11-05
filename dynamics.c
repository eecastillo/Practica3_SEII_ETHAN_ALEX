/*
 * dynamics.c
 *
 *  Created on: Nov 4, 2020
 *      Author: eduar
 */

#include "dynamics.h"


uint8_t openPaint(uint8_t *bufferKey)
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

