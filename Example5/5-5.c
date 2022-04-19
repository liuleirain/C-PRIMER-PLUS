#include <stdio.h>
int main(void)
{
  int count, sum;
  int days;
  printf("Enter the days:");
  while (scanf("%d", &days) == 1 && days > 0)
  {

    count = 0;
    sum = 0;
    while (count++ < days)
      sum = sum + count;
    printf("sum = %d\n", sum);
    printf("Enter the days:");
  }
  return 0;
}