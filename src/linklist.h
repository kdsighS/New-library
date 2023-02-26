/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_LINKLIST_H__
#define __NEW_LIBRARY_LINKLIST_H__

#include "header.h"

#define NL_LINKLIST_NONE	0b00000000
#define NL_LINKLIST_AFTER	0b00000001
#define NL_LINKLIST_HERE	0b00000010
#define NL_LINKLIST_BEFORE	0b00000100

struct nl_linklist_node_t {
	struct {
		void* data;
		nl_size_t size;
	} data;
	struct nl_linklist_node_t* prev;
	struct nl_linklist_node_t* next;
};

typedef struct nl_linklist_t {
	struct nl_linklist_node_t* node;
	nl_size_t size;
} nl_linklist_t;

nl_linklist_t nl_create_linklist_t(void);
nl_ushort_t nl_insert_linklist_t(nl_linklist_t* list,nl_ushort_t attr,void* data,nl_size_t size);
nl_short_t nl_get_linklist_t(nl_linklist_t* list,nl_ushort_t attr,void** buffer);
nl_short_t nl_delete_linklist_t(nl_linklist_t* list,nl_ushort_t attr);
nl_short_t nl_destory_linklist_t(nl_linklist_t* list);
nl_short_t nl_move_linklist_t(nl_linklist_t* list,nl_size_t step,nl_ushort_t attr);

#endif

