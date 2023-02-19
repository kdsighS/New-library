# MIT License
#
# Copyright (c) 2023 Free Nothing
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

ROOT=$(shell pwd)
BUILD=$(ROOT)/build
BUILD_LIB=$(BUILD)/lib
BUILD_INCLUDE=$(BUILD)/include
SRC=$(ROOT)/src
INCLUDE=$(ROOT)/include

.PHONY:ALL

ALL:
	@echo "Try HELP."

.PHONY:COMPILE

COMPILE:
	cd $(SRC) && make INCLUDE=$(INCLUDE) ROOT=$(ROOT) SRC=$(SRC) -f Makefile
	cp $(SRC)/*.o $(BUILD_LIB)
	cp $(SRC)/*.h $(BUILD_INCLUDE)
	$(shell test -e $(BUILD_LIB)/libnlibrary.a || rm $(BUILD_LIB)/libnlibrary.a)
	ar -q $(BUILD_LIB)/libnlibrary.a $(BUILD_LIB)/*.o
	rm $(SRC)/*.o
.PHONY:CLEAN

CLEAN:
	rm $(BUILD) -r
