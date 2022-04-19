#include <stdio.h>
#define PERPINTCUP 2
#define PERCUPOUNCE 8
#define PEROUNCEBIGSOUP 2
#define PERBIGSUPTEASPOON 3

int main(void)
{
  float cup;
  printf("Please enter a cup number:");
  scanf("%f", &cup);
  printf("%f cup euqal %f pint.\n", cup, cup / PERPINTCUP);
  printf("%f cup euqal %f ounce.\n", cup, cup * PERCUPOUNCE);
  printf("%f cup euqal %f big suop.\n", cup, cup * PERCUPOUNCE * PEROUNCEBIGSOUP);
  printf("%f cup euqal %f teas spoon.\n", cup, cup * PERCUPOUNCE * PEROUNCEBIGSOUP * PERBIGSUPTEASPOON);
  return 0;
}