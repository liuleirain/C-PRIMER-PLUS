#include <stdio.h>
#include <stdlib.h>
#define LEN 512

int main(int argc, char* argv[]) {
  FILE* sfp, * dfp;
  char temp[LEN];
  int bytes;
  if (argc != 3) {
    fprintf(stderr, "Usage: %s SourceFileName DestFileName\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((sfp = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }
  if ((dfp = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  if ((bytes = fread(temp, sizeof(char), LEN, sfp)) > 0) {
    fwrite(temp, sizeof(char), bytes, dfp);
  }
  if (fclose(sfp) != 0) {
    fprintf(stderr, "Can't close %s\n", argv[1]);
  }
  if (fclose(dfp) != 0) {
    fprintf(stderr, "Can't close %s\n", argv[2]);
  }
  return 0;
}