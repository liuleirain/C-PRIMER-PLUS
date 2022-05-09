#include <stdio.h>
#define N 3
#define M 5

void showArr(int[][M], int);
void doublingArr(int[][M], int);

int main(void)
{
  int arr[N][M] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15}};
  int arr1[N][M];
  printf("Original array is :\n");
  showArr(arr, N);
  doublingArr(arr, N);
  printf("New array is:\n");
  showArr(arr, N);
  return 0;
}

void showArr(int a[][M], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < M; j++)
    {
      printf("%d ", a[i][j]);
    }
    putchar('\n');
  }
  putchar('\n');
}

void doublingArr(int a[][M], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < M; j++)
    {
      a[i][j] *= 2;
    }
  }
}