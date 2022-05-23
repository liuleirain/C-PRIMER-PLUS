#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50

void deleteSpace(char *st);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char st[LEN];
  puts("Please enter some string:");
  while (s_gets(st, LEN) != NULL && *st != '\0')
  {
    deleteSpace(st);
    puts(st);
    puts("Please enter some string again:");
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

void deleteSpace(char *st)
{
  int i, j;
  char *temp;
  temp = st;
  i = j = 0;
  while (*(temp + i) != '\0')
  {
    if (!isspace(*(temp + i)))
    {
      *(st + j) = *(temp + i);
      j++;
    }
    i++;
  }
  *(st + j) = '\0';
}