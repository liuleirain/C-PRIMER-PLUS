#include <stdio.h>

int main(void)
{
  const int DAYS2WEEK = 7;
  int days;

  printf("Please enter the days:");
  scanf("%d", &days);
  printf("%d days are %d weeks, %d days.\n", days, days / DAYS2WEEK, days % DAYS2WEEK);
  return 0;
}