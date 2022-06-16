#include <stdio.h>
#include <stdlib.h>
#define LEN 60

int main(void) {
  FILE* fp;
  char fileName[LEN];
  int n;
  char ch;

  printf("Enter the file name:\n");
  scanf("%59s", fileName);
  if ((fp = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", fileName);
    exit(EXIT_FAILURE);

  }
  puts("Enter a number:");
  while ((scanf("%d", &n) == 1) && n > 0) {

    fseek(fp, n, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF && ch != '\n') putchar(ch);
    putchar('\n');
    puts("Enter a number:");

  }
  printf("Done.\n");
  if (fclose(fp) != 0) {
    fprintf(stderr, "Can't close %s\n", fileName);
    exit(EXIT_FAILURE);
  }
  return 0;
}