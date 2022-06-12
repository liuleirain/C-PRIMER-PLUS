#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 100
#define RANGE 10

static int rollem(int side);
void sort_arr(int *a);

int main(int argc, char *argv[])
{
  int arr[LEN];
  int i;
  srand((unsigned int)time(0));
  for (i = 0; i < LEN; i++)
  {
    arr[i] = rollem(RANGE);
  }

  sort_arr(arr);

  for (i = 1; i <= LEN; i++)
  {
    printf("%2d ", arr[i - 1]);
    if (i % RANGE == 0)
      putchar('\n');
  }
  putchar('\n');
  return 0;
}

void sort_arr(int *a)
{
  int i, j;
  int temp;
  for (i = 0; i < LEN; i++)
  {
    for (j = i + 1; j < LEN; j++)
    {
      if (a[i] < a[j])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

static int rollem(int side)
{
  int roll;
  roll = rand() % side + 1;
  return roll;
}