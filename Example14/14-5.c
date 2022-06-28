#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 20
#define CSIZE 4
#define SCORE 3

struct name {
  char lname[LEN];
  char fname[LEN];
};

struct student {
  struct name names;
  double grade[SCORE];
  double average;
};

void set_student(struct student ar[], int n);
void find_averages(struct student ar[], int n);
void show_messages(const struct student ar[], int n);
void show_averages(const struct student ar[], int n);

int main(void) {
  struct student classes[CSIZE] = {
    {"Doe", "John"},
    {"Bertha", "Miller"},
    {"Chaya", "White"},
    {"Diana", "Harris"}
  };
  set_student(classes, CSIZE);
  find_averages(classes, CSIZE);
  show_messages(classes, CSIZE);
  show_averages(classes, CSIZE);
  return 0;
}

void set_student(struct student ar[], int n) {
  int i, j;
  for (i = 0;i < n;i++) {
    printf("Please enter three scores for %s %s:\n", ar[i].names.lname, ar[i].names.fname);
    for (j = 0; j < SCORE; j++) {
      while (scanf("%lf", &ar[i].grade[j]) != 1) {
        while (getchar() != '\n')continue;
        printf("Please enter a score!\n");
      }
    }
  }
}

void find_averages(struct student ar[], int n) {
  double ave;
  int i, j;
  for (i = 0;i < n;i++) {
    for (j = 0, ave = 0; j < SCORE; j++) {
      ave += ar[i].grade[j] / SCORE;
    }
    ar[i].average = ave;
  }
}

void show_messages(const struct student ar[], int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    printf("%s. %s's scores is:", ar[i].names.lname, ar[i].names.fname);
    for (j = 0; j < SCORE;j++) {
      printf(" %.2lf", ar[i].grade[j]);
    }
    printf(", averages is %.2lf.\n", ar[i].average);
  }
}

void show_averages(const struct student ar[], int n) {
  double TotAve = 0;
  int i, j;
  for (i = 0; i < n; i++) {
    TotAve += ar[i].average / n;
  }
  printf("The averages class is %.2lf.\n", TotAve);
}