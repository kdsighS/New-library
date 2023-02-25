/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

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

struct nl_log_t nl_create_log_t(char* file,unsigned int attr){
	FILE* dest;
	while((dest = fopen(file,"a+"))==NULL);
	nl_log_t log;
	log.lock = nl_create_lock_t(1);
	log.dest = dest;
	log.attr = attr;
	return log;
};
struct nl_log_t nl_create_log_t_f(FILE* dest,unsigned int attr){
	nl_log_t log;
	log.lock = nl_create_lock_t(1);
	log.dest = dest;
	log.attr = attr;
	return log;
};
int nl_put_log_t(struct nl_log_t* log,const char* expr,...){
	nl_lock_h_t lock = nl_while_lock_t(&log -> lock);
	print_attr_log_t(log -> dest,log -> attr);
	va_list vargs;
	va_start(vargs,expr);
	vfprintf(log -> dest,expr,vargs);
	va_end(vargs);
	fprintf(log -> dest,"\r\n");
	nl_un_lock_t(&log -> lock,&lock);
	return NL_OK;
};
int nl_destory_log_t(struct nl_log_t* log){
	nl_while_lock_t(&log -> lock);
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
