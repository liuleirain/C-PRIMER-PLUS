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

void showStruct(struct messages* pm, int n);

int main(void) {
  struct messages peopleMes[5] = {
    {"52351233", {"Dribble", "Mike", "Flossie"}},
    {"65234612", {"Emma", "", "Smith"}},
    {"62356234", {"Aggie", "Robert", "Jones"}},
    {"23451235", {"Agnes", "karen", "Williams"}} ,
    {"56234626", {"Bella", "", "Taylor"}},
  };
  showStruct(peopleMes, 5);
  return 0;
}

void showStruct(struct messages* pm, int n) {
  int i;
  for (i = 0; i < 5; i++) {

    printf("%s, ", (pm + i)->names.lname);
    printf("%s ", (pm + i)->names.fname);
    if (strlen((pm + i)->names.mname) != 0) printf("%c. ", (pm + i)->names.mname[0]);
    printf("-- %s\n", (pm + i)->inc_num);
  }
}