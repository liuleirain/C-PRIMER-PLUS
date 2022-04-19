#include <stdio.h>
#define N 8

int main(void)
{

  int array[N];
  int i;
  printf("Enter a number array:");
  for (i = 0; i < N; i++)
  {
    scanf("%d", &array[i]);
  }
  printf("Reveres array is :");
  for (i = N - 1; i >= 0; i--)
  {
    printf("%d ", array[i]);
  }
  putchar('\n');
  return 0;
}