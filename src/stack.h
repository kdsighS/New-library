/*
MIT License

Copyright (c) 2023 Free Nothing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_STACK_H__
#define __NEW_LIBRARY_STACK_H__

#include "header.h"
#include "lock.h"

typedef struct stack_t {
	lock_t lock;
	void* base;
	size_t top;
	size_t current;
} stack_t;

typedef struct b_stack_t {
	struct stack_t stack;
	size_t each;
} b_stack_t;

struct stack_t create_stack_t(void);
struct stack_t create_stack_t_i(size_t initial_size);
int push_stack_t(struct stack_t* stack,void* source,size_t size);
int pop_stack_t(struct stack_t* stack,void* dest,size_t size);
int clean_stack_t(struct stack_t* stack);
int destory_stack_t(struct stack_t* stack);

struct b_stack_t create_b_stack_t(size_t each_size);
struct b_stack_t create_b_stack_t_i(size_t each_size,size_t initial_size);
int push_b_stack_t(struct b_stack_t* stack,void* source);
int pop_b_stack_t(struct b_stack_t* stack,void* dest);
int clean_b_stack_t(struct b_stack_t* stack);
int destory_b_stack_t(struct b_stack_t* stack);

#endif
