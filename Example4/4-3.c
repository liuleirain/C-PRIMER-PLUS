#include <stdio.h>
#include <string.h>

int main(void)
{
  float num;
  printf("Please enter a float: ");
  scanf("%f", &num);
  printf("The float is %f\n", num);
  printf("The float is %e\n", num);
  return 0;
}