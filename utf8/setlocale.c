#include <stdio.h>
#include <locale.h>


/*
 gcc -Wall -Wextra -pedantic -ggdb3  setlocale.c -o setlocale
*/

  int main()
  {
    if (!setlocale(LC_CTYPE, "es_AR.UTF-8")) {
      fprintf(stderr, "Can't set the specified locale! "
              "Check LANG, LC_CTYPE, LC_ALL.\n");
      return 1;
    }
    printf("%ls\n", L"Schöne Grüße");
    return 0;
  }

