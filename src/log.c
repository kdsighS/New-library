#include "header.h"
#include "log.h"
#include "lock.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>

#if defined __WIN32
#include <process.h>
#define getpid() _getpid()
#elif defined __linux__
#include <sys/types.h>
#endif

static int print_attr_log_t(FILE* dest,unsigned int attr);

struct log_t create_log_t(char* file,unsigned int attr){
	FILE* dest;
	while((dest = fopen(file,"a+"))==NULL);
	log_t log;
	log.lock = create_lock_t(1);
	log.dest = dest;
	log.attr = attr;
	return log;
};
struct log_t create_log_t_f(FILE* dest,unsigned int attr){
	log_t log;
	log.lock = create_lock_t(1);
	log.dest = dest;
	log.attr = attr;
	return log;
};
int put_log_t(struct log_t* log,const char* expr,...){
	while_lock_t(&log -> lock);
	print_attr_log_t(log -> dest,log -> attr);
	va_list vargs;
	va_start(vargs,expr);
	vfprintf(log -> dest,expr,vargs);
	va_end(vargs);
	fprintf(log -> dest,"\r\n");
	un_lock_t(&log -> lock);
	return NL_OK;
};
int destory_log_t(struct log_t* log){
	while_lock_t(&log -> lock);
	return NL_OK;
};
static int print_attr_log_t(FILE* dest,unsigned int attr){
	if (attr > 0){
		if ((attr & NL_LOG_TIME) > 0){
			fprintf(dest,"[%-9ld]",time(NULL));
		};if ((attr & NL_LOG_DATE) > 0){
			time_t  now = time(NULL);
			struct tm* tm = localtime(&now);
			char now_string[64];
			strftime(now_string,sizeof(char)*64,"%Y-%x-%X",tm);
			fprintf(dest,"[%-9s]",now_string);
		};
		if ((attr & NL_LOG_PID) > 0){
			fprintf(dest,"[%-6d]",getpid());
		};
	};
	return NL_OK;
};
