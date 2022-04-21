#include <stdio.h>
void to_base_n(unsigned long n, int m);

int main(void)
{
  unsigned long number;
  int advance;
  printf("Enter an integer (q to quit):\n");
  while (scanf("%lu %d", &number, &advance) == 2)
  {
    printf("Binary equivalent: ");
    to_base_n(number, advance);
    putchar('\n');
    printf("Enter an integer (q to quit):\n");
  }
  printf("Done.\n");

  return 0;
}

void to_base_n(unsigned long n, int m)
{
  int r;

  r = n % m;
  if (n >= m)
    to_base_n(n / m, m);
  putchar(r < 10 ? r + '0' : r - 10 + 'A');

  return;
}