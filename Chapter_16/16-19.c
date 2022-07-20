#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

_Static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");
int mina(void) {
  puts("char is 16 bits.");
  return 0;
}