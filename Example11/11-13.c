#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int i;
  for (i = argc - 1; i > 0; i--)
  {
    printf("%s ", argv[i]);
  }
  putchar('\n');
  return 0;
}