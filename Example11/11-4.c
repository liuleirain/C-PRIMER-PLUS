#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 20

char *s_gets(char *st, int n, int m);

int main(int argc, char *argv[])
{
  char str[LEN];
  puts("Please enter some character:");
  s_gets(str, LEN - 1, 5);
  puts(str);
  return 0;
}

char *s_gets(char *st, int n, int m)
{
  char ch;
  int i, j;
  char *pst;
  i = j = 0;
  pst = st;
  while ((ch = getchar()) == ' ' || ch == '\t' || ch == '\n')
    continue;
  *pst = ch;
  pst++;
  i++;
  j++;
  while ((ch = getchar()) != ' ' && ch != '\t' && ch != '\n' && i < n && j < m)
  {
    *pst = ch;
    pst++;
    i++;
    j++;
  }
  *pst == '\0';
  if (i < n)
  {
    while (getchar() != '\n')
      continue;
  }
  return st;
}