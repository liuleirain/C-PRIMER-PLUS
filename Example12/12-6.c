#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10
#define LENGTH 1000

int main(int argc, char *argv[])
{
  int arr[RANGE] = {0};
  int i, j, seek;
  for (i = 0; i < 5; i++)
  {
    printf("Time %2d.\n", j + 1);
    srand(i);
    for (j = 0; j < LENGTH; j++)
    {
      seek = rand() % RANGE + 1;
      arr[seek - 1]++;
    }
    for (j = 0; j < RANGE; j++)
    {
      printf("%2d. %4d ", j + 1, arr[j]);
      arr[j] = 0;
    }
    putchar('\n');
  }
  return 0;
}