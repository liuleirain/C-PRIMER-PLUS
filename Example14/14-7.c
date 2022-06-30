#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char* s_gets(char* st, int n);
char get_first(const char* st);
int get_books(struct book pb);
void update(struct book pb);
void eatline();

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
  bool isDel;
};

int main(void) {
  struct book library[MAXBKS];
  int count = 0;
  int deleted = 0;
  int open;
  int index, filecount;
  FILE* pbooks;
  int size = sizeof(struct book);

  if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
    fputs("Can't open book.dat file\n", stderr);
    exit(1);
  }

  rewind(pbooks);
  while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
    if (count == 0)
      puts("Current contents of book.dat:");
    printf("%s by %s: $%.2f\n", library[count].title,
      library[count].author, library[count].value);
    count++;
    printf("Do you want to change or delete this entry(y/n)?\n");
    printf("Please you enter to choose: ");
    if (get_first("yn") == 'y') {
      printf("Enter c to change, d to delete entry: ");
      if (get_first("cd") == 'd') {
        library[count].isDel = true;
        deleted++;
        puts("Flag marked for deletion(The space for the next book).");
      }
      else update(library[count]);
    }
    count++;
  }

  if (count == MAXBKS) {
    fputs("The book.dat file is full.", stderr);
    exit(2);
  }
  filecount = count - deleted;

  if (count == MAXBKS) {
    fputs("The book.data file is full.", stderr);
    exit(EXIT_FAILURE);
  }

  if (deleted > 0) {
    printf("If you delete some books, you should enter books to replace.\n");
  }
  puts("Please add new book titles.");
  puts("Press [enter] at the start of a line to stop.");
  open = 0;
  while (filecount < MAXBKS) {
    if (filecount < count) {
      while (library[open].isDel == false) {
        open++;
      }
      if (get_books(library[open]) == 1) {
        break;
      }
    }
    else if (get_books(library[filecount]) == 1) {
      break;
    }
    filecount++;
    if (filecount < MAXBKS) puts("Enter the next book title.");
  }
  puts("Here is the list of your books:");
  for (index = 0; index < filecount; index++) {
    if (library[index].isDel == false) {
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }
  }
  if ((pbooks = fopen("book.dat", "wb")) == NULL) {
    fputs("Can't open book.dat file for output.\n", stderr);
    exit(EXIT_FAILURE);
  }
  for (index = 0; index < filecount; index++) {
    if (library[index].isDel == false) {
      fwrite(&library[index], size, 1, pbooks);
    }
  }
  if (fclose(pbooks) != 0) {
    fprintf(stderr, "Error in closing file.\n");
  }
  puts("Bye.\n");

  return 0;
}

void update(struct book pb) {
  int ch;

  puts("==============================");
  puts("t) modify title a) modify author");
  puts("v) modify value s) quit and save changes");
  puts("q) quit and ignore changes");
  puts("==============================");
  printf("Please you enter to choose: ");
  while ((ch = get_first("tavsq")) != 's' && ch != 'q') {
    switch (ch) {
    case 't': {
      printf("Please enter new title: ");
      s_gets(pb.title, MAXTITL);
      break;
    }
    case 'a': {
      printf("Please enter new author: ");
      s_gets(pb.author, MAXAUTL);
      break;
    }
    case 'v': {
      printf("Please enter new value:");
      while (scanf("%f", &pb.value) != 1) {
        eatline();
        puts("Please enter a valid value: ");
      }
      eatline();
      break;
    }
    }

    puts("==============================");
    puts("t) modify title a) modify author");
    puts("v) modify value s) quit and save changes");
    puts("q) quit and ignore changes");
    puts("==============================");
    printf("You can choose again: ");

  }
  return;
}

int get_books(struct book pb) {
  int status = 0;

  if (s_gets(pb.title, MAXTITL) == NULL || pb.title[0] == '\0') {
    status = 1;
  }
  else {
    printf("Now enter the author: ");
    s_gets(pb.author, MAXAUTL);
    printf("Now enter the value:");
    while (scanf("%f", &pb.value) != 1) {
      eatline();
      puts("Please enter a valid value: ");
    }
    eatline();
    pb.isDel = false;
  }
  return status;
}

char get_first(const char* st) {
  int ch;

  ch = tolower(getchar());
  while (strchr(st, ch) == NULL) {
    printf("Invalid data! Please enter again:");
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
      while (getchar() != '\n')continue;
  }
  return ret_val;
}