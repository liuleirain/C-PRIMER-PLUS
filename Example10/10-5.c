#include <stdio.h>
#define LENGTH 10

double Difference(double[], int);

int main(void)
{
  double arr[LENGTH];
  int i, difference;
  printf("Enter %d float:", LENGTH);
  for (i = 0; i < LENGTH; i++)
  {
    scanf("%lf", &arr[i]);
  }
  difference = Difference(arr, LENGTH);
  printf("Difference is %d.\n", difference);
  return 0;
}

double Difference(double a[], int n)
{
  int i, max, min;
  double res;
  max = a[0];
  min = a[0];
  for (i = 0; i < n; i++)
  {
    if (max < a[i])
      max = a[i];
    if (max > a[i])
      min = a[i];
  }
  res = max - min;
  return res;
}