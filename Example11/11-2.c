#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 20

void *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char str[LEN];
  puts("Please enter some characters:");
  s_gets(str, LEN - 1);
  puts(str);
  return 0;
}

void *s_gets(char *st, int n)
{
  int i = 0;
  char ch;
  char *pst;
  pst = st;
  while ((ch = getchar()) != '\n' && i < n && ch != '\t' && ch != ' ')
  {
    *pst = ch;
    pst++;
    i++;
  }
  *pst = '\0';
}