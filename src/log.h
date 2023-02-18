/*
MIT License

Copyright (c) 2023 Free Nothing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_LOG_H__
#define __NEW_LIBRARY_LOG_H__

#include <stdio.h>
#include "lock.h"

typedef struct log_t {
	lock_t lock;
	unsigned int attr;
	FILE* dest;
} log_t;

/*

#define NL_LOG_NONE	0b00000000
#define NL_LOG_TIME	0b00000001
#define NL_LOG_DATE	0b00000010
#define NL_LOG_PID	0b00000100

*/

enum {
	NL_LOG_NONE	= 0b00000000,
	NL_LOG_TIME	= 0b00000001,
	NL_LOG_DATE	= 0b00000010,
	NL_LOG_PID	= 0b00000100,
};

struct log_t create_log_t(char* file,unsigned int attr);
struct log_t create_log_t_f(FILE* dest,unsigned int attr);
int put_log_t(struct log_t* log,const char* expr,...);
int destory_log_t(struct log_t* log);

#endif
