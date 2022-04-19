#include <stdio.h>
#define N 50

int main(void)
{
  char str[N];
  int count = 0;
  int i = 0;
  printf("Enter some string:\n");
  while (i < N - 1 && (str[i] = getchar()) != '#')
  {
    i++;
  }
  str[i] = '\0';
  i = 0;
  while (str[i + 1] != '\0')
  {
    if (str[i] == 'e' && str[i + 1] == 'i')
    {
      count++;
    }
    i++;
  }
  printf("\"ei\" %d times.\n", count);

  return 0;
}