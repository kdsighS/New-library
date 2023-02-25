/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_NET_H__
#define __NEW_LIBRARY_NET_H__

#include "header.h"
#include "lock.h"

typedef struct net_socket_t {
	int socket;
	struct {
		char* address;
		unsigned int len;
		int port;
	} address;
	unsigned int attr;
	union {
		struct {
			unsigned int :32;
			unsigned int :32;
			unsigned int :32;
			unsigned int :32;
		};
		struct {
			lock_t lock;
		} lock;
	} exter;
} net_socket_t;

struct net_status_t {
	struct {
		char* address;
		unsigned int len;
		int port;
	} address;
	unsigned int attr;
};

/*

	suffix:
		a		means address.
		l		means locks.
		t		means attrs.
	order:	alt
*/

struct net_socket_t create_net_socket_t(void);
struct net_socket_t create_net_socket_t_a(char* address,unsigned int len);
struct net_socket_t create_net_socket_t_l(void);
struct net_socket_t create_net_socket_t_t(unsigned int attr);
struct net_socket_t create_net_socket_t_al(char* address,unsigned int len);
struct net_socket_t create_net_socket_t_at(char* address,unsigned int len);
struct net_socket_t create_net_socket_t_lt(unsigned int attr);
struct net_socket_t create_net_socket_t_alt(char* address,unsigned int len,unsigned int attr);

struct net_status_t status_net_socket_t(struct net_socket_t socket,struct net_socket_t* status);

int send_net_socket_t(struct net_socket_t* socket,void* source,size_t size);
int recv_net_socket_t(struct net_socket_t* socket,void* buffer,size_t size);

int lock_net_socket_t(struct net_socket_t* socket);

int destory_net_socket_t(struct net_socket_t* socket);

#endif
