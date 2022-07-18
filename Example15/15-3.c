#include <stdio.h>
#include <limits.h>

#define MASK 01

int count_bit_on(int n);

int main(void) {
  int num;

  puts("Please enter the number:");
  scanf("%d", &num);
  printf("The number of bit on is: %d.\n", count_bit_on(num));

  return 0;

}

int count_bit_on(int n) {
  int i;
  int count = 0;
  int size = CHAR_BIT * sizeof(int);

  for (i = 0; i < size; i++) {
    if (MASK & n) {
      count++;
    }
    n >>= 1;
  }
  return count;
}