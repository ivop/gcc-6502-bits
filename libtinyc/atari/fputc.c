#include "stdio.h"
#include "stdint.h"

#define PUTCHAR 0x0b

static uint16_t *const ICBALH = (uint16_t *) 0x0344;
static uint16_t *const ICBLLH = (uint16_t *) 0x0348;
static uint8_t *const ICCOM = (uint8_t *) 0x0342;
static uint8_t buffer;

int fputc (int c, FILE *f)
{
    buffer = c;
    if (buffer == '\n') buffer = 0x9b;
    *ICBALH = (uint16_t)&buffer;
    *ICBLLH = 1;
    *ICCOM = PUTCHAR;

  register char x asm ("x") = 0;
  __asm__ __volatile__ (\
          "jsr $e456" : : "Aq" (x) );

  return c;
}
