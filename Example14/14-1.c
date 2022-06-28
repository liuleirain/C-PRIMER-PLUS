#include <stdio.h>
#include <string.h>
#define SLEN 40

struct mon {
  char name[SLEN];
  char sname[4];
  int days;
  int month;
};

struct mon months[12] = {
  {"January", "jan", 31, 1},
  {"February", "feb", 28, 2},
  {"March", "mar", 31,3},
  {"April", "apr", 30, 4},
  {"May", "may", 31, 5},
  {"June","jun", 30, 6},
  {"July", "jul", 31, 7},
  {"August", "aug", 31, 8} ,
  {"September", "sep", 30, 9},
  {"October", "oct", 31, 10},
  {"November", "nov", 30, 11},
  {"December", "dec", 31, 12}
};

int TotDays(char* st);

int main(void) {
  char temp[SLEN];
  puts("Please enter the monthly name");

  scanf("%s", temp);
  while (getchar() != '\n')continue;
  if (TotDays(temp) != -1)
    printf("%s total days are %d.\n", temp, TotDays(temp));
  else
    puts("Your input is incorrect.");
  return 0;
}

int TotDays(char* st) {
  int i;
  int tot = 0;
  for (i = 0; i < 12;i++) {
    tot += months[i].days;
    if (strcmp(st, months[i].name) == 0)return tot;
  }
  return -1;
}