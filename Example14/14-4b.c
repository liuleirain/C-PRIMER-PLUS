#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15
#define LEN 30

struct fullname {
  char lname[N];
  char mname[N];
  char fname[N];
};

struct messages {
  char inc_num[LEN];
  struct fullname names;
};

void showStruct(const struct messages pm, int n);

int main(void) {
  struct messages peopleMes[5] = {
    {"52351233", {"Dribble", "Mike", "Flossie"}},
    {"65234612", {"Emma", "", "Smith"}},
    {"62356234", {"Aggie", "Robert", "Jones"}},
    {"23451235", {"Agnes", "karen", "Williams"}} ,
    {"56234626", {"Bella", "", "Taylor"}},
  };
  int i;
  for (i = 0; i < 5; i++) {
    showStruct(peopleMes[i], 5);
  }

  return 0;
}

void showStruct(const struct messages pm, int n) {

  printf("%s, ", pm.names.lname);
  printf("%s ", pm.names.fname);
  if (strlen(pm.names.mname) != 0) printf("%c. ", pm.names.mname[0]);
  printf("-- %s\n", pm.inc_num);
}