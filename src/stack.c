#include "stack.h"
#include <malloc.h>
#include <string.h>

struct stack_t create_stack_t(void){
	struct stack_t stack;
	stack.lock = create_lock_t(1);
	stack.base = NULL;
	stack.current = 0;
	stack.top = 0;
	return stack;
};
struct stack_t create_stack_t_i(size_t initial_size){
	struct stack_t stack;
	stack = create_stack_t();
	while((stack.base = malloc(initial_size)) == NULL);
	return stack;
};
int push_stack_t(struct stack_t* stack,void* source,size_t size){
	while_lock_t(&stack -> lock);
	if (!stack -> base){
		while((stack -> base = malloc(size)) == NULL);
	};

	if (stack -> top - stack -> current < size){
		void* new_base = realloc(stack -> base,stack -> top + size);
		if (!new_base){
			un_lock_t(&stack -> lock);
			return NL_ERR;
		} else {
			stack -> base = new_base;
			stack -> top += size;
		};
	};

	// copy data
	memcpy(stack -> base + stack -> current,source,size);
	stack -> current += size;

	un_lock_t(&stack -> lock);

	return NL_OK;
};
int pop_stack_t(struct stack_t* stack,void* dest,size_t size){
	while_lock_t(&stack -> lock);
	if (!stack -> base){
		un_lock_t(&stack -> lock);
		return NL_ERR;
	};

	if (stack -> current < size){
		size = stack -> current;
	};

	if (size > 0){
		stack -> current -= size;
		memcpy(dest,stack -> base + stack -> current,size);
	};
	un_lock_t(&stack -> lock);
	return NL_OK;
};
int clean_stack_t(struct stack_t* stack){
	while_lock_t(&stack -> lock);
	stack -> current = 0;
	un_lock_t(&stack -> lock);
	return NL_OK;
};
int destory_stack_t(struct stack_t* stack){
	while_lock_t(&stack -> lock);
	if (stack -> base){
		free(stack -> base);
	};
	stack -> top = 0;
	stack -> current = 0;
	un_lock_t(&stack -> lock);
	return NL_OK;
};


struct b_stack_t create_b_stack_t(size_t each_size){
	struct b_stack_t stack;
	stack.stack = create_stack_t();
	stack.each = each_size;
	return stack;
};
struct b_stack_t create_b_stack_t_i(size_t each_size,size_t initial_size){
	struct b_stack_t stack;
	stack.stack = create_stack_t_i(each_size * initial_size);
	stack.each = each_size;
	return stack;
};
int push_b_stack_t(struct b_stack_t* stack,void* source){
	return push_stack_t(&stack -> stack,source,stack -> each);
};
int pop_b_stack_t(struct b_stack_t* stack,void* dest){
	return pop_stack_t(&stack -> stack,dest,stack -> each);
};
int clean_b_stack_t(struct b_stack_t* stack){
	return clean_stack_t(&stack -> stack);
};
int destory_b_stack_t(struct b_stack_t* stack){
	return destory_stack_t(&stack -> stack);
};
