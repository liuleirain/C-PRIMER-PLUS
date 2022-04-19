#include <stdio.h>
#define N 27

int main(void)
{
  char letter[N] = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  while (letter[i] != '\0')
    printf("%c ", letter[i++]);
  printf("\nDone.\n");

  return 0;
}