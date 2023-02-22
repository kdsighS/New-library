/*
MIT License

Copyright (c) 2023 Free Nothing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_NRC_RW_H__
#define __NEW_LIBRARY_NRC_RW_H__

#include "header.h"
#include "lock.h"

typedef struct nl_nrc_entry_t {
	nl_nrc_entry_t* next;
	struct {
		char* label;
		nl_size_t lenght;
	} label;
	struct {
		char* info;
		nl_size_t lenght;
	} info;
} nl_nrc_entry_t;

typedef struct nl_nrc_t {
	nl_lock_t lock;
	struct {
		nl_nrc_entry_t* entry;
		nl_size_t count;
	} entry;
	struct {

	} info;
} nl_nrc_t;

#endif
