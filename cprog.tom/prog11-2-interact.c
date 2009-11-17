/* prog11-2.c: interact */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
   char name[20];
   char buffer[10];
   char *p;
   int age, ok;

   printf("Enter your name: ");
   fflush(stdout);

   if (fgets(name, sizeof name, stdin) == NULL)
   {
      printf("Error reading name from stdin\n");
      return EXIT_FAILURE;
   }

   p = strchr(name,'\n');
   if (p!=NULL)
      *p = '\0';

   fprintf(stdout, "Welcome, %s!\n", name);

   do
   {
      printf("Enter your age [1-150]: ");
      fflush(stdout);
      if (fgets(buffer, sizeof buffer, stdin) != NULL
          && sscanf(buffer, "%d", &age) == 1
          && age>=1 && age<=150)
      {
         ok = 1;
      }
      else
      {
         ok = 0;
         printf("Invalid age! Enter again...\n");
      }
   }
   while (!ok);

   printf("Your age now is %d. In 10 years your age will be %d.\n",
          age, age+10);

   return EXIT_SUCCESS;
}

