#include <stdio.h>

int main(void)
{
  char ch;
  int n;
  printf("enter some string:");
  while ((ch = getchar()) != '#')
  {
    switch (ch)
    {
    case '.':
      ch = '!';
      putchar(ch);
      n++;
      break;
    case '!':
      putchar(ch);
      putchar(ch);
      n++;
      break;
    default:
      putchar(ch);
      break;
    }
  }
  printf("%d replace times.\n", n);
  return 0;
}