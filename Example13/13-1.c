#include <stdio.h>
#include <stdlib.h>
#define LEN 50

int main(void)
{
  int ch;
  FILE* fp;
  unsigned long count = 0;
  char fileName[LEN];
  printf("Enter the file name:");
  scanf("%49s", fileName);
  if ((fp = fopen(fileName, "r")) == NULL) {
    printf("Can't open %s\n", fileName);
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(fp)) != EOF)
  {
    putc(ch, stdout);
    count++;
  }
  putchar('\n');
  fclose(fp);
  printf("File %s has %lu characters\n", fileName, count);

  return 0;
}