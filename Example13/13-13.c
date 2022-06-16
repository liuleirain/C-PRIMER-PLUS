#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEVELS 10
#define ROWS 20
#define COLS 30
#define SLEN 50

const char surstr[LEVELS + 1] = "0123456789";
const char trans[LEVELS + 1] = " .':~*=&%#";
void ReplaceChar(int rows, int cols, int arr[rows][cols]);

int main(void) {
  FILE* sfp;
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
  ReplaceChar(ROWS, COLS, numArr);
  if (fclose(sfp) != 0) {
    fprintf(stderr, "Can't close %s\n", fileName);
  }
  return 0;
}

void ReplaceChar(int rows, int cols, int arr[rows][cols]) {
  FILE* dfp;
  int i, j;
  if ((dfp = fopen("target", "w")) == NULL) {
    fprintf(stderr, "Can't open %s\n", "target");
    exit(EXIT_FAILURE);
  }
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      // printf("%d", numArr[i][j]);
      putc(trans[arr[i][j]], dfp);
    }
    putc('\n', dfp);
    // putchar('\n');
  }
  if (fclose(dfp) != 0) {
    fprintf(stderr, "Can't close %s\n", "target");
    exit(EXIT_FAILURE);
  }
}