/* prog11-1.c: fileio */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	size_t cantidad_pedida=10; 
	int cantidad_leida;	
	char *string;

	//string = (char *) malloc ( cantidad_pedida +1);
	printf("la funcion espera 10 nomas\n");

	cantidad_leida = getline ( &string, &cantidad_pedida, stdin);

	printf("tamaño del string %d\n",sizeof(string));
	printf("largo del string %d\n",strlen(string));


	free (string);


	return EXIT_SUCCESS;
}

