#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iconv.h>
#include <wchar.h>
#include <string.h>


/*
 gcc -Wall -Wextra -pedantic -ggdb3  whatlocale.c -o whatlocale
*/

  int main(void)
  {
    struct lconv *loc=NULL;
    char *Alocale=NULL;
    wchar_t *currency=NULL;
    
    Alocale = setlocale(LC_CTYPE, NULL);
    printf("antes: %s\n--------------------------------\n",Alocale);
    loc = localeconv ();
    currency = malloc ( strlen (loc->int_curr_symbol) );
    mbstowcs ( currency,loc->int_curr_symbol,strlen (loc->int_curr_symbol));
    printf("plata: %ls-\n",currency);
    free ( currency);

    Alocale = setlocale(LC_CTYPE, "");
    printf("despues: %s\n------------------------------\n",Alocale);
    loc = localeconv ();

    currency = malloc ( strlen (loc->int_curr_symbol) );
    mbstowcs ( currency,loc->int_curr_symbol,strlen (loc->int_curr_symbol));
    printf("plata: %ls-\n",currency);
    free ( currency);
    
    return 0;
  }

