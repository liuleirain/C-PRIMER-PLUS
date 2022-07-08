#include <stdio.h>
#include <math.h>

#define LEN 5

void transform(double source[], double target[], int len, double(*pf)(double));
void show_array(double arr[], int len);
double twice(double n);
double square(double n);

int main(void) {
  double x[LEN] = { 1.1,2.2,3.3,4.4,5.5 };
  double y[LEN] = { 0 };


  puts("The source list is: ");
  show_array(x, LEN);

  puts("The target list is: ");
  show_array(y, LEN);

  transform(x, y, LEN, floor);
  puts("After floor: ");
  show_array(y, LEN);

  transform(x, y, LEN, sqrt);
  puts("After sqrt: ");
  show_array(y, LEN);

  transform(x, y, LEN, twice);
  puts("After twice: ");
  show_array(y, LEN);

  transform(x, y, LEN, square);
  puts("After square: ");
  show_array(y, LEN);

  return 0;
}

double twice(double n) {
  return n + n;
}


double square(double n) {
  return n * n;
}


void show_array(double arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%.2lf ", arr[i]);
  }
  putchar('\n');
}

void transform(double source[], double target[], int len, double(*pf)(double)) {
  for (int i = 0; i < len; i++) {
    target[i] = pf(source[i]);
  }
}