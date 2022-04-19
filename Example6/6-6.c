#include <stdio.h>

int main(void)
{
  int i;
  int num;
  printf("Enter a number:");
  scanf("%d", &num);
  for (i = 1; i <= num; i++)
  {
    printf("%10d %10d %10d\n", i, i * i, i * i * i);
  }

  return 0;
}