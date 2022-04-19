#include <stdio.h>

int main(void)
{
  int num;
  int i;
  int j;
  int flag = 1;
  printf("Enter a number:\n");
  while (scanf("%d", &num) == 1 && num > 2)
  {
    for (i = 2; i <= num; i++)
    {
      flag = 1;
      for (j = 2; j * j <= i; j++)
      {
        if (i % j == 0)
        {
          flag = 0;
          break;
        }
      }
      if (flag == 1)
      {
        printf("%d is prime!\n", i);
      }
      // else
      // {
      //   printf("%d isn't prime!\n", i);
      // }
    }
    printf("Enter a number:\n");
  }
  printf("Done.\n");
  return 0;
}