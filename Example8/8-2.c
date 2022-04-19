#include <stdio.h>

int main(void)
{
  int ch;
  int count = 0;
  while ((ch = getchar()) != EOF)
  {
    if (ch < 32)
    {
      printf(" ^%c:%3d", ch + 64, ch);
    }
    else if (ch == ' ')
    {
      printf("%3c:%3d", ' ', ch);
    }
    else if (ch == '\n')
    {
      printf(" \\n:%3d", ch);
    }
    else if (ch == '\t')
    {
      printf(" \\t:%3d", ch);
    }
    else
    {
      printf("%3c:%3d", ch, ch);
    }
    putchar(' ');
    count++;
    if (count % 10 == 0)
      putchar('\n');
  }
  return 0;
}