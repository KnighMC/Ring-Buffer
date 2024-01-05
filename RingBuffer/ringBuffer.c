/******************************************************************************
 * File: ringBuffer                       @file   ringBuffer.c
 * Author: KnightMC                       @author KnightMC
 * Comments: file of ringBuffer module.   @brief  Header file of ringBuffer module.
 * Revision history: 04/01/2024
 ******************************************************************************
 * @brief        Interface declaration of ringBuffer module.
 * @attention    See implementation file for information about this module.
 *
 * Copyright (c) 2024 KnightMC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Sofware, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABLILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 * *****************************************************************************
 */
#include "ringBuffer.h"

#include <string.h>
#include <stdlib.h>

RingBuffer* initializeBuffer(uint8_t size) {

    RingBuffer* instance = (RingBuffer*)malloc(sizeof(RingBuffer));


    if (instance == NULL)
        /* Exception(Error allocating memory for struct)*/
        return NULL;

    instance->buffer = (uint8_t*)malloc(size * sizeof(uint8_t));

    if (instance->buffer == NULL) {
        /* Exception(Error allocating memory for buffer)*/
        free(instance);
        return NULL;
    }

    memset(instance->buffer, 0, sizeof(instance->buffer));
    instance->size = size;
    instance->head = 0;
    instance->tail = 0;

    return instance;

}

void freeBuffer(RingBuffer* Handler) {

    free(Handler->buffer);
    free(Handler);

}

bool isBufferFull(RingBuffer* Handler) {

    return  (((Handler->head + 1) % Handler->size) == Handler->tail);

}

bool isBufferEmpty(RingBuffer* Handler) {

    return (Handler->tail == Handler->head);

}

void addToBuffer(RingBuffer* Handler, uint8_t item) {

    Handler->buffer[Handler->head] = item;
    Handler->head = (Handler->head + 1) % Handler->size;

}

void getFromBuffer(RingBuffer* Handler, uint8_t* item) {

    *item = Handler->buffer[Handler->tail];
    Handler->tail = (Handler->tail + 1) % Handler->size;

}

void BufferFlush(RingBuffer* Handler) {

    Handler->head = 0;
    Handler->tail = 0;
    Handler->emptying = false;

    memset(Handler->buffer, 0, sizeof(Handler->buffer));

}
void removeFromBuffer(RingBuffer* Handler) {

    Handler->head = (Handler->head - 1) % Handler->size;

}