#include <stdlib.h>
#include <stdio.h>

struct triangle {
            int sidea;
            int sideb;
            int sidec;
            };

void settriangle (struct triangle *param)
{
   param->sidea = 1;
   param->sideb = 1;
   param->sidec = 1;
}

int main(void)
{
   struct triangle *mytriangle=NULL;
   mytriangle = malloc (sizeof (struct triangle) );
   settriangle (mytriangle);
   printf ("%d %d %d",mytriangle->sidea,mytriangle->sideb,mytriangle->sidec);
   free(mytriangle);
   return 0;
}

