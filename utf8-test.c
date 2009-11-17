#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 gcc -Wall -ggdb utf8-test.c -o utf8-test
 * */

int main(void)
{
	char *foo=NULL; 
	size_t cantidad=1;
	int cantidad_leida;

	printf("muestro caracteres unicode ññóóáíñoño|@·~·½{[]}[{¬½\n");

	printf("ingresá caracteres unicode\n");
	foo = malloc (cantidad + 1);
	cantidad_leida = getline (&foo,&cantidad,stdin);

	if ( cantidad == -1)
		return EXIT_FAILURE;
	
	printf("%d: leimos %s\n",cantidad,foo);
	
	free (foo);


	return EXIT_SUCCESS;
}

