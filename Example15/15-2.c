#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 5

int btoi(char* st);
char* itob(char* st, int n);
void show_st(const char* st);

int main(int argc, char* argv[]) {
  int num1;
  int num2;
  char bin_st[CHAR_BIT * sizeof(int) + 1];
  if (3 != argc) {
    fprintf(stderr, "The number of arguments is wrong.\n");
    exit(EXIT_FAILURE);
  }

  num1 = btoi(argv[1]);
  num2 = btoi(argv[2]);
  show_st(itob(bin_st, ~num1));
  show_st(itob(bin_st, ~num2));
  show_st(itob(bin_st, num1 & num2));
  show_st(itob(bin_st, num1 | num2));
  show_st(itob(bin_st, num1 ^ num2));

  return 0;
}

void show_st(const char* st) {
  int i = 0;
  while (st[i]) {
    putchar(st[i]);
    if (++i % 4 == 0 && st[i])
      putchar(' ');
  }
  putchar('\n');
}

char* itob(char* st, int n) {
  int i;
  const static int size = CHAR_BIT * sizeof(int);

  for (i = size - 1; i >= 0; i--, n >>= 1)
    st[i] = (01 & n) + '0';
  st[size] = '\0';
  return st;
}

int btoi(char* st) {
  int num;
  while (*st)
    num = (num << 1) + (*st++ - '0');
  return num;
}