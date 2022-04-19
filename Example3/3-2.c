#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ascii;
  printf("Please enter a number:(EOF to quit)");

  while ((scanf("%d", &ascii) == 1) && ascii >= 0 && ascii < 128)
  {
    printf("%d is the ASCII code for %c\n", ascii, ascii);
    printf("Please enter again: ");
  }
  return 0;
}