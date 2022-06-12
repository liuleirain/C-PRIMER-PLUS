#include <stdio.h>

static int count = 0;

int callCount();

int main(int argc, char *argv[])
{
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("%d times.\n", callCount());
  }
  return 0;
}

int callCount()
{
  return ++count;
}