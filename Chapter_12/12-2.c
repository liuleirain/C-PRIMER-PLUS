#include <stdio.h>
int main(int argc, char *argv[])
{
  int n = 8;

  printf("   Initially, n = %d at %p\n", n, &n);
  for (int n = 1; n < 3; n++)
    printf("     loop l: n = %d at %p\n", n, &n);
  printf("After loop 1, n = %d at %p\n", n, &n);
  for (int n = 1; n < 3; n++)
  {
    printf("  loop 2 index n = %d at %p\n", n, &n);
    int n = 6;
    printf("        loop 2: n = %d at %p\n", n, &n);
    n++;
  }
  printf("After loop 2, n = %d at %p \n", n, &n);
  return 0;
}