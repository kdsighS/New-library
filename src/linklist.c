/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "linklist.h"
#include "malloc.h"
#include "string.h"

nl_linklist_t nl_create_linklist_t(void){
	struct nl_linklist_t list;
	list.node = NULL;
	list.size = 0;
	return list;
};

nl_ushort_t nl_insert_linklist_t(nl_linklist_t* list,nl_ushort_t attr,void* data,nl_size_t size){
	if (!list || !data){
		return NL_ERR;
	};
	if (attr & NL_LINKLIST_NONE){
		return NL_OK;
	} else {
		struct nl_linklist_node_t* node;
		node = nl_malloc(sizeof(struct nl_linklist_node_t));
		if (!node){
			return NL_ERR;
		};
		void* data_buffer = nl_malloc(size);
		if (!data_buffer){
			nl_free(node);
			return NL_ERR;
		};
		nl_memcpy(data_buffer,data,size);
		node -> data.data = data_buffer;
		node -> data.size = size;
		if (!list -> node){
			list -> node = node;
			node -> next = NULL;
			node -> prev = NULL;
			return NL_OK;
		};

		if (attr & NL_LINKLIST_AFTER){
			node -> next = list -> node -> next;
			node -> prev = list -> node;
			list -> node -> next = node;
		} else if (attr & NL_LINKLIST_BEFORE){
			node -> prev = list -> node -> prev;
			node -> next = list -> node;
			list -> node -> prev = node;
		} else {
			list -> node -> data = node -> data;
			nl_free(node);
		};

		list -> size++;
		return NL_OK;
	};
};
nl_short_t nl_get_linklist_t(nl_linklist_t* list,nl_ushort_t attr,void** buffer){
	if (!list || !buffer){
		return NL_ERR;
	};
	if (!list -> node){
		return NL_ERR;
	};
	struct nl_linklist_node_t* data_src;
	if (attr & NL_LINKLIST_HERE){
		data_src = list -> node;
	} else if (attr & NL_LINKLIST_BEFORE){
		if (!list -> node -> prev){
			return NL_ERR;
		};
		data_src = list -> node -> prev;
	} else if (attr & NL_LINKLIST_AFTER){
		if (!list -> node -> next){
			return NL_ERR;
		};
		data_src = list -> node -> next;
	} else {
		return NL_ERR;
	};
	void* data_buffer = nl_malloc(data_src -> data.size);
	if (!data_buffer){
		return NL_ERR;
	};
	nl_memcpy(data_buffer,data_src -> data.data,data_src -> data.size);
	*buffer = data_buffer;
	return NL_OK;
};
nl_short_t nl_delete_linklist_t(nl_linklist_t* list,nl_ushort_t attr){
	if (!list || !list -> node){
		return NL_ERR;
	};
	switch(attr){
		case NL_LINKLIST_HERE:
			{
				struct nl_linklist_node_t* node = list -> node;
				if (list -> node -> prev){
					list -> node -> prev -> next = list -> node -> next;
				};
				if (list -> node -> next){
					list -> node -> next -> prev = list -> node -> prev;
				};
				list -> node = list -> node -> prev ? list -> node -> prev : list -> node -> next;
				nl_free(node -> data.data);
				nl_free(node);
			};
			break;
		case NL_LINKLIST_AFTER:
			{
				if (!list -> node -> next){
					return NL_ERR;
				};
				struct nl_linklist_node_t* node = list -> node -> next;
				if (list -> node -> next -> next){
					list -> node -> next -> next -> prev = list -> node;
				};
				list -> node -> next = list -> node -> next -> next;
				nl_free(node -> data.data);
				nl_free(node);
			};
			break;
		case NL_LINKLIST_BEFORE:
			{
				if (!list -> node -> prev){
					return NL_ERR;
				};
				struct nl_linklist_node_t* node = list -> node -> prev;
				if (list -> node -> prev -> prev){
					list -> node -> prev -> prev -> next = list -> node;
				};
				list -> node -> prev = list -> node -> prev -> prev;
				nl_free(node -> data.data);
				nl_free(node);
			};
			break;
		default:
			return NL_ERR;
	};
	list -> size--;
	return NL_OK;
};
nl_short_t nl_destory_linklist_t(nl_linklist_t* list){
	if (!list || !list -> node){
		return NL_ERR;
	};
	nl_move_linklist_t(list,list -> size,NL_LINKLIST_BEFORE);
	for (;list -> size && list -> node;list -> size--){
		struct nl_linklist_node_t* node = list -> node;
		list -> node = list -> node -> next;
		nl_free(node -> data.data);
		nl_free(node);
	};
	return NL_OK;
};
nl_short_t nl_move_linklist_t(nl_linklist_t* list,nl_size_t step,nl_ushort_t attr){
	if (!list || !list -> node){
		return NL_ERR;
	};
	switch(attr){
		case NL_LINKLIST_HERE:
			return NL_OK;
		case NL_LINKLIST_AFTER:
			for (;step && list -> node -> next;step--){
				list -> node = list -> node -> next;
			};
			return NL_OK;
		case NL_LINKLIST_BEFORE:
			for (;step && list -> node -> prev;step--){
				list -> node = list -> node -> prev;
			};
			return NL_OK;
		default:
			return NL_ERR;
	};
};
