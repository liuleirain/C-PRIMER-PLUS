#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int count = 0;
  char ch;
  FILE *fp;
  char fname[50];
  printf("Please enter the file name:\n");
  scanf("%s", fname);
  fp = fopen(fname, "r");
  if (fp == NULL)
  {
    printf("Filad open to file, Bye\n");
    exit(1);
  }
  while ((ch = getc(fp)) != EOF)
    count++;
  printf("The file has %d letters.\n", count);
  return 0;
}