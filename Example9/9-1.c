#include <stdio.h>
double min(double, double);

int main(void)
{
  double x;
  double y;
  printf("Enter two number (q to quit): ");
  while (scanf("%lf %lf", &x, &y) == 2)
  {
    printf("The minimum value is %.2lf.\n", min(x, y));
    printf("Enter again(q to quit): ");
  }
  printf("Done.\n");
  return 0;
}

double min(double a, double b)
{
  return (a > b ? b : a);
}