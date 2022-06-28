#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 12

struct month {
  char monthly[11];
  char abbre[4];
  int days;
  int monum;
};

struct month months[LEN] = {
  {"January", "jan", 31, 1},
  {"February", "feb", 28, 2},
  {"March", "mar", 31, 3},
  {"April", "apr", 30, 4},
  {"May", "may", 31, 5},
  {"June", "jun", 30, 6},
  {"July", "jul", 31, 7},
  {"August", "aug", 31, 8},
  {"September", "sep", 30, 9},
  {"October", "oct", 31, 10},
  {"November", "nov", 30, 11},
  {"December", "dec", 31, 12}
};

void leapYear(int n);
int TotDays(char* st, int n);

int main(void) {
  int year;
  int day;
  char mon[10];
  int totalDays;
  puts("Please enter the Day, Month and Year:");
  while ((scanf("%d %11s %d", &day, mon, &year) == 3) && day > 0 && year > 0 && mon[0] != '\0') {
    leapYear(year);
    totalDays = TotDays(mon, day);
    if (totalDays > 0) {
      printf("There are %d days from the beginning of %d to %s to %d\n", totalDays, year, mon, day);
    }
    else {
      puts("Your input error.");
    }
    months[1].days = 28;
    puts("Please enter the Day, Month and Year:");
  }
  puts("Done.");

  return 0;
}

int TotDays(char* st, int n) {
  int total = 0;
  int i;
  int temp = atoi(st);
  int slen = strlen(st);
  if (n < 1 || n > 31) {
    return -1;
  }
  if (0 == temp) {
    for (i = 0; i < slen; i++) {
      st[i] = tolower(st[i]);
    }
    if (slen > 3) st[0] = toupper(st[0]);
  }
  for (i = 0; i < LEN; i++) {
    if (temp == months[i].monum || (strcmp(st, months[i].monthly) == 0) || (strcmp(st, months[i].abbre) == 0)) {
      if (n > total) return -1;
      else
        total += n;
      return total;
    }
    else {
      total += months[i].days;
    }
  }
  return total;
}

void leapYear(int n) {
  if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
    months[1].days = 29;
  }
}