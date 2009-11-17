#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 gcc -Wall Wextra -std=c99 file-macro.c -o file-macro
 * */

int main(void)
{
	printf("%s",__FILE__);

	return EXIT_SUCCESS;
}

