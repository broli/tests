#!/bin/bash

CFLAGS="-ggdb3 -Wall -Wextra -pedantic -ansi -Wmissing-prototypes -Wstrict-prototypes -Wcast-qual -Wcast-align -Wundef "

LIBS=""

gcc $CFLAGS $LIBS $1 -o $( basename $1 .c)
