/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_HASHMAP_H__
#define __NEW_LIBRARY_HASHMAP_H__

#include "header.h"

struct nl_hashmap_node_t {
	struct {
		nl_size_t size;
		void* name;
	} entry;
	struct {
		nl_size_t size;
		void* data;
	} data;
	struct nl_hashmap_node_t* next;
};

typedef struct nl_hashmap_t {
	nl_size_t size;
	struct nl_hashmap_node_t** entrys;
	nl_size_t (*hash)(void* data,nl_size_t lenght);
} nl_hashmap_t;

struct nl_hashmap_t nl_create_hashmap_t(nl_size_t size);
int nl_add_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void* data,nl_size_t data_lenght);
int nl_get_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void* dest,nl_size_t dest_lenght);
int nl_get_hashmap_t_m(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void** dest,nl_size_t dest_lenght);
int nl_delete_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght);
int nl_destory_hashmap_t(struct nl_hashmap_t* map);

nl_size_t nl_hash_hashmap_t(void* data,nl_size_t size);

#endif
