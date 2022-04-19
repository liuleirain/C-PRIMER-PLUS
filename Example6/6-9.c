#include <stdio.h>
float calculateFormula(float x, float y);

int main(void)
{
  float first;
  float second;
  float res;
  printf("Enter two float number:");
  while (scanf("%f %f", &first, &second) != 2)
  {
    printf("Please enter the correct number!");
  };
  res = calculateFormula(first, second);
  printf("(%.2f - %.2f) / (%.2f * %.2f) = %.2f\n", first, second, first, second, res);
  return 0;
}

float calculateFormula(float x, float y)
{
  float res;
  res = (x - y) / (x * y);
  return res;
}