#include <stdio.h>
#define N 3
#define M 5

void copyArr(int rows, int cols, double ar[rows][cols], double tar[rows][cols]);
void showArr(int rows, int cols, double ar[rows][cols]);

int main(void)
{
  double arr1[N][M] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 10},
      {11, 12, 13, 14, 15}};
  double arr2[N][M];
  copyArr(N, M, arr1, arr2);
  printf("New arr is:\n");
  showArr(N, M, arr2);
  return 0;
}

void copyArr(int rows, int cols, double ar[rows][cols], double tar[rows][cols])
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      tar[i][j] = ar[i][j];
    }
  }
}

void showArr(int rows, int cols, double ar[rows][cols])
{
  int i, j;
  for (i = 0; i < rows; i++)
  {
    for (j = 0; j < cols; j++)
    {
      printf("%.2lf ", ar[i][j]);
    }
    putchar('\n');
  }
}