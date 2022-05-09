#include <stdio.h>
#define N 4

void addArr(int[], int[], int[], int);
void showArr(int[], int);

int main(void)
{
  int arr1[N] = {2, 4, 5, 8};
  int arr2[N] = {1, 0, 4, 6};
  int arr3[N];
  addArr(arr1, arr2, arr3, N);
  printf("New arr is :\n");
  showArr(arr3, N);
  return 0;
}

void addArr(int a[], int b[], int c[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    c[i] = a[i] + b[i];
  }
}

void showArr(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  putchar('\n');
}