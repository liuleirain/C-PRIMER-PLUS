#include <stdio.h>

int main(void)
{
  int i, j;
  int count = 0;
  for (i = 0; i < 6; i++)
  {
    for (j = 0; j <= i; j++)
    {
      printf("%c", 'A' + count++);
    }
    putchar('\n');
  }
  return 0;
}