#include <stdio.h>

int main(void)
{
  float first;
  float second;
  printf("Enter two float number:");
  while (scanf("%f %f", &first, &second) != 2)
  {
    printf("Please enter the correct number!");
  };
  printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", first, second, first, second, (first - second) / (first * second));
  return 0;
}