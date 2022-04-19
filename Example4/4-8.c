#include <stdio.h>
#include <string.h>

int main(void)
{
  const float gallon2rise = 3.785;
  const float mile2km = 1.609;
  float mileage;
  float gallon;
  printf("Please enter you mileage:");
  scanf("%f", &mileage);
  printf("Please enter the gallon:");
  scanf("%f", &gallon);
  printf("Miles per gallon gasoline is %.1f\n", mileage / gallon);
  printf("Universal fuel consumption is %.1f\n", (gallon * gallon2rise) / (mileage * mile2km) * 100);
  return 0;
}