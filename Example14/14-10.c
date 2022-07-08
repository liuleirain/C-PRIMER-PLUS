#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM 4

double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);
void show(int index, double x, double y, double (*pf[NUM])(double, double));
int showmenu();
int get_first();
void eatline();

int main(void) {
  double x, y;
  int choice;
  double (*pf[NUM])(double, double) = { add, subtract, multiply, divide };
  while ((choice = showmenu()) != 'q') {
    printf("Enter two numbers: ");
    while (scanf("%lf %lf", &x, &y) != 2) {
      puts("Involid value, please enter again.");
    }
    switch (choice) {
    case 'a':
      show(0, x, y, pf);
      break;
    case 'b':
      show(1, x, y, pf);
      break;
    case 'c':
      show(2, x, y, pf);
      break;
    case 'd':
      show(3, x, y, pf);
      break;
    }
  }
  puts("Done.");
  return 0;
}

void eatline() {
  while (getchar() != '\n')continue;
}

int get_first() {
  int ch;
  do {
    ch = tolower(getchar());
  } while (isspace(ch));
  eatline();

  return ch;
}

int showmenu() {
  int ch;

  puts("==========================");
  puts("a) add       b) subtract");
  puts("c) multiply  d) divide");
  puts("q) quit");
  puts("==========================");
  printf("Please your choose: ");
  while (ch = get_first(), NULL == strchr("abcdq", ch)) {
    printf("Please enter a, b, c, d or q:");
  }
  return ch;
}

void show(int index, double x, double y, double (*pf[NUM])(double, double)) {
  double res;
  if (0 == y) {
    puts("Nothing can be divided by 0");
    return;
  }
  res = (*pf[index])(x, y);
  printf("The result is %.2lf.\n", res);
}

double add(double x, double y) {
  return x + y;
}

double subtract(double x, double y) {
  return x - y;
}

double multiply(double x, double y) {
  return x * y;
}

double divide(double x, double y) {
  return x / y;
}