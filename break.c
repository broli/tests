#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************
* gcc -Wall -g -Wextra break.c -o break
*******************************************/

#define SIZE 40


void loop (void)
{
	int square_y, square_x;

	printf ("\n");

	for (square_y = 1; square_y <= SIZE; square_y++)
	{
	     for (square_x = 1; square_x <= SIZE; square_x++)
	     {
	         printf("*");
		if ( square_x == 10 )
	   	   {
	   		printf("break");
			break;
	   	   }

	     }
	   	   printf ("\n");
	}

}

int main(int argc, char *argv[])
{
 	loop();	
	printf("\n");
	return 0;
}
