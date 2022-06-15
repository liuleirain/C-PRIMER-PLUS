#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 50

int main(void) {
  FILE* fp;
  char fileName[LEN];
  char ch;
  fprintf(stderr, "Enter the file name:\n");
  scanf("%49s", fileName);
  if ((fp = fopen(fileName, "r+")) == NULL) {
    fprintf(stderr, "Can't open %s\n", fileName);
    exit(EXIT_FAILURE);
  }
  while ((ch = fgetc(fp)) != EOF) {
    fseek(fp, -1L, SEEK_CUR);
    fputc(toupper(ch), fp);
    fseek(fp, 0L, SEEK_CUR);
  }
  rewind(fp);
  fprintf(stdout, "File %s is:\n", fileName);
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
  }
  putchar('\n');
  if (fclose(fp) != 0) {
    fprintf(stderr, "Can't close %s\n", fileName);
    exit(EXIT_FAILURE);
  }

  return 0;
}