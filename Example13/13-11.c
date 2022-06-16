#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 500

int main(int argc, char* argv[]) {
  FILE* fp;
  char temp[LEN];
  if (argc != 3) {
    fprintf(stderr, "Usage: %s String FileName.\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(argv[2], "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  while (fgets(temp, LEN, fp) != NULL) {
    if (strstr(temp, argv[1]) != NULL) {
      fputs(temp, stdout);
    }
  }
  if (fclose(fp) != 0) {
    fprintf(stderr, "Can't close %s\n", argv[2]);
    exit(EXIT_FAILURE);
  }
  return 0;
}