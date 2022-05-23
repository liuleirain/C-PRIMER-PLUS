#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 30

char *findChar(char *st, char c);

int main(int argc, char *argv[])
{
  char str[LEN] = "This is a test function";
  if (findChar(str, 'z'))
  {
    puts("Yes!");
  }
  else
  {
    puts("No!");
  }
  return 0;
}

char *findChar(char *st, char c)
{
  char *pst;
  pst = st;
  while (*pst != '\0')
  {
    if (*pst == c)
      return pst;
    pst++;
  }
  return NULL;
}