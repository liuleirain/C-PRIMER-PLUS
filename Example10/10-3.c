#include <stdio.h>
#define LENGTH 10
int findMax(int[], int);
int main(void)
{
  int arr[LENGTH] = {};
  int max;
  printf("Enter %d number:", LENGTH);
  for (int i = 0; i < LENGTH; i++)
  {
    scanf("%d", &arr[i]);
  }
  max = findMax(arr, LENGTH);
  printf("The max number is %d.\n", max);

  return 0;
}

int findMax(int a[], int n)
{
  int i;
  int max;
  max = a[0];
  for (i = 0; i < n; i++)
  {
    if (max < a[i])
    {
      max = a[i];
    }
  }
  return max;
}