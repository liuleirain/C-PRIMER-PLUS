#include <stdio.h>
#define TAX 0.08
int main(void)
{
  double chuckie = 100;
  int year = 0;
  int i;
  do
  {
    year++;
    chuckie += chuckie * TAX;
    chuckie -= 10;
  } while (chuckie > 9);
  printf("%d year after .\n", ++year);
  return 0;
}