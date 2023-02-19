/*
MIT License

Copyright (c) 2023 Free Nothing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_LOCK_H__
#define __NEW_LIBRARY_LOCK_H__

<<<<<<< HEAD
#include "header.h"

typedef volatile struct _nl_lock_t{
	nl_size_t now;
	nl_size_t max;
	nl_size_t seed;
} nl_lock_t;


typedef volatile nl_size_t nl_lock_h_t;

#define NL_LOCK_ERR 0x0


nl_lock_t nl_create_lock_t(unsigned int max);
nl_lock_h_t nl_try_lock_t(nl_lock_t* lock);
nl_lock_h_t nl_while_lock_t(nl_lock_t* lock);
int nl_un_lock_t(nl_lock_t* lock,nl_lock_h_t* handle);
#endif
