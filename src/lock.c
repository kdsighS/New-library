#include "lock.h"
#include "header.h"

struct lock_t create_lock_t(unsigned int max){
	struct lock_t lock;
	lock.max = max;
	lock.min = 0;
	return lock;
};
int try_lock_t(struct lock_t* lock){
	if (lock -> now < lock -> max){
		lock -> now++;
		return NL_OK;
	} else {
		return NL_ERR;
	};
};
int while_lock_t(struct lock_t* lock){
	while(lock -> now >= lock ->max);
	lock -> now++;
};
int un_lock_t(struct lock_t* lock){
	lock -> now--;
};