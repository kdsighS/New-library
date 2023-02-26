/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __NEW_LIBRARY_HEADER_H__
#define __NEW_LIBRARY_HEADER_H__

#define NEW_LIBRARY_VERSION_MAJOR 0
#define NEW_LIBRARY_VERSION_MINOR 0
#define NEW_LIBRARY_VERSION_PATCH 1

#define NEW_LIBRARY_VERSION_STRING "Pre-alpha 0.0.1"

#define NL_OK 1
#define NL_ERR 0

typedef short nl_short_t;
typedef unsigned short nl_ushort_t;
typedef long nl_long_t;
typedef unsigned long nl_ulong_t;
typedef unsigned long nl_size_t;

#define NL_SHORT_SIZE sizeof(nl_short_t)
#define NL_SHORT_BIT (NL_SHORT_SIZE * 8)
#define NL_USHORT_SIZE sizeof(nl_Ushort_t)
#define NL_USHORT_BIT (NL_USHORT_SIZE * 8)
#define NL_LONG_T_SIZE sizeof(nl_long_t)
#define NL_LONG_T_BIT (NL_LONG_T_SIZE * 8)
#define NL_ULONG_T_SIZE sizeof(nl_Ulong_t)
#define NL_ULONG_T_BIT (NL_ULONG_T_SIZE * 8)
#define NL_SIZE_T_SIZE sizeof(nl_size_t)
#define NL_SIZE_T_BIT (NL_SIZE_T_SIZE * 8)

#ifndef NULL
#define NULL (void*)0x0
#endif

#endif
