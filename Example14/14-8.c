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
void showList(struct seat* ps[], int n);
char get_first(char* st);
void eatline();
int showEmpNum(const struct seat* ps, int n);
void showAlpList(struct seat* ps[], int n);
void assignSeat(struct seat* ps[], int n);
void deleteSeat(struct seat* ps[], int n);
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
    case 'e':
      deleteSeat(pt, ALEN);
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

void deleteSeat(struct seat* ps[], int n) {
  struct seat temp;
  int dNum;
  do {
    puts("The seats list is :");
    showList(ps, n);
    puts("Enter the number of the seat to be deleted:(0 to quit)");
    while (scanf("%d", &dNum) != 1 && (dNum > 0 && dNum < 13)) {
      puts("Invalid value! Please enter numbers between 0 and 12 .");
      eatline();
    }
    eatline();
    for (int i = 0; i < n; i++) {
      if (ps[i]->num == dNum) {
        temp.num = ps[i]->num;
        strcpy(temp.fname, "");
        strcpy(temp.lname, "");
        temp.isBooking = false;
        *(ps[i]) = temp;
      }
    }
  } while (0 != dNum);
}

void showList(struct seat* ps[], int n) {
  for (int i = 0; i < n; i++) {
    printf("The No.%d seat is %s %s.\n", ps[i]->num, ps[i]->fname, ps[i]->lname);
  }
}

void assignSeat(struct seat* ps[], int n) {
  struct seat temp;
  if (showEmpNum(*ps, n) == 0) return;
  for (int i = 0; i < n; i++) {
    if (ps[i]->isBooking == false) {
      puts("Do you want add customer information:(y/n)");
      if (get_first("yn") == 'n') return;
      temp.num = ps[i]->num;
      puts("Enter customer first name:");
      s_gets(temp.fname, SLEN);
      puts("Enter customer last name:");
      s_gets(temp.lname, SLEN);
      temp.isBooking = true;
      *(ps[i]) = temp;
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