/* prog15-1.c: module 1 */

#include <stdio.h>

#include "prog15-2.h"

int main(void)
{
   myfunction(25);

   printf("This is %s. The value of myvariable is %d\n",
          __FILE__, myvariable);

   return 0;
}

