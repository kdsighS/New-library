/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "stack.h"
#include <malloc.h>
#include <string.h>

struct nl_stack_t nl_create_stack_t(void){
	struct nl_stack_t stack;
	stack.lock = nl_create_lock_t(1);
	stack.base = NULL;
	stack.current = 0;
	stack.top = 0;
	return stack;
};
struct nl_stack_t nl_create_stack_t_i(nl_size_t initial_size){
	struct nl_stack_t stack;
	stack = nl_create_stack_t();
	while((stack.base = malloc(initial_size)) == NULL);
	return stack;
};
int nl_push_stack_t(struct nl_stack_t* stack,void* source,nl_size_t size){
	nl_lock_h_t handle = nl_while_lock_t(&stack -> lock);
	if (!stack -> base){
		while((stack -> base = malloc(size)) == NULL);
	};

	if (stack -> top - stack -> current < size){
		void* new_base = realloc(stack -> base,stack -> top + size);
		if (!new_base){
			nl_un_lock_t(&stack -> lock,&handle);
			return NL_ERR;
		} else {
			stack -> base = new_base;
			stack -> top += size;
		};
	};

	// copy data
	memcpy(stack -> base + stack -> current,source,size);
	stack -> current += size;

	nl_un_lock_t(&stack -> lock,&handle);

	return NL_OK;
};
int nl_pop_stack_t(struct nl_stack_t* stack,void* dest,nl_size_t size){
	nl_lock_h_t handle = nl_while_lock_t(&stack -> lock);
	if (!stack -> base){
	nl_un_lock_t(&stack -> lock,&handle);
		return NL_ERR;
	};

	if (stack -> current < size){
		size = stack -> current;
	};

	if (size > 0){
		stack -> current -= size;
		memcpy(dest,stack -> base + stack -> current,size);
	};
	nl_un_lock_t(&stack -> lock,&handle);
	return NL_OK;
};
int nl_clean_stack_t(struct nl_stack_t* stack){
	nl_lock_h_t handle = nl_while_lock_t(&stack -> lock);
	stack -> current = 0;
	nl_un_lock_t(&stack -> lock,&handle);
	return NL_OK;
};
int nl_destory_stack_t(struct nl_stack_t* stack){
	nl_lock_h_t handle = nl_while_lock_t(&stack -> lock);
	if (stack -> base){
		free(stack -> base);
	};
	stack -> top = 0;
	stack -> current = 0;
	nl_un_lock_t(&stack -> lock,&handle);
	return NL_OK;
};


struct nl_b_stack_t nl_create_b_stack_t(nl_size_t each_size){
	struct nl_b_stack_t stack;
	stack.stack = nl_create_stack_t();
	stack.each = each_size;
	return stack;
};
struct nl_b_stack_t nl_create_b_stack_t_i(nl_size_t each_size,nl_size_t initial_size){
	struct nl_b_stack_t stack;
	stack.stack = nl_create_stack_t_i(each_size * initial_size);
	stack.each = each_size;
	return stack;
};
int nl_push_b_stack_t(struct nl_b_stack_t* stack,void* source){
	return nl_push_stack_t(&stack -> stack,source,stack -> each);
};
int nl_pop_b_stack_t(struct nl_b_stack_t* stack,void* dest){
	return nl_pop_stack_t(&stack -> stack,dest,stack -> each);
};
int nl_clean_b_stack_t(struct nl_b_stack_t* stack){
	return nl_clean_stack_t(&stack -> stack);
};
int nl_destory_b_stack_t(struct nl_b_stack_t* stack){
	return nl_destory_stack_t(&stack -> stack);
};
