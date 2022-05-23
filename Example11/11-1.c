#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 20

void *s_gets(char *st);

int main(int argc, char *argv[])
{
  char str[N];
  printf("Please enter %d characters:\n", N - 1);
  s_gets(str);
  puts(str);
  return 0;
}

void *s_gets(char *st)
{
  char ch;
  char *pst;
  pst = st;
  while ((ch = getchar()) != '\n')
  {
    *pst = ch;
    pst++;
  }
  *pst = '\0';
}