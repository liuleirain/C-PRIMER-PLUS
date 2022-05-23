#include <stdio.h>
void put1(const char *string)
{
  while (*string != '\0')
    putchar(*string++);
}

int main(void)
{
  char *st = "How old are you!";
  put1(st);
  putchar('\n');
  return 0;
}