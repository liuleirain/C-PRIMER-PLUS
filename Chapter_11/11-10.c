#include <stdio.h>
#define STLEN 10
char *s_gets(char *st, int n)
{
  char *ret_val;
  int i = 0;

  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    while (st[i] != '\n' && st[i] != '\0')
      i++;
    if (st[i] == '\n')
      st[i] = '\0';
    else
      while (getchar() != '\n')
        continue;
  }
  return ret_val;
}

int main(void)
{
  char str[STLEN];
  if (s_gets(str, STLEN))
    puts(str);
  return 0;
}