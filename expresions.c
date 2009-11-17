#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************
* gcc -Wall -g -Wextra expresions.c -o exp *
*******************************************/

int main(int argc, char *argv[])
{
	if(0)
	{
		printf("if 0 es verdad\n");
	}
	else
	{
		printf("if 0 es mentira\n");
	}

	if(-1)
	{
		printf("if -1 es verdad\n");
	}
	else
	{
		printf("if -1 es mentira\n");
	}


	if(1)	
	{
		printf("if 1 es verdad\n");
	}
	else
	{
		printf("if 1 es mentira\n");
	}

	return 0;
}
