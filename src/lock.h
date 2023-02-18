#ifndef __NEW_LIBRARY_LOCK_H__
#define __NEW_LIBRARY_LOCK_H__

typedef volatile struct _lock_t{
	unsigned int now;
	unsigned int max;
} lock_t;

lock_t create_lock_t(unsigned int max);
int try_lock_t(lock_t* lock);
int while_lock_t(lock_t* lock);
int un_lock_t(lock_t* lock);


#endif
