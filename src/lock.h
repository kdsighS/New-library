#ifndef __NEW_LIBRARY_LOCK_H__
#define __NEW_LIBRARY_LOCK_H__

typedef volatile struct lock_t{
	unsigned int now;
	unsigned int max;
} lock_t;

struct lock_t create_lock_t(unsigned int max);
int try_lock_t(struct lock_t* lock);
int while_lock_t(struct lock_t* lock);
int un_lock_t(struct lock_t* lock);


#endif