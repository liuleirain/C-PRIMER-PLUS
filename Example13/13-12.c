#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEVELS 10
#define ROWS 20
#define COLS 30
#define SLEN 50

const char trans[LEVELS + 1] = " .':~*=&%#";

int main(void) {
  FILE* sfp, * dfp;
  int numArr[ROWS][COLS];
  char fileName[SLEN];
  int i, j;
  puts("Enter the file name:");
  scanf("%49s", fileName);
  if ((sfp = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n");
    exit(EXIT_FAILURE);
  }

  return 0;
}
