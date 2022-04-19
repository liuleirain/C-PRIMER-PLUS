#include <stdio.h>
#define PERWATERMOLECULES 3.0E-23
#define PERQUART 950

int main(void)
{
  int n;
  printf("Please enter the number:");
  scanf("%d", &n);
  printf("%d quart water of the water molecules is %e.\n", n, PERQUART * n / PERWATERMOLECULES);
  return 0;
}