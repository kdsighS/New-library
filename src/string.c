/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "string.h"
#include <string.h>

int nl_strcmp(const char* string_a,const char* string_b){
#if 0
	for (;*string_a == *string_b && *string_a;string_a++,string_b++);
	return *(unsigned char*)string_a - *(unsigned char*)string_b;
#endif
	return strcmp(string_a,string_b);
};

void* nl_memcpy(void* dest,const void* src,nl_size_t size){
#if 0
	unsigned char* d = dest;
	const unsigned char* s = src;
	for (; size; size--) *d++ = *s++;
	return dest;
#endif
	return memcpy(dest,src,size);
};

int nl_strncmp(const char* a,nl_size_t a_l,const char* b,nl_size_t b_l){
	a_l = a_l <= b_l ? a_l : b_l;
	return strncmp(a,b,a_l);
};
