#include <stdio.h>
#define LENGTH 10
int findMaxIndex(double[], int);

int main(void)
{
  double arr[LENGTH];
  int i, index;
  printf("Enter %d float:", LENGTH);
  for (i = 0; i < LENGTH; i++)
  {
    scanf("%lf", &arr[i]);
  }
  index = findMaxIndex(arr, LENGTH);
  printf("The max index is %d.\n", index);
  return 0;
}

int findMaxIndex(double a[], int n)
{
  int i, max, index;
  index = 0;
  max = a[0];
  for (i = 0; i < n; i++)
  {
    if (max < a[i])
    {
      index = i;
      max = a[i];
    }
  }

  return index;
}