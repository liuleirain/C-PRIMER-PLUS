#include <stdio.h>

int main(void)
{
  char ch;
  int i;
  while ((ch = getchar()) != '#')
  {
    putchar(ch);
    printf(" %3d ", ch);
    i++;
    if (i % 8 == 0)
    {
      putchar('\n');
    }
  }
  printf("\nDone.\n");
  return 0;
}