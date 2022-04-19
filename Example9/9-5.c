#include <stdio.h>

void larger_of(double *, double *);

int main(void)
{
  double x, y;
  printf("Enter two numbers:");
  while (scanf("%lf %lf", &x, &y) == 2)
  {
    printf("Original numbers are %.2lf, %.2lf\n", x, y);
    larger_of(&x, &y);
    printf("New numbers are %.2lf, %.2lf\n", x, y);
    printf("Enter two nubmers:");
  }
  return 0;
}

void larger_of(double *x, double *y)
{
  if (*x > *y)
    *y = *x;
  else
    *x = *y;
}