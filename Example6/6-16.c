#include <stdio.h>

int main(void)
{
  double daphne = 100.0;
  double deirdre = 100.0;
  int year = 0;
  do
  {
    year++;
    daphne = 100.0 + (100.0 * 0.1 * year);
    deirdre = deirdre * 1.05;
    printf("%d years daphne = %.2lf, deirdre = %.2lf\n", year, daphne, deirdre);
  } while (daphne >= deirdre);
  return 0;
}