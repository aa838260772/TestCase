#!/bin/bash
gcc test.c -I./lua/include/ -L ./lua/lib/ -llua -lm -ldl
