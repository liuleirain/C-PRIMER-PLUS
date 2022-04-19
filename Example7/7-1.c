#include <stdio.h>

int main(void)
{
  char ch;
  int s_ct;
  int n_ct;
  int o_ct;
  s_ct = n_ct = o_ct = 0;
  while ((ch = getchar()) != '#')
  {
    // putchar(ch);
    switch (ch)
    {
    case 32:
      s_ct++;
      break;
    case '\n':
      n_ct++;
      break;
    default:
      o_ct++;
      break;
    }
  }
  printf("Space = %d, \\n = %d, Other = %d\n", s_ct, n_ct, o_ct);
  return 0;
}