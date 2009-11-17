#!/bin/bash

CFLAGS="-ggdb3 -Wall -Wextra -pedantic -ansi -Wmissing-prototypes -Wstrict-prototypes -Wcast-qual -Wcast-align -Wundef $(pkg-config --cflags mxml) "

LIBS=$(pkg-config --libs mxml)

gcc $CFLAGS $LIBS $1 -o $( basename $1 .c)
