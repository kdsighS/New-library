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
