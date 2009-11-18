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
    
    Alocale = setlocale(LC_CTYPE, NULL);
    printf("before: %s\n--------------------------------\n",Alocale);
    loc = localeconv ();
    printf("plata: %s-\n",loc->currency_symbol);

    Alocale = setlocale(LC_CTYPE, "");
    printf("after: %s\n------------------------------\n",Alocale);
    loc = localeconv ();

    printf("plata: %s-\n",loc->currency_symbol);
    
    return 0;
  }

