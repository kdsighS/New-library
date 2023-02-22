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

typedef struct nl_stack_t {
	nl_lock_t lock;
	void* base;
	nl_size_t top;
	nl_size_t current;
} nl_stack_t;

typedef struct nl_b_stack_t {
	struct nl_stack_t stack;
	nl_size_t each;
} nl_b_stack_t;

struct nl_stack_t nl_create_stack_t(void);
struct nl_stack_t nl_create_stack_t_i(nl_size_t initial_size);
int nl_push_stack_t(struct nl_stack_t* stack,void* source,nl_size_t size);
int nl_pop_stack_t(struct nl_stack_t* stack,void* dest,nl_size_t size);
int nl_clean_stack_t(struct nl_stack_t* stack);
int nl_destory_stack_t(struct nl_stack_t* stack);

struct nl_b_stack_t nl_create_b_stack_t(nl_size_t each_size);
struct nl_b_stack_t nl_create_b_stack_t_i(nl_size_t each_size,nl_size_t initial_size);
int nl_push_b_stack_t(struct nl_b_stack_t* stack,void* source);
int nl_pop_b_stack_t(struct nl_b_stack_t* stack,void* dest);
int nl_clean_b_stack_t(struct nl_b_stack_t* stack);
int nl_destory_b_stack_t(struct nl_b_stack_t* stack);

#endif
