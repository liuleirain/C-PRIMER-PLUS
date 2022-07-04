#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 3

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
  bool isDel;
};

char* s_gets(char* st, int n);
char get_first(const char* st);
void eatline();
void update(struct book* pb);

int main(void) {
  struct book libary[MAXBKS];
  int count = 0;
  int deleted = 0;
  FILE* pbooks;
  int size = sizeof(struct book);

  if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
    fputs("Can't open book.dat.\n", stderr);
    exit(EXIT_FAILURE);
  }
  // strcpy(libary[0].title, "Metric Merriment");
  // strcpy(libary[0].author, "Polly Poetica");
  // libary[0].value = 11.22;
  // libary[0].isDel = false;
  // fwrite(&libary[0], size, 1, pbooks);

  rewind(pbooks);
  while (count < MAXBKS && fread(&libary[count], size, 1, pbooks)) {
    if (count == 0) {
      puts("Current contents of data.dat.");
    }

    printf("%s by %s: $%.2f.\n", libary[count].title, libary[count].author, libary[count].value);
    puts("Do you want to change or delete this entry(y/n):");
    printf("Enter your choose:");
    if (get_first("yn") == 'y') {
      puts("Enter c to change, d to delete entry:");
      if (get_first("cd") == 'd') {
        libary[count].isDel = true;
        deleted++;
      }
      else update(&libary[count]);
    }
    ++count;
  }
  rewind(pbooks);
  for (int i = 0; i < MAXBKS; i++) {
    if (libary[i].isDel == false)
      fwrite(&libary[i], size, 1, pbooks);
  }
  for (int i = 0; i < count; i++) {
    printf("%s by %s: $%.2f.\n", libary[i].title, libary[i].author, libary[i].value);
  }
  if (fclose(pbooks) != 0) {
    fputs("Don't close the book.dat", stderr);
    exit(EXIT_FAILURE);
  }

  return 0;
}

void update(struct book* pb) {
  int ch;

  puts("==============================");
  puts("a) modify title b) modify author");
  puts("c) modify value d) modify status");
  puts("q) quit and ignore changes");
  puts("==============================");
  printf("Please you enter to choose: ");
  while ((ch = get_first("abcdq")) != 'q') {
    switch (ch) {
    case 'a':
      puts("Enter the new titel:");
      s_gets(pb->title, MAXTITL);
      break;
    case 'b':
      puts("Enter the new author: ");
      s_gets(pb->author, MAXAUTL);
      break;
    case 'c':
      puts("Enter the new value:");
      while (scanf("%f", &pb->value) != 1) {
        puts("Please enter a valid value.");
      }
      eatline();
      break;
    case 'd':
      puts("Enter 0 or 1 change status:");
      while ((ch = get_first("01")) != '1' && ch != '0')
      {
        eatline();
        puts("Enter a valid value.");
      }
      eatline();
      if (ch == '0') {
        pb->isDel = false;
      }
      if (ch == '1') {
        pb->isDel = true;
      }
    }
    puts("==============================");
    puts("a) modify title b) modify author");
    puts("c) modify value d) modify status");
    puts("q) quit and ignore changes");
    puts("==============================");
    printf("Please you enter to choose: ");
  }
}

char get_first(const char* st) {
  char ch;

  ch = tolower(getchar());
  while (strchr(st, ch) == NULL) {
    puts("Invalid data, Please enter again:");
    eatline();
    ch = tolower(getchar());
  }
  eatline();
  return ch;
}

void eatline() {
  while (getchar() != '\n')continue;
}

char* s_gets(char* st, int n) {
  char* ret_val;
  char* find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n') continue;
  }
  return ret_val;
}