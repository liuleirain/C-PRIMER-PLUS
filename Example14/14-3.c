#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};
char* s_gets(char* st, int n);
void sort_title(struct book* pb[], int n);
void sort_value(struct book* pb[], int n);


int main(void) {
  struct book library[MAXBKS];
  struct book* book[MAXBKS];
  int count = 0;
  int index;

  printf("Please enter the book title.\n");
  printf("Press [enter] at the start of a line to stop.\n");
  while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0') {
    printf("Now enter the author.\n");
    s_gets(library[count].author, MAXAUTL);
    printf("Now enter the value.\n");
    scanf("%f", &library[count].value);
    book[count] = &library[count];
    count++;
    while (getchar() != '\n')continue;
    if (count < MAXBKS)printf("Enter the next title.\n");
  }

  if (count > 0) {
    printf("Here is the list of your books:\n");
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", library[index].title, library[index].author, library[index].value);

    printf("\nHere is the list of your books title sorted:\n");
    sort_title(book, count);
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", book[index]->title, book[index]->author, book[index]->value);

    printf("\nHere is the list of your books value sorted:\n");
    sort_value(book, count);
    for (index = 0; index < count; index++)
      printf("%s by %s: $%.2f\n", book[index]->title, book[index]->author, book[index]->value);
  }

  else printf("No books? Too bad.\n");

  return 0;
}

void sort_value(struct book* pb[], int n) {
  int i, j;
  struct book* temp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (pb[i]->value > pb[j]->value) {
        temp = pb[i];
        pb[i] = pb[j];
        pb[j] = temp;
      }
    }
  }
}

void sort_title(struct book* pb[], int n) {
  struct book* temp;
  int i, j;
  for (i = 0; i < n - 1;i++) {
    for (j = i + 1; j < n; j++) {

      if ((strcmp(pb[i]->title, pb[j]->title) > 0)) {
        temp = pb[i];
        pb[i] = pb[j];
        pb[j] = temp;
      }
    }
  }
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