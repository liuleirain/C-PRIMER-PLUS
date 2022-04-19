#include <stdio.h>

int main(void)
{
  int min, max;
  int i;
  int sum;
  printf("Enter lower and upper integer limits:");
  while (scanf("%d %d", &min, &max) == 2 && min < max)
  {
    sum = 0;
    for (i = min; i <= max; i++)
    {
      sum += i * i;
    }
    printf("The sums of the squares from %d to %d is %d\n", min * min, max * max, sum);
    printf("Enter lower and upper ineger limits:");
  }
  printf("Done\n");
  return 0;
}