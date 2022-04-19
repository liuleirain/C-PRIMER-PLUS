#include <stdio.h>
#include <string.h>

int main(void)
{
  int num;
  int i;
  printf("Please enter a number:");
  scanf("%d", &num);
  for (i = 0; i <= 10; i++)
  {
    printf("%d ", num + i);
  }
  putchar('\n');
  return 0;
}