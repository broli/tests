#include <stdlib.h>
#include <stdio.h>

struct angles {
		int anglea;
		int angleb;
		};

struct triangle {
            int sidea;
            int sideb;
            int sidec;
	    struct angles idad;
            };

void settriangle (struct triangle *param)
{
   param->sidea = 1;
   param->sideb = 1;
   param->sidec = 1;
   param->idad.anglea=300;
   param->idad.angleb=60;

}

int main(void)
{
   struct triangle *mytriangle=NULL;
   mytriangle = malloc (sizeof (struct triangle) );
   settriangle (mytriangle);
   printf ("%d %d %d \n",mytriangle->sidea,mytriangle->sideb,mytriangle->sidec);
   printf ("angles %d %d\n",mytriangle->idad.anglea,mytriangle->idad.angleb);
   free(mytriangle);
   return 0;
}

