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
