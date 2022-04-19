#include <stdio.h>

int main(void)
{
  const int CONVERSION = 60;
  int munites;
  printf("Please enter munites:");
  while (scanf("%d", &munites) == 1 && munites > 0)
  {
    printf("%d Hour %d munites.\n", munites / CONVERSION, munites % CONVERSION);
    printf("Please enter munites:");
  }
  printf("Done.\n");
  return 0;
}