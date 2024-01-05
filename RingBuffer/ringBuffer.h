/******************************************************************************
 * File: ringBuffer                       @file   ringBuffer.h
 * Author: KnightMCC                      @author KnightMCC
 * Comments: file of ringBuffer module.   @brief  Header file of ringBuffer module.
 * Revision history: 04/01/2024
 ******************************************************************************
 * @brief        Interface declaration of ringBuffer module.
 * @attention    See implementation file for information about this module.
 *
 * Copyright (c) 2024 KnightMCC
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

#ifndef RING_BUFFER_H_FILE
#define RING_BUFFER_H_FILE  "library usart V1.0\n"

#include <stdint.h>
#include <stdbool.h>

 /******************************************************************************
   * Ring Buffer:
   *
   * - First starts with all empty buffer.
   * - The lenght is set.
   * - Uses FIFO logic: the first data in, is the first out.
   * - When the buffer is Full, incoming data is overwritting on top of older
   *   data.
   * - But the routine manager might avoid overwriting the data and alarming
   *   about errors or throwing exceptions.
   * - The head make reference to actual end index into buffer.
   * - The tail make reference to actual start index into buffer.
   *          _____________________________________________________
   * Example: |  |  | start | 2 | 3 | 4 | end | (next data) |  |  |
   *          ----------------------------------------------------
   * - When the index of the head and tail are equal, the buffer is empty
   * - When the size in use is equal to => length - 1, the buffer is complete
   ******************************************************************************/
typedef struct {

  volatile bool emptying;
  volatile uint8_t head;
  volatile uint8_t tail;
  uint8_t size;
  uint8_t* buffer;

}RingBuffer;


/*****************************************************************************************
 * @brief   allocating memory for struct
 * @param   size      Number of elements allowed in the buffer
 *****************************************************************************************/
RingBuffer* initializeBuffer(uint8_t size);

/*****************************************************************************************
 * @brief   free allocated memory for buffer
 * @param   Handler   Pointer to struct of Buffer Data Control
 *****************************************************************************************/
void freeBuffer(RingBuffer* Handler);

/*****************************************************************************************
 * @brief   Add item to buffer
 * @param   Handler   Pointer to struct of Buffer Data Control
 * @param   item      Item to add into buffer
 *****************************************************************************************/
void addToBuffer(RingBuffer* Handler, uint8_t item);

/*****************************************************************************************
 * @brief   Gets a item stored in the buffer
 * @param   Handler   Pointer to struct of Buffer Data Control
 * @param   item      Pointer to the direction of the variable where the item will be
 *                    assigned
 *****************************************************************************************/
void getFromBuffer(RingBuffer* Handler, uint8_t* item);

/******************************************************************************************
 * @brief   Remove the most recent data
 * @param   Handler   Pointer to struct of Buffer Data Control
 *****************************************************************************************/
void removeFromBuffer(RingBuffer* Handler);

/******************************************************************************************
 * @brief   Delete all items stored in the buffer
 * @param   Handler   Pointer to struct of Buffer Data Control
 *****************************************************************************************/
void BufferFlush(RingBuffer* Handler);

/******************************************************************************************
 * @brief   Flag:  is buffer full?
 * @param   Handler   Pointer to struct of Buffer Data Control
 * @retval  Returns 1: if the buffer is Full
 *****************************************************************************************/
bool isBufferFull(RingBuffer* Handler);

/******************************************************************************************
 * @brief   Flag:  is buffer empty?
 * @param   Handler   Pointer to struct of Buffer Data Control
 * @retval  Returns 1: if the buffer is Empty
 *****************************************************************************************/
bool isBufferEmpty(RingBuffer* Handler);

#endif /* RING_BUFFER_H_FILE */