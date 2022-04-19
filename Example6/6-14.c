#include <stdio.h>
#define N 8

int main(void)
{
  double a1[N];
  double a2[N];
  int i, j;
  printf("Enter some number:");
  for (i = 0; i < N; i++)
  {
    scanf("%lf", &a1[i]);
  }
  for (i = 0; i < N; i++)
  {
    for (j = 0; j <= i; j++)
    {
      a2[i] += a1[j];
    }
  }
  for (i = 0; i < N; i++)
  {
    printf("%6.2lf ", a1[i]);
  }
  printf("\n");
  for (i = 0; i < N; i++)
  {
    printf("%6.2lf ", a2[i]);
  }
  printf("\n");
  return 0;
}