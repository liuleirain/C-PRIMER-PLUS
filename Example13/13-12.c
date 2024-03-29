#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEVELS 10
#define ROWS 20
#define COLS 30
#define SLEN 50

const char surstr[LEVELS + 1] = "0123456789";
const char trans[LEVELS + 1] = " .':~*=&%#";

int main(void) {
  FILE* sfp, * dfp;
  int numArr[ROWS][COLS];
  char fileName[SLEN];
  int i, j;
  char ch;
  i = j = 0;
  puts("Enter the file name:");
  scanf("%49s", fileName);
  if ((sfp = fopen(fileName, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", fileName);
    exit(EXIT_FAILURE);
  }
  while ((ch = getc(sfp)) != EOF) {
    if (ch != '\n' && strchr(surstr, ch)) {
      numArr[i][j] = ch - 48;
      j++;
      if (i > 29) {
        j = 0;
        i++;
      }
    }
    ch = getc(sfp);
  }
  if ((dfp = fopen("target", "w")) == NULL) {
    fprintf(stderr, "Can't open %s\n", "target");
    exit(EXIT_FAILURE);
  }
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      // printf("%d", numArr[i][j]);
      putc(trans[numArr[i][j]], dfp);
    }
    putc('\n', dfp);
    // putchar('\n');
  }
  return 0;
}
