#include <stdio.h>
#include <limits.h>
#define MASK 01
char* itob(int, char*);
void show_bstr(char*);
int move_left(int, int);

int main(void) {
  char st[CHAR_BIT * sizeof(unsigned int) + 1];
  int num;
  int bit;
  puts("Please enter a number:");
  scanf("%d", &num);
  show_bstr(itob(num, st));
  printf("Please input a integer and the number of bits to move:\n");
  scanf("%d", &bit);
  num = move_left(num, bit);
  printf("The present binary string:\n");
  show_bstr(itob(num, st));
  return 0;
}

int move_left(int n, int bit) {
  int i;
  int size = CHAR_BIT * sizeof(unsigned int);
  for (i = 0; i < bit; i++) {
    n = (n << 1) + ((n >> (size - 1)) && MASK);
  }
  return n;
}

char* itob(int n, char* st) {
  int i;
  int size = CHAR_BIT * sizeof(unsigned int);
  for (i = size - 1; i >= 0; i--, n >>= 1) {
    st[i] = (MASK & n) + '0';
  }
  st[size] = '\0';
  return st;
}


void show_bstr(char* st) {
  int i = 0;
  while (st[i]) {
    putchar(st[i]);
    if (++i % 4 == 0 && st[i])
      putchar(' ');
  }
  printf("\n");
}