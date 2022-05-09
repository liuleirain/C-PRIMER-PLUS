#include <stdio.h>
#define N 3
#define M 4
void CopyArray(double[], double[], int);
void ShowArray(double (*a)[M], int, int);
int main(void)
{
  double arr[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}};
  int i,
      j;
  double arr2[3][4];
  for (i = 0; i < 3; i++)
  {
    CopyArray(arr[i], arr2[i], 4);
  }
  printf("Resource array:\n");
  ShowArray(arr, 3, 4);
  putchar('\n');
  printf("New array:\n");
  ShowArray(arr2, 3, 4);
  putchar('\n');
  return 0;
}

void CopyArray(double source[], double target[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    target[i] = source[i];
  }
}

void ShowArray(double (*array)[M], int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      printf("%.2lf ", array[i][j]);
    }
    putchar('\n');
  }
}