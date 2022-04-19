#include <stdio.h>
#include <stdlib.h>

void printString(char, int, int);

int main(void)
{
  int x, y;
  char ch;
  do
  {
    printf("Enter a char and two number(q to quit):");
    while (scanf("%c %d %d", &ch, &x, &y) == 3)
    {
      if (ch == 'q')
        exit(1);
      printf("%c %d %d\n", ch, x, y);
      printString(ch, y, x);
      printf("Enter a char an two number:");
    }
  } while (1);
  return 0;
}

void printString(char c, int x, int y)
{
  int i, j;
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < x; j++)
    {
      putchar(c);
    }
    putchar('\n');
  }
}