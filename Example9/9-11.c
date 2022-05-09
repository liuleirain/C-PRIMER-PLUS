#include <stdio.h>

unsigned long long Fibonacci(unsigned n);
unsigned long long FibonacciLoop(unsigned n);

int main(void)
{
  int num;
  int i;
  printf("Please enter a number:");
  while (scanf("%d", &num) == 1 && num > 0)
  {
    for (i = 1; i <= num; i++)
    {
      // printf("%lld ", Fibonacci(i));
      printf("%lld ", FibonacciLoop(i));
    }
    putchar('\n');
    printf("Please enter a number:");
  }
  return 0;
}

unsigned long long FibonacciLoop(unsigned n)
{
  if (n > 2)
  {
    long long a = 1;
    long long b = 1;
    long long c;
    int i;
    for (i = 2; i < n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    return b;
  }
  else
    return 1;
}

unsigned long long Fibonacci(unsigned n)
{
  if (n > 2)
    return Fibonacci(n - 1) + Fibonacci(n - 2);
  else
    return 1;
}