#include <stdio.h>

int main(void)

{
  const double BASICWAGE = 1000.0;
  const double WORKOVERTIME = 1.5;
  const double TAXRATE300 = 0.15;
  const double TAXRATE150 = 0.2;
  const double TAXRATE = 0.25;
  double hours;
  double totalSalary = 0;
  double tax = 0;
  double netIncome = 0;
  printf("Enter this week working time:\n");

  while (scanf("%lf", &hours) == 1 && hours > 0)
  {
    if (hours > 40)
    {
      hours = 40 + (hours - 40) * 1.5;
    }
    totalSalary = hours * BASICWAGE;
    tax = 300 * TAXRATE300 + 150 * TAXRATE150 + (totalSalary - 300 - 150) * TAXRATE;
    netIncome = totalSalary - tax;
    printf("Total salary: %.2lf\n", totalSalary);
    printf("Tax: %.2lf\n", tax);
    printf("Net income: %.2lf\n", netIncome);
  }
  return 0;
}