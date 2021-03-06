#include "string.h"

int
strcmp (const char *s1, const char *s2)
{
  for (; *s1 || *s2; s1++, s2++)
    {
      int diff;
      
      if (!*s1 || !*s2)
	return *(unsigned char *)s1 - *(unsigned const char *)s2;
      
      diff = *s1 - *s2;
      if (diff != 0)
        return diff;
    }

  return 0;
}
