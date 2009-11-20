#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <iconv.h>

int main(int argc, char *argv[])
{
	char *CurLocale=NULL; /*var to hold the current locale*/

	CurLocale = setlocale(LC_ALL, "");/* set the user's env locale*/
	if ( CurLocale == NULL )
	{
		perror("Warning: Cant set locale, check your env\n");
	}


	return EXIT_SUCCESS;
}

