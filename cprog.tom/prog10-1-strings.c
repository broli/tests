/* prog10-1.c: strings */

#include <stdio.h>
#include <string.h>

int main(void)
{
   char s[20];

   strcpy(s, "strings");

   printf("s = %s\n", s);
   printf("s[3] = %c\n", s[3]);
   printf("s[6] = %c\n", s[6]);
   printf("s[7] = %d\n", s[7]);
   printf("strlen(s) = %lu\n",(unsigned long)strlen(s));

   strcat(s, " program");
   printf("s now = %s\n", s);
   printf("strlen(s) = %lu\n",(unsigned long)strlen(s));

   return 0;
}

