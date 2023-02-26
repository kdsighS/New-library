/*
MIT License

Copyright (c) 2023 Free Noyhing

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "lock.h"
#include "header.h"
#include "math.h"

nl_lock_t nl_create_lock_t(unsigned int max){
	static nl_size_t seed = 1000;
	seed = nl_random(seed+1);
	nl_lock_t lock;
	lock.seed = nl_random(++seed);
	if (lock.seed <= 0){
		seed++;
	};
	lock.max = max;
	lock.now = 0;
	return lock;
};

nl_lock_h_t nl_try_lock_t(nl_lock_t* lock){
	if (lock -> now < lock -> max){
		nl_lock_h_t handle = nl_random(lock -> seed + lock -> now);
		handle = (handle << NL_SIZE_T_BIT / 2) | (handle & ((2 ^ NL_SIZE_T_BIT - 1) >> NL_SIZE_T_BIT / 2));
		handle = handle ^ lock -> seed;
		lock -> now++;
		return handle;
	} else {
		return NL_LOCK_ERR;
	};
};

nl_lock_h_t nl_while_lock_t(nl_lock_t* lock){
	while(lock -> now >= lock -> max);
	nl_lock_h_t handle = nl_random(lock -> seed);
	handle = (handle << NL_SIZE_T_BIT / 2) | (handle & ((2 ^ NL_SIZE_T_BIT - 1) >> NL_SIZE_T_BIT / 2));
	handle = handle ^ lock -> seed;
	lock -> now++;
	return handle;
};
int nl_un_lock_t(nl_lock_t* lock,nl_lock_h_t* handle){
	if (!lock || !handle){
		return NL_ERR;
	};
	if (*handle == NL_LOCK_ERR){
		return NL_ERR;
	};
	nl_lock_h_t temp_handle = *handle ^ lock -> seed;
	if((temp_handle << NL_SIZE_T_BIT / 2) == (temp_handle & ((2 ^ NL_SIZE_T_BIT - 1) >> NL_SIZE_T_BIT / 2))){
		lock -> now--;
		*handle = NL_LOCK_ERR;
		return NL_OK;
	} else {
		return NL_ERR;
	};
};
