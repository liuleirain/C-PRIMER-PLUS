#include <stdio.h>

int main(void)
{
  int n;
  int i;
  double res1;
  double res2;
  int flag = 1;
  printf("Enter a number:");
  while (scanf("%d", &n) == 1 && n > 0)
  {
    res1 = res2 = 0.0;
    for (i = 1; i <= n; i++)
    {
      res1 += 1.0 / (double)(i * 1.0);
      res2 += 1.0 / (double)(i * 1.0 * flag);
      flag = -flag;
    }
    printf("res1 = %lf\n", res1);
    printf("res2 = %lf\n", res2);
    printf("Enter a number:");
  }
  return 0;
}