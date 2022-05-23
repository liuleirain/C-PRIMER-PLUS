#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 50

void *ReverseStr(char *st);
char *s_gets(char *st, int n);

int main(int argc, char *argv[])
{
  char st[LEN];
  puts("Please enter some string:");
  while (s_gets(st, LEN) != NULL)
  {
    ReverseStr(st);
    puts(st);
    puts("Please enter some string:");
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

void *ReverseStr(char *st)
{
  int i;
  char temp;
  int stringLen = strlen(st);
  for (i = 0; i < stringLen / 2; i++)
  {
    temp = *(st + i);
    *(st + i) = *(st + stringLen - 1 - i);
    *(st + stringLen - 1 - i) = temp;
  }
}