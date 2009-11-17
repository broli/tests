/* prog10-2.c: pointers */

#include <stdio.h>

int main(void)
{
   int a[] = {1,2,3,5,7,11,13,17,19};
   int *p;

   printf("a[4] = %d\n", a[4]);

   printf("the address of the array = %p\n", (void *)a);
   printf("the address of element nr. 0 of the array = %p\n", (void *)&a[0]);
   printf("the address of element nr. 4 of the array = %p\n", (void *)&a[4]);

   p = a;

   printf("the value of the pointer = %p\n", (void *)p);
   printf("the value the pointer points at = %d\n", *p);

   p += 4;

   printf("the value of the pointer now = %p\n", (void *)p);
   printf("the value the pointer now points at = %d\n", *p);

   return 0;
}

