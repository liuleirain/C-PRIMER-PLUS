#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  FILE* fp;
  int i;
  char ch;
  for (i = 1; i < argc; i++) {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "Can't open %s\n", argv[i]);
      continue;
    }
    printf("File %s :\n", argv[i]);
    while ((ch = fgetc(fp)) != EOF)
      putchar(ch);
    putchar('\n');
    if (fclose(fp) != 0) {
      fprintf(stderr, "Can't close %s\n", argv[i]);
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}