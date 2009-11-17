/*http://swishewiki.org/sw/index.php/Unicode_C_Example */




/* Beginner's exercise in UTF-8 programming
 *  * From http://mail.nl.linux.org/linux-utf8/2001-07/msg00070.html
 *   *
 *    *   * To: linux-utf8@nl.linux.org (linux-utf8)
 *     *   * Subject: Beginner's exercise in UTF-8 programming
 *      *   * From: Markus Kuhn <Markus{{dot}}Kuhn{{at}}cl.cam.ac.uk>
 *       *   * Date: Thu, 12 Jul 2001 15:54:43 +0100
 *        *   * Reply-To: linux-utf8@nl.linux.org
 *         *   * Sender: owner-linux-utf8@nl.linux.org
 *          *
 *           * Here a nice little code example that you can show to people interested
 *            * in character set aware programming to demonstrate how simple properly
 *             * written portable code to output a certain character in a
 *              * locale-dependent portable way can look like:
 *               */

/* Trivial demonstration of how to output a Unicode character (here:
 *  * the euro sign, U+20AC) with ISO C in a portable way. [For Linux,
 *   * make sure you have glibc 2.2 or newer, otherwise you'll only get
 *    * the ASCII fallback.] */

/* Compile the above wtest.c and call with
 *  *
 *   * LANG=de_DE ./wtest             -> get ISO 8859-1
 *    * LANG=de_DE@euro ./wtest        -> get ISO 8859-15
 *     * LANG=de_DE.UTF-8 ./wtest       -> get UTF-8
 *      *
 *       * You'll fully automatically get the encoding that "locale charmap"
 *        * reports for the current locale setting.
 *         *
 *          * If you are unfamiliar with C's wide I/O functions, you'll find them
 *           * documented in the new ISO C standard
 *            *
 *             * http://www.cl.cam.ac.uk/~mgk25/volatile/ISO-C-FDIS.1999-04.txt 
 *              * Markus G. Kuhn, Computer Laboratory, University of Cambridge, UK
 *               * Email: mkuhn at acm.org,  WWW: <http://www.cl.cam.ac.uk/~mgk25/>
 *                */


#include <stdio.h>
#include <locale.h>

int main() {

  /* Set the locale, such that C's multibyte output routines know,
 *    * which encoding (ISO 8859-1, ISO 8859-15, UTF-8, ASCII, etc.)
 *       * the user wants */
  if (!setlocale(LC_CTYPE, "")) {
    fprintf(stderr, "Can't set the specified locale! "
            "Check LANG, LC_CTYPE, LC_ALL.\n");
    return 1;
  }

  printf("Euro sign: ");


#ifdef __STDC_ISO_10646__
  /* this is defined on linux but not on OS X*/
  if (printf("%lc", 0x20ac) < 0)   /* try C's multibyte output mechanism */
#endif
    printf("EUR");                 /* if that fails: ASCII fallback */

  printf("\n");

  return 0;
}



