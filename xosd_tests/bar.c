#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <xosd.h>

/* http://ldots.org/xosd-guide/using_libxosd.html 
 * para compilar gcc `xosd-config --cflags --libs` nombre.c -o nombresalida 
 * */

int main (int argc, char *argv[])
{
  int porcentaje = 0;
  porcentaje = atoi(argv[1]);
  xosd *osd;
  setlocale(LC_ALL, "");
  osd = xosd_create (2);
  if (osd == NULL)
    {
      perror ("Could not create \"osd\"");
      exit (1);
    }
  xosd_set_shadow_offset (osd, 4);
  xosd_set_font (osd, "-*-terminus-*-*-*-*-32-*-*-*-*-*-*-*");
  xosd_set_colour (osd, "green");
  xosd_set_pos (osd, XOSD_bottom);
  xosd_set_align (osd, XOSD_center);
  xosd_set_vertical_offset (osd, 50);
  xosd_display (osd, 0, XOSD_percentage, porcentaje);
  sleep (1);
  xosd_destroy (osd);
  exit (0);
}
