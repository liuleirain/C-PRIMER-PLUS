#include <stdio.h>

int main(void)
{
  int firends = 5;
  int i = 0;
  do
  {
    firends = (firends - 1) * 2;
    i++;
    printf("%d week Rabnud's firends are %d.\n", i, firends);
  } while ((firends - 1) * 2 < 150);
  return 0;
}