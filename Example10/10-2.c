#include <stdio.h>

void copy_arr(double[], double[], int);
void copy_ptr(double[], double[], int);
void copy_ptrs(double[], double[], double[]);

void show_arr(double[], int);

int main(void)
{
  double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
  double target1[5];
  double target2[5];
  double target3[5];
  copy_arr(target1, source, 5);
  copy_ptr(target2, source, 5);

  copy_ptrs(target3, source, source + 5);

  printf("target1:\n");
  show_arr(target1, 5);
  printf("\ntarget2:\n");
  show_arr(target2, 5);
  printf("\ntarget3:\n");
  show_arr(target3, 5);
  putchar('\n');
  return 0;
}

void show_arr(double s[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%.2lf ", s[i]);
  }
}

void copy_arr(double t[], double s[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    t[i] = s[i];
  }
}

void copy_ptr(double *t, double *s, int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    *t++ = *s++;
  }
}

void copy_ptrs(double *t, double *s, double *n)
{
  while (s < n)
  {
    *t++ = *s++;
  }
}