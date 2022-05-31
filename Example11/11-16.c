#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN 60

char *s_gets(char *st, int n);
void Upper(char *st);
void Lower(char *st);

int main(int argc, char *argv[])
{
  char str[LEN];
  puts("Please enter a string(EOF to quit):");
  while (s_gets(str, LEN) != NULL)
  {
    if (argc == 1)
    {
      puts(str);
    }
    else
    {
      switch (argv[1][1])
      {
      case 'p':
        puts(str);
        break;
      case 'u':
        Upper(str);
        break;
      case 'l':
        Lower(str);
        break;
      default:
        puts("Please enter -p, -u or -l:");
        break;
      }
    }
    puts("Enter a string again(EOF to quit):");
  }

  return 0;
}

void Upper(char *st)
{
  int i = 0;
  while (st[i] != '\0')
  {
    putchar(toupper(st[i]));
    i++;
  }
  putchar('\n');
}

void Lower(char *st)
{
  int i = 0;
  while (st[i] != '\0')
  {
    putchar(tolower(st[i]));
    i++;
  }
  putchar('\n');
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