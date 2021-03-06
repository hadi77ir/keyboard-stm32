/* Copyright (c) 2013, Vitaly Bursov <vitaly<AT>bursov.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the author nor the names of its contributors may
 *       be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef STRING_H
#define STRING_H

#include <stddef.h>
#include "defs.h"

int memcmp(const void *m1, const void *m2, size_t n);
void *memmove(void *dst_void, const void *src_void, size_t length);

/* arm-none-eabi-gcc-4.8.1 has some bug with cloning during -Os
 * optimization.
 *
 * Resulting object file fails to link with this error:
 *   whole_program.o: In function `terminal_move_cursor':
 *    libs/microrl/microrl.c:253: undefined reference to `memset'
 *
 * whole_program.o file has these symbols:
 *      U memset
 *      t memset.constprop.43
 *
 * Project compiles OK with a -O2.
 */
void _NOCLONE_NOINLINE_ *memset(void *m, int c, size_t n);

#define memcpy(a,b,c) memmove(a,b,c)

char* strcat(char *s1, const char *s2);
char* strcpy(char *dst0, const char *src0);
char* strncpy(char *dst0, const char *src0, size_t count);
size_t strlen(const char *str);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

#endif /* STRING_H */
