#include <stdio.h>
#define N 3
#define M 5
void AverageValue(int n, int m, double arr[n][m]);
void AllAverageValue(int n, int m, double arr[n][m]);
void FindMaxValue(int n, int m, double arr[n][m]);
int main(void)
{
  double arr[N][M];
  int i, j;
  printf("Enter some float:\n");
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < M; j++)
    {
      scanf("%lf", &arr[i][j]);
    }
  }
  AverageValue(N, M, arr);
  AllAverageValue(N, M, arr);
  FindMaxValue(N, M, arr);
  return 0;
}

void FindMaxValue(int n, int m, double arr[n][m])
{
  int i, j;
  double max = arr[0][0];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      if (max < arr[i][j])
      {
        max = arr[i][j];
      }
    }
  }
  printf("The Max value is %.2lf.\n", max);
}

void AllAverageValue(int n, int m, double arr[n][m])
{
  int i, j;
  double ave = 0.0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      ave += arr[i][j] / m;
    }
  }
  printf("The average value is %.2lf.\n", ave);
}

void AverageValue(int n, int m, double arr[n][m])
{
  int i, j;
  double ave;
  for (i = 0; i < n; i++)
  {
    ave = 0.0;
    for (j = 0; j < m; j++)
    {
      ave += arr[i][j] / m;
    }
    printf("The average value of the %d group is %.2lf.\n", i + 1, ave);
  }
}