/* A tiny C library.  */

__attribute__((noreturn)) void
exit (int status)
{
  register unsigned char retcode __asm__ ("a") = status;
  __asm__ __volatile__ ("jmp 0" : : "Aq" (retcode));
  while (1)
    ;
}

