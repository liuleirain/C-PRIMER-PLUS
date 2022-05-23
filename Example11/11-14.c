#include <stdio.h>
#include <stdbool.h>

double PowerOperation(double n, int m);

int main(int argc, char *argv[])
{
  double BottomNumber = 2.0;
  int index = 2;
  puts("Enter bottom number:");
  while (scanf("%lf", &BottomNumber) == 1)
  {
    puts("Enter index:");
    scanf("%d", &index);
    printf("%.2lf's %d power is %.2lf.\n", BottomNumber, index, PowerOperation(BottomNumber, index));
  }
  return 0;
}

double PowerOperation(double n, int m)
{
  int i;
  double res = n;
  for (i = 1; i < m; i++)
  {
    res *= n;
  }
  return res;
}
