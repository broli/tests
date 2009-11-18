/* prog11-1.c: fileio */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <locale.h>


/*
 gcc -Wall -Wextra -pedantic -ggdb3  utf8io.c -o utf8io
 for some f**** reason this always ALWAYS works, even without the set locale and with any LC_ALL in the unix env
 */

int main(void)
{

	size_t cantidad_pedida=10; 
	char *string=NULL;
	FILE *unifile=NULL;

	if ( setlocale(LC_ALL, "") == NULL )
	{
		printf("Error setting the locale\n");
		printf("Errno %d\n",errno);
		return EXIT_FAILURE;
	}

	unifile = fopen("UTF-8-demo.html","r");
	if ( unifile == NULL)
	{
		printf("Error opening file\n");
		printf("Errno %d\n",errno);
		return EXIT_FAILURE;
	}
	while ( getline ( &string, &cantidad_pedida, unifile) != -1 )
	{
		printf("%s",string);
	}

	fclose(unifile);
	free (string);
	return EXIT_SUCCESS;
}

