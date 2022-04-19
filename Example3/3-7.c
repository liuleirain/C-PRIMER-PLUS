#include <stdio.h>
#define PERINCHCENTIMERTER 2.54

int main(void)
{
  float inch;
  printf("Please enter the number of inches: ");
  scanf("%f", &inch);
  printf("%f inches equal %f cen.\n", inch, inch * PERINCHCENTIMERTER);
  return 0;
}