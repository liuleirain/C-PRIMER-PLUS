#include <stdio.h>
#include <limits.h>

#define MASK 01

int check_bit(int, int);

int main(void) {
  int num, index;
  puts("Please enter a number and index:");
  scanf("%d %d", &num, &index);
  printf("The number in your position is : %d.\n", check_bit(num, index));

  return 0;
}

int check_bit(int n, int m) {
  int i;
  for (i = 0;i < m; i++)
  {
    n >>= 1;
  }
  return n & MASK;
}