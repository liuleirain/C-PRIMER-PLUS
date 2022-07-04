#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define SLEN 20
#define ALEN 12

struct seat {
  int num;
  bool isBooking;
  char fname[SLEN];
  char lname[SLEN];
};

static struct seat seats[ALEN] = {
  {1, true, "Doe", "John"},
  {2, false},
  {3, false},
  {4, true, "Merry", "White"},
  {5, true, "Tom", "Json"},
  {6, false},
  {7, false},
  {8, false},
  {9, false},
  {10, false},
  {11, false},
  {12, false}
};

char showMenu();
char get_first(char* st);
void eatline();
int showEmpNum(const struct seat* ps, int n);
void showAlpList(struct seat* ps[], int n);
void assignSeat(struct seat* ps[], int n);
char* s_gets(char* st, int n);


int main(void) {
  char ch;
  struct seat* pt[ALEN];
  for (int i = 0; i < ALEN; i++) {
    pt[i] = &seats[i];
  }

  while (ch = showMenu()) {
    switch (ch) {
    case 'a':
      printf("The number of empty seats: %d\n", showEmpNum(seats, ALEN));
      break;
    case 'b':
      puts("The list of empty seats:");
      for (int i = 0; i < 12; i++) {
        if (seats[i].isBooking == false) {
          printf("%d ", seats[i].num);
        }
      }
      putchar('\n');
      break;
    case 'c':
      puts("The alphabetical list of seats:");
      showAlpList(pt, ALEN);
      break;
    case 'd':
      assignSeat(pt, ALEN);
      break;
    }
  };

  return 0;
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

void assignSeat(struct seat* ps[], int n) {
  if (showEmpNum(*ps, n) == 0) return;
  for (int i = 0; i < n; i++) {
    if (ps[i]->isBooking == false) {
      puts("Do you want add customer information:(y/n)");
      if (get_first("yn") == 'n') return;
      puts("Enter customer first name:");
      s_gets(ps[i]->fname, SLEN);
      puts("Enter customer last name:");
      s_gets(ps[i]->lname, SLEN);
    }
  }

}

void showAlpList(struct seat* pt[], int n) {
  int i, j;
  struct seat* temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(pt[i]->lname, pt[j]->lname) > 0) {
        temp = pt[i];
        pt[i] = pt[j];
        pt[j] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (pt[i]->isBooking == true)
      printf("The No.%d seat is %s %s.\n", pt[i]->num, pt[i]->fname, pt[i]->lname);
  }
}

int showEmpNum(const struct seat* ps, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (ps[i].isBooking == false)
      count++;
  }
  return count;
}

char get_first(char* st) {
  char ch;
  ch = tolower(getchar());
  while (strchr(st, ch) == NULL) {
    puts("Invalid data, Please enter again.");
    eatline();
    ch = tolower(getchar());
  }
  eatline();
  return ch;
}

void eatline() {
  while (getchar() != '\n') continue;
}

char showMenu() {
  char ch;
  puts("To choose a function, enter its letter label:");
  puts("a) Show number of empty seats");
  puts("b) Show list of empty seats");
  puts("c) Show alphabetical list of seats");
  puts("d) Assign a customer to a seat assignment");
  puts("e) Delete a seat assignment");
  puts("f) Quit");
  ch = get_first("abcdef");
  return ch;
}