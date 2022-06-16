#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LEN 50

int main(int argc, char* argv[]) {
  FILE* fp1, * fp2;
  char file1[LEN], file2[LEN];
  char ch1, ch2;
  bool file1End = false;
  bool file2End = false;
  if (argc < 3) {
    printf("Enter the file name:");
    scanf("%49s %49s", file1, file2);
  }
  else {
    strncpy(file1, argv[1], LEN);
    strncpy(file2, argv[2], LEN);
  }
  if ((fp1 = fopen(file1, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", file1);
    exit(EXIT_FAILURE);
  }
  if ((fp2 = fopen(file2, "r")) == NULL) {
    fprintf(stderr, "Can't open %s\n", file2);
    exit(EXIT_FAILURE);
  }
  ch1 = fgetc(fp1);
  ch2 = fgetc(fp2);
  while (ch1 != EOF || ch2 != EOF) {
    while (ch1 != EOF && ch1 != '\n') {
      putchar(ch1);
      ch1 = fgetc(fp1);
    }
    while (ch2 != EOF && ch2 != '\n') {
      putchar(ch2);
      ch2 = fgetc(fp2);
    }
    putchar('\n');
    if (ch1 != EOF) ch1 = fgetc(fp1);
    if (ch2 != EOF) ch2 = fgetc(fp2);
  }
  return 0;
}