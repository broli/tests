/* prog15-2.c: module 2 */

#include <stdio.h>

int myvariable = 42;

void myfunction(int number)
{
   printf("This is %s. The sum of number and myvariable is %d.\n",
          __FILE__, number+myvariable);
}


