#include <stdio.h>
double numOfAdj(double, double);

int main(void)
{
  double x, y;
  printf("Enter two numbers:");
  while (scanf("%lf %lf", &x, &y) != 2)
  {
    printf("Enter two numbers(such to 10.0 or 21.1)");
  }
  printf("%.2lf and %.2lf number of adjustments is : %.2lf\n", x, y, numOfAdj(x, y));
  return 0;
}

double numOfAdj(double x, double y)
{
  double ans;
  // ans = 1 / (((1 / x) + (1 / y)) / 2);
  ans = 2 / ((1 / x) + (1 / y));
  return ans;
}