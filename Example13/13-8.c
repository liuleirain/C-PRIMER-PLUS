#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 50
#define STLEN 500

char* s_gets(char* st, int n);

int main(int argc, char* argv[]) {
  FILE* fp;
  char find;
  char fileName[LEN];
  char st[STLEN];
  char ch;
  int i;
  int count = 0;
  if (argc < 2) {
    fprintf(stderr, "Usage: %s character filename...\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  if (strlen(argv[1]) != 1) {
    fprintf(stderr, "The second argument must be a character!\n");
    exit(EXIT_FAILURE);
  }
  if (argc < 3) {
    count = 0;
    find = argv[1][0];
    puts("Enter some string:");
    s_gets(st, STLEN);
    for (i = 0; st[i] != '\0'; i++) {
      if (st[i] == find) {
        count++;
      }
    }
    printf("\'%c\' appeared %d times.\n ", find, count);
  }
  else {
    find = argv[1][0];
    for (i = 2; i < argc; i++) {
      count = 0;
      if ((fp = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[i]);
        exit(EXIT_FAILURE);
      }
      while ((ch = fgetc(fp)) != EOF) {
        if (ch == find) {
          count++;
        }
      }
      printf("File %s \'%c\' apperaed %d times.\n", argv[i], find, count);
    }
  }

  return 0;
}

char* s_gets(char* st, int n) {
  char* ret_val;
  char* find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');
    if (find) {
      *find = '\0';
    }
    else {
      while (getchar() != '\n')continue;
    }
  }
  return ret_val;
}