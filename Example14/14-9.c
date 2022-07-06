#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TOTSEATS 12
#define SLEN 20
#define LEN 4

typedef struct {
  int num;
  bool isBooking;
  char fname[SLEN];
  char lname[SLEN];
}SEAT;

typedef struct {
  char num[LEN];
  SEAT seats[TOTSEATS];
}FLIGHT;

static FLIGHT flights[4] = {
  {"102", {
    {1,true,"Herbert","Smith"},
    {2,true,"Rain","Jones"},
    {3,true,"Tobin","Williams"},
    {4,false},
    {5,false},
    {6,false},
    {7,false},
    {8,false},
    {9,false},
    {10,false},
    {11,false},
    {12,false},
  }},
  {"311", {
    {1,true,"Cillian","Johnson"},
    {2,true,"Malina","Williams"},
    {3,false},
    {4,false},
    {5,false},
    {6,false},
    {7,false},
    {8,false},
    {9,false},
    {10,false},
    {11,false},
    {12,false},
  }},
  {"444", {
    {1,true,"Winnie","Garcia"},
    {2,true,"Isadora","Miller"},
    {3,true,"Vicky","Davis"},
    {4,true,"Chantel","Rodriguez"},
    {5,true,"jeff","Wilson"},
    {6,false},
    {7,false},
    {8,false},
    {9,false},
    {10,false},
    {11,false},
    {12,false},
  }},
  {"519", {
    {1,true,"Tiago","Brown"},
    {2,true,"Marko","Taylor"},
    {3,true,"Andrei","Davis"},
    {4,true,"Viola","Johnson"},
    {5,true,"Ares","Anderson"},
    {6,false,"Loretta","Thomas"},
    {7,false},
    {8,false},
    {9,false},
    {10,false},
    {11,false},
    {12,false},
  }},
};

void eatline();
char getfirst(char* st);
char showSubMenu(FLIGHT* pf);
int showEmpNum(SEAT ps[], int n);
void handleFlight(FLIGHT* pf);
void showMainMenu();
void showAlpList(const SEAT ps[], int n);
char* s_gets(char* st, int n);
void assignSeat(SEAT* ps[], int n);
void deleteSeat(SEAT* ps[], int n);
void confirmSeat(SEAT* ps[], int n);

int main(void)
{
  showMainMenu();
  return 0;
}

void eatline() {
  while (getchar() != '\n')continue;
}

char getfirst(char* st) {
  char ch;
  ch = tolower(getchar());
  while (strchr(st, ch) == NULL) {
    eatline();
    ch = tolower(getchar());
  }
  eatline();
  return ch;
}

char showSubMenu(FLIGHT* pf) {
  char ch;
  printf("Currently processing information about flight \"%s\"\n", pf->num);
  puts("a) Show number of empty seats");
  puts("b) Show list of empty seats");
  puts("c) Show alphabetical list of seats");
  puts("d) Assign a customer to a seat assignment");
  puts("e) Delete a seat assignment");
  puts("f) Comfirm seat assigned");
  puts("q) Quit");
  ch = getfirst("abcdefq");
  return ch;
}

int showEmpNum(SEAT ps[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (false == ps[i].isBooking) count++;
  }
  return count;
}

void showAlpList(const SEAT ps[], int n) {
  SEAT temp;
  SEAT sortSeats[n];
  for (int i = 0; i < n; i++) {
    sortSeats[i] = ps[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (strcmp(sortSeats[i].fname, sortSeats[j].fname) > 0) {
        temp = sortSeats[i];
        sortSeats[i] = sortSeats[j];
        sortSeats[j] = temp;
      }
    }
  }
  for (int i = 0;i < n; i++) {
    printf("The No.%d is %s %s.\n", sortSeats[i].num, sortSeats[i].fname, sortSeats[i].lname);
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
      eatline();
  }
  return ret_val;
}

void assignSeat(SEAT* ps[], int n) {
  SEAT temp;
  if (showEmpNum(*ps, n) == 0) return;
  for (int i = 0;i < n; i++) {
    if (ps[i]->isBooking == false) {
      printf("Do you want add customer information to No.%d:(y/n)", ps[i]->num);
      if (getfirst("yn") == 'n') return;
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

void deleteSeat(SEAT* ps[], int n) {
  SEAT temp;
  int dNum;
  do {
    puts("The seat list is:");
    for (int i = 0; i < n; i++) {
      printf("The No.%d is %s %s.\n", ps[i]->num, ps[i]->fname, ps[i]->lname);
    }
    puts("Enter the number of the seat to be delete:(0 to quit)");
    while (scanf("%d", &dNum) != 1 || (dNum < 0 && dNum > 13)) {
      eatline();
      puts("Involid value, Please enter numbers between 0 and 12 ");
    }
    eatline();
    for (int i = 0; i < n; i++) {
      if (dNum == ps[i]->num) {
        temp.num = ps[i]->num;
        temp.isBooking = false;
        strcpy(temp.fname, "");
        strcpy(temp.lname, "");
      }
    }
  } while (0 != dNum);
}

void comfirmSeat(SEAT* ps[], int n) {
  for (int i = 0; i < n; i++) {
    if (true == ps[i]->isBooking)
      printf("Seat %-2d: assignd.\n", ps[i]->num);
    else
      printf("Seat %-2d: unassignd.\n", ps[i]->num);
  }
}

void handleFlight(FLIGHT* pf) {
  char ch;
  SEAT* ps[TOTSEATS];
  for (int i = 0; i < TOTSEATS; i++) {
    ps[i] = &(pf->seats[i]);
  }
  while ((ch = showSubMenu(pf)) && ch != 'q') {
    switch (ch) {
    case 'a':
      printf("The number of empty is: %d.\n", showEmpNum(pf->seats, TOTSEATS));
      break;
    case 'b':
      puts("The list of empty seats:");
      for (int i = 0; i < 12; i++) {
        if (pf->seats[i].isBooking == false) {
          printf("%d ", pf->seats[i].num);
        }
      }
      putchar('\n');
      break;
    case 'c':
      puts("The alphabetical list of seats");
      showAlpList(pf->seats, TOTSEATS);
      break;
    case 'd':
      assignSeat(ps, TOTSEATS);
      break;
    case 'e':
      deleteSeat(ps, TOTSEATS);
      break;
    case 'f':
      comfirmSeat(ps, TOTSEATS);
      break;
    case 'q':
      return;

    }
  }
}

void showMainMenu() {
  char ch;
  do {
    puts("There are some airlines for you to choose.");
    puts("a) Airline 102  b) Airline 311");
    puts("c) Airline 444  d) Airline 519");
    puts("q) Quit");
    ch = getfirst("abcdq");
    switch (ch) {
    case 'a':
      handleFlight(&flights[0]);
      break;
    case 'b':
      handleFlight(&flights[1]);
      break;
    case 'c':
      handleFlight(&flights[2]);
      break;
    case 'd':
      handleFlight(&flights[3]);
      break;
    }
  } while (ch != 'q');
}
