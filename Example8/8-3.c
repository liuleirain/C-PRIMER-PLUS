#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char ch;
  int l_count = 0;
  int u_count = 0;
  int o_count = 0;
  printf("Please enter some letters:\n");
  while ((ch = getchar()) != EOF)
  {
    if (islower(ch))
    {
      l_count++;
    }
    else if (isupper(ch))
    {
      u_count++;
    }
    else
      o_count++;
  }
  printf("\nYou enter %d lower letters, %d upper letters, %d other letters.\n", l_count, u_count, o_count);
  return 0;
}