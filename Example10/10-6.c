#include <stdio.h>
#define LENGTH 10
void ReverseOrder(double[], int);
void ShowArray(double[], int);
int main(void)
{
  double arr[LENGTH];
  int i;
  printf("Enter %d float:", LENGTH);
  for (i = 0; i < LENGTH; i++)
  {
    scanf("%lf", &arr[i]);
  }
  ReverseOrder(arr, LENGTH);
  ShowArray(arr, LENGTH);
  return 0;
}

void ReverseOrder(double a[], int n)
{
  double temp;
  int i, j;
  for (i = 0; i < n - 1; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (a[j] > a[j + 1])
      {
        temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

void ShowArray(double a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%.2lf ", a[i]);
  }
  putchar('\n');
}