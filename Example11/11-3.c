#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 20

char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char word[LEN];
  puts("Please enter some characters:");
  s_gets(word, LEN - 1);
  puts(word);
  return 0;
}

char *s_gets(char *st, int n)
{
  char ch;
  int i = 0;
  char *pst;
  pst = st;
  while ((ch = getchar()) == ' ' || ch == '\t' || ch == '\n')
    continue;
  *pst = ch;
  pst++;
  i++;
  while ((ch = getchar()) != ' ' && ch != '\t' && ch != '\n' && i < n)
  {
    *pst = ch;
    pst++;
    i++;
  }
  *pst = '\0';
  i++;
  if (i < n)
  {
    while (getchar() != '\n')
      continue;
  }
  return st;
}