#include <stdio.h>

int main(void)
{
  float height;
  const float CM2INCH = 0.3937;
  const double CM2FEET = 0.032808399;
  const double CM_PER_FEET = 30.48;
  printf("Enter a height in centimeters (<=0 to quit): ");
  while (scanf("%f", &height) == 1 && height > 0)
  {

    printf("%.1f cm = %d feet, %.1f inches\n", height, (int)(height * CM2FEET), (height - (CM_PER_FEET * ((int)(height * CM2FEET)))) * CM2INCH);
    printf("Enter a height in centimeters (<=0 to quit) : ");
  }

  return 0;
}