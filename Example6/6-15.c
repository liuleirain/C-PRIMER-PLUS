#include <stdio.h>
#include <string.h>
#define N 255

int main(void)
{
  char str[N];
  int n;
  int i;
  printf("Enter a string:");
  scanf("%s", str);
  printf("Reverse string is :");
  n = strlen(str);
  for (i = n - 1; i >= 0; i--)
  {
    printf("%c", str[i]);
  }
  putchar('\n');
  return 0;
}