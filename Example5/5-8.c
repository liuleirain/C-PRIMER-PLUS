#include <stdio.h>

int main(void)
{
  int second;
  int first;

  printf("This program computes moduli.\n");
  printf("Enter an integer to serve as the second operand: ");
  scanf("%d", &second);
  printf("Now enter the first operand:");
  while (scanf("%d", &first) == 1 && first > 0)
  {
    printf("%d %% %d is %d\n", first, second, first % second);
    printf("Enter next number for first operand (<= 0 to quit): ");
  }
  printf("Done\n");
  return 0;
}