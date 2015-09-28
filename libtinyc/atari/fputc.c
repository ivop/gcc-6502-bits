#include "stdio.h"

int fputc (int c, FILE *f)
{
  register char x asm ("a") = c;
  /* FIXME: actually call ciov to output character to screen  */
  __asm__ __volatile__ ("jsr $ffee" : : "Aq" (x));

  return c;
}
