#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40

int main(void)
{
  FILE* in, * out;
  int ch;
  char name[LEN];
  int count = 0;
  char fileName[LEN];

  printf("Enter the file name:\n");
  scanf("%39s", fileName);
  if ((in = fopen(fileName, "r")) == NULL)
  {
    fprintf(stderr, "I couldn't open the file \"%s\"\n", fileName);
    exit(EXIT_FAILURE);
  }
  strncpy(name, fileName, LEN - 5);
  name[LEN - 5] = '\0';
  strcat(name, ".red");
  if ((out = fopen(name, "w")) == NULL)
  {
    fprintf(stderr, "Can't create output file.\n");
    exit(3);
  }
  while ((ch = getc(in)) != EOF)
    if (count++ % 3 == 0)
    {
      putc(ch, out);
    }
  if (fclose(in) != 0 || fclose(out) != 0)
    fprintf(stderr, "Error in closing files\n");

  return 0;
}
