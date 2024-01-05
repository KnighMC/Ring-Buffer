# RING BUFFER

Ring Buffer based in FIFO logic. The Allowed items are 'uint8_t' => unsigned char

# CONTENT

- USE
- AVAILABLE FUNCTIONS
- LICENSE
- ABOUT

# USE

Call the constructor in your main code:

#define SIZE    10
RingBuffer* Buffer1 = initializeBuffer(SIZE);

Free memory:

freeBuffer(Buffer1);   // THIS IS IMPORTANT

# AVAILABLE FUNCTIONS

initializeBuffer(uint8_t size);                             initialize buffer in memory
freeBuffer(RingBuffer* Handler);                            free memory
addToBuffer(RingBuffer* Handler, uint8_t item);             add item in the buffer
getFromBuffer(RingBuffer* Handler, uint8_t* item);          get item from buffer
removeFromBuffer(RingBuffer* Handler);                      remove item from buffer
BufferFlush(RingBuffer* Handler);                           delete all elements in the buffer
isBufferFull(RingBuffer* Handler);                          return if is buffer complete
isBufferEmpty(RingBuffer* Handler);                         return if is buffer empty


# LICENSE

/******************************************************************************
 * File: ringBuffer
 * Author: KnightMC
 * Comments: file of ringBuffer module.
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

# ABOUT

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