#include <stdio.h>

void sort_num(double *, double *, double *);

int main(void)
{
  double a, b, c;
  printf("Enter three numbers:");
  while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
  {
    printf("Original numbers are %.2lf, %.2lf, %.2lf\n", a, b, c);
    sort_num(&a, &b, &c);
    printf("New nubmers are %.2lf, %.2lf, %.2lf\n", a, b, c);
    printf("Enter three numbers:");
  }
  printf("Dnoe.\n");
  return 0;
}

void sort_num(double *x, double *y, double *z)
{
  double temp;
  if (*x > *y)
  {
    temp = *x;
    *x = *y;
    *y = temp;
  }
  if (*y > *z)
  {
    temp = *y;
    *y = *z;
    *z = temp;
  }
  if (*x > *y)
  {
    temp = *x;
    *x = *y;
    *y = temp;
  }
}