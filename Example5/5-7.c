#include <stdio.h>

double cube(double x);

int main(void)
{
  double n;
  printf("Enter a number:");
  scanf("%lf", &n);
  cube(n);
  return 0;
}

double cube(double x)
{
  double result;
  result = x * x * x;
  printf("%lf\n", result);
  return result;
}