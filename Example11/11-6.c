#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50

int is_within(char c, char *st);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char str[LEN];
  char ch;
  puts("Please enter a string.");
  while (s_gets(str, LEN - 1) != NULL)
  {
    puts("Enter a character:");
    ch = getchar();
    while (getchar() != '\n')
      continue;
    if (is_within(ch, str))
    {
      puts("Yes!");
    }
    else
    {
      puts("No!");
    }
    puts("Please enter a string.");
  }
  return 0;
}

int is_within(char c, char *st)
{
  char *pst;
  pst = st;
  while (*pst != '\0')
  {
    if (*pst == c)
    {
      return 1;
    }
    pst++;
  }
  return 0;
}

char *s_gets(char *st, int n)
{
  char *ret_val;
  char *find;

  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if (find)
    {
      *find = '\0';
    }
    else
    {

      while (getchar() != '\n')
        continue;
    }
  }
  return ret_val;
}