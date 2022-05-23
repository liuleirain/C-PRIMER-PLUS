#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50

char *string_in(char *st1, char *st2);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char s1[LEN], s2[LEN];
  puts("Please enter a string:");
  while (s_gets(s1, LEN) != NULL)
  {
    puts("Enter the search string:");
    s_gets(s2, LEN);
    if (string_in(s1, s2))
    {
      puts("Yes!");
    }
    else
    {
      puts("No!");
    }
    puts("Please enter a string:");
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

char *string_in(char *st1, char *st2)
{
  char *s1, *s2;
  int i;
  s1 = st1;
  s2 = st2;

  while (*s1 != '\0')
  {
    if (*s1 == *s2)
    {
      i = 1;
      while (*(s2 + i) == *(s1 + i))
      {
        i++;
        if (*(s2 + i) == '\0')
          return s1;
      }
    }
    s1++;
  }
  return NULL;
}