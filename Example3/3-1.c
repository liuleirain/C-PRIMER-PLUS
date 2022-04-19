#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
  printf("%d,%d,%d\n", INT_MAX, INT_MAX + 1, INT_MAX + 2);
  printf("%e, %e\n", FLT_MAX, FLT_MAX * 100.0f);
  printf("%e, %e\n", FLT_MIN, FLT_MIN / 100.0f);
  return 0;
}