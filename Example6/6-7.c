#include <stdio.h>
#include <string.h>
#define N 20

int main(void)
{
  char str[N];
  int i;
  int s_len;
  printf("Enter a string:");
  scanf("%s", str);
  s_len = strlen(str);

  for (i = s_len; i >= 0; i--)
  {
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}