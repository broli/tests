#include <stdio.h>
#include <locale.h>


/*
 gcc -Wall -Wextra -pedantic -ggdb3  whatlocale.c -o whatlocale
*/

  int main(void)
  {
    struct lconv *loc=NULL;
    char *Alocale=NULL;
    
    Alocale = setlocale(LC_CTYPE, NULL);
    printf("antes: %s\n--------------------------------\n",Alocale);
    loc = localeconv ();
    printf("plata: %s-\n",loc->int_curr_symbol);
    Alocale = setlocale(LC_CTYPE, "");
    printf("despues: %s\n------------------------------\n",Alocale);
    loc = localeconv ();
    printf("plata: %s-\n",loc->int_curr_symbol);
    
    return 0;
  }

