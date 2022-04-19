#include <stdio.h>
#define N 8

int thePowerOf2(int x);

int main(void)
{
  int array[N];
  int i;
  for (i = 0; i < N; i++)
  {
    array[i] = thePowerOf2(i);
  }
  i = 0;
  do
  {
    printf("%d ", array[i++]);
  } while (i < N);
  printf("\nDone.\n");

  return 0;
}

int thePowerOf2(int x)
{
  int i;
  int res = 2;
  for (i = 0; i < x; i++)
  {
    res *= 2;
  }
  // printf("%d\n", res);
  return res;
}