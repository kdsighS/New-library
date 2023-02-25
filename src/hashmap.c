/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "hashmap.h"
#include "string.h"
#include "malloc.h"

struct nl_hashmap_t nl_create_hashmap_t(nl_size_t size){
	struct nl_hashmap_t hashmap;
	do{
		hashmap.entrys = nl_malloc(sizeof(struct nl_hashmap_node_t*)*size);
	} while(!hashmap.entrys);
	hashmap.size = size;
	for (nl_size_t i = 0;i < size;i++){
		hashmap.entrys[i] = NULL;
	};
	hashmap.hash = nl_hash_hashmap_t;
	return hashmap;
};
int nl_add_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void* data,nl_size_t data_lenght){
	if (!map || !name || !data){
		return NL_ERR;
	};
	nl_size_t hash = map -> hash(name,name_lenght);
	hash %= map -> size;
	struct nl_hashmap_node_t** map_node = &map -> entrys[hash];
	while (*map_node){
		if (!nl_strncmp((*map_node) -> entry.name,(*map_node) -> entry.size,name,name_lenght)){
			void* data_buffer = nl_malloc(data_lenght);
			if (!data_buffer){
				return NL_ERR;
			};
			nl_memcpy(data_buffer,data,data_lenght);
			nl_free((*map_node) -> data.data);
			(*map_node) -> data.data = data_buffer;
			(*map_node) -> data.size = data_lenght;
			return NL_OK;
		};
		map_node = &(*map_node) -> next;
	};
	struct nl_hashmap_node_t* node = nl_malloc(sizeof(struct nl_hashmap_node_t));
	if(!node){
		return NL_ERR;
	};
	void* data_buffer = nl_malloc(data_lenght);
	if (!data_buffer){
		nl_free(node);
		return NL_ERR;
	};
	void* name_buffer = nl_malloc(name_lenght);
	if (!name_buffer){
		nl_free(data_buffer);
		nl_free(node);
		return NL_ERR;
	};
	nl_memcpy(name_buffer,name,name_lenght);
	nl_memcpy(data_buffer,data,data_lenght);
	node -> entry.name = name_buffer;
	node -> entry.size = name_lenght;
	node -> data.data = data_buffer;
	node -> data.size = data_lenght;
	node -> next = NULL;
	*map_node = node;
	return NL_OK;
};
int nl_get_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void* dest,nl_size_t dest_lenght){
	if (!map || !name){
		return NL_ERR;
	};
	nl_size_t hash = map -> hash(name,name_lenght);
	hash %= map -> size;
	struct nl_hashmap_node_t** map_node = &map -> entrys[hash];
	while (*map_node){
		if (!nl_strcmp((*map_node) -> entry.name,name)){
			dest_lenght = dest_lenght >= (*map_node) -> data.size ? dest_lenght : (*map_node) -> data.size;
			nl_memcpy(dest,(*map_node) -> data.data,dest_lenght);
			return NL_OK;
		};
		map_node = &(*map_node) -> next;
	};
	return NL_ERR;
};
int nl_get_hashmap_t_m(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght,void** dest,nl_size_t dest_lenght){
	void* buffer = nl_malloc(dest_lenght);
	if (!buffer){
		return NL_ERR;
	};
	if (nl_get_hashmap_t(map,name,name_lenght,buffer,dest_lenght) == NL_OK){
		*dest = buffer;
		return NL_OK;
	};
	return NL_ERR;
};
int nl_delete_hashmap_t(struct nl_hashmap_t* map,void* name,nl_size_t name_lenght){
	if (!map || !name){
		return NL_ERR;
	};
	nl_size_t hash = map -> hash(name,name_lenght);
	hash %= map -> size;
	struct nl_hashmap_node_t** map_node = &map -> entrys[hash];
	struct nl_hashmap_node_t** map_node_pv = NULL;
	while (*map_node){
		if (!nl_strcmp((*map_node) -> entry.name,name)){
			struct nl_hashmap_node_t* node = *map_node;
			if (!map_node_pv){
				map_node_pv = map_node;
			};
			*map_node_pv = (*map_node) -> next;
			nl_free(node -> data.data);
			nl_free(node -> entry.name);
			nl_free(node);
			return NL_OK;
		};
		map_node_pv = map_node;
		map_node = &(*map_node) -> next;
	};
	return NL_ERR;
};
int nl_destory_hashmap_t(struct nl_hashmap_t* map){

};

nl_size_t nl_hash_hashmap_t(void* d,nl_size_t size){
	const char* data = d;
	nl_size_t hash = 0;
	for (;size;size--){
		hash += data[size];
		hash *= data[size];
	};
	return hash;
};
