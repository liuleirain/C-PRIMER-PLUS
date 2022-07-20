#include <stdio.h>
#define HORMONIC(x, y) (2.0 / ((1 / (x)) + (1 / (y))) )

int main(void) {
  double num1, num2;

  printf("Please enter two number ('q' to quit): ");
  while (scanf("%lf%lf", &num1, &num2) == 2) {
    printf("The hormonic average: %.2lf\n", HORMONIC(num1, num2));
    printf("Please input two number ('q' to quit): ");
  }

  return 0;
}