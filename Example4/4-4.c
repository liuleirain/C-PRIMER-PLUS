#include <stdio.h>
#include <string.h>
#define N 20
int main(void)
{
  char name[N];
  float inch;
  printf("Please enter your name:");
  scanf("%s", name);
  printf("Please enter your height(inch):");
  scanf("%f", &inch);
  printf("%s, you are %.3f feet tall\n", name, inch);
  return 0;
}