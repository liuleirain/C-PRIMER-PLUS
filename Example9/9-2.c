#include <stdio.h>
#include <stdlib.h>
void chline(char, int, int);

int main(void)
{
  int x, y;
  char showChar;
  do
  {
    printf("Enter two number:");
    while (scanf("%d %d", &x, &y) != 2 || x < 0 || y < 0)
    {
      printf("Please enter two positive integers:");
    }
    while (getchar() != '\n')
      continue;
    printf("Enter a char(q to quit):");
    scanf("%c", &showChar);
    if (showChar == 'q')
      exit(1);
    chline(showChar, y, x);
  } while (1);
  return 0;
}

void chline(char c, int x, int y)
{
  int i, j;
  for (i = 0; i < y; i++)
  {
    for (j = 0; j < x; j++)
      putchar(c);
    putchar('\n');
  }
}