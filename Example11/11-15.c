#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 60
int myatoi(char *st);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char st[LEN];
  puts("Please enter a string (EOF to quit):");
  while (s_gets(st, LEN) != NULL)
  {
    printf("%s is %d.\n", st, myatoi(st));
    puts("Enter a string again (EOF to quit):");
  }
  puts("Done.");

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

int myatoi(char *st)
{
  int i, j;
  int num = 0;
  int length;
  length = strlen(st);
  for (i = 0; i < length; i++)
  {
    if (isdigit(st[i]))
    {
      // putchar(st[i]);
      // putchar(' ');
      num = num * 10 + (st[i] - 48);
      // printf("%d.\n", num);
    }
    else
      return 0;
  }
  return num;
}