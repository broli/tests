/* prog10-3.c: command line arguments */

#include <stdio.h>

int main(int argc, char *argv[])
{
   int i;

   printf("There are %d command line arguments\n", argc);

   for (i=0; i < argc; i++)
   {
      printf("Command line argument number %d = %s\n", i, argv[i]);
   }

   return 0;
}

