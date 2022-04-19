#include <stdio.h>

int main(void)
{
  int num;
  int even_count = 0;
  int odd_count = 0;
  int even_sum = 0;
  int odd_sum = 0;
  float even_avg;
  float odd_avg;
  while (scanf("%d", &num) == 1 && num > 0)
  {
    if (num % 2 == 0)
    {
      even_count++;
      even_sum += num;
    }
    else
    {
      odd_count++;
      odd_sum += num;
    }
  }
  printf("Even is %d, Avg is %f.\n", even_count, (float)even_sum / even_count);
  printf("Odd is %d, Avg is %f.\n", odd_count, (float)odd_sum / odd_count);
  return 0;
}