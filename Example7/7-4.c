#include <stdio.h>

int main(void)
{
  char ch;
  int n;
  printf("enter some string:");
  while ((ch = getchar()) != '#')
  {
    if (ch == '.')
    {
      ch = '!';
      putchar(ch);
      n++;
    }
    else if (ch == '!')
    {
      putchar(ch);
      putchar(ch);
      n++;
    }
    else
      putchar(ch);
  }
  printf("%d replace times.\n", n);
  return 0;
}