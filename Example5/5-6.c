#include <stdio.h>
int main(void)
{
  int count, sumSquares;
  int days;
  printf("Enter the days:");
  while (scanf("%d", &days) == 1 && days > 0)
  {

    count = 0;
    sumSquares = 0;
    while (count++ < days)
      sumSquares = sumSquares + count * count;
    printf("sumSquares = %d\n", sumSquares);
    printf("Enter the days:");
  }
  return 0;
}