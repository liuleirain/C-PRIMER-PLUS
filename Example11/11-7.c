#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50

char *mystrncpy(char *s1, char *s2, int n);

char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char st1[LEN], st2[LEN];
  int strlen;
  puts("Please enter a string:");
  while (s_gets(st1, LEN) != NULL)
  {
    puts("Please enter other string:");
    s_gets(st2, LEN);
    printf("Str1 is %s.\n", mystrncpy(st1, st2, 10));
    puts("Please enter a string.");
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

char *mystrncpy(char *s1, char *s2, int n)
{
  char *st1, *st2;
  st1 = s1;
  st2 = s2;
  int i = 0;
  while (*(st2 + i) != '\0')
    i++;
  if (i >= n)
  {
    return s1;
  }
  else
  {
    while (*st2 != '\0')
      *st1++ = *st2++;
    *st1 = '\0';
    return s1;
  }
}
