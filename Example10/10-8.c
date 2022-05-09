#include <stdio.h>
#define N 5

void copyArr(double[], double[], int);
void showArr(double[], int);

int main(void)
{
  double arr1[N] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double arr2[3];
  copyArr(&arr1[2], arr2, 3);
  printf("New arr is: ");
  showArr(arr2, 3);
  return 0;
}

void copyArr(double s[], double t[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    t[i] = s[i];
  }
}

void showArr(double s[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%.2lf ", s[i]);
  }
  putchar('\n');
}