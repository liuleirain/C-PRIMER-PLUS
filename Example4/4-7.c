#include <stdio.h>
#include <string.h>
#include <float.h>

int main(void)
{
  double d = 1.0 / 3.0;
  float f = 1.0 / 3.0;
  printf("%.6f %.6lf\n", f, d);
  printf("%.12f %.12lf\n", f, d);
  printf("%.16f %.16lf\n", f, d);
  printf("FLT_DIG = %d\n", FLT_DIG);
  printf("DBL_DIG = %d\n", DBL_DIG);
  return 0;
}