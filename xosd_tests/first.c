#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <xosd.h>

int main (int argc, char *argv[])
{
  xosd *osd;
  setlocale(LC_ALL, "");
  osd = xosd_create (2);
  if (osd == NULL)
    {
      perror ("Could not create \"osd\"");
      exit (1);
    }
  xosd_set_font (osd, "-*-verdana-*-*-*-*-17-*-*-*-*-*-*-*");  
  xosd_display (osd, 0, XOSD_string, "verdana 17-----------------------------------------------------------------------");
  sleep (2);
  /* el segundo*/
  xosd_set_shadow_offset (osd, 4);
  xosd_set_font (osd, "-*-terminus-*-*-*-*-20-*-*-*-*-*-*-*");
  xosd_set_colour (osd, "white");
  xosd_set_pos (osd, XOSD_bottom);
  xosd_set_align (osd, XOSD_center);
  xosd_set_vertical_offset (osd, 48);
  xosd_display (osd, 0, XOSD_string, "terminus 20 con shadow y otro color");
  sleep (8);
  xosd_destroy (osd);
  exit (0);
}
