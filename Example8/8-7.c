#include <stdio.h>

int main(void)

{
  double basicWage;
  const double WORKOVERTIME = 1.5;
  const double TAXRATE300 = 0.15;
  const double TAXRATE150 = 0.2;
  const double TAXRATE = 0.25;
  double hours;
  double totalSalary = 0;
  double tax = 0;
  double netIncome = 0;
  char choice;
  while (1)
  {
    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("a) $8.75/hr\t\tb) $9.33/hr\n");
    printf("c) $10.00/hr\t\td) $11.20/hr\n");
    printf("q) quit\n");
    choice = getchar();
    while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'q')
    {
      printf("Please enter a, b, c, d or q\n");
      while (getchar() != '\n')
        continue;
      choice = getchar();
    }
    switch (choice)
    {
    case 'a':
      basicWage = 8.75;
      break;
    case 'b':
      basicWage = 9.33;
      break;
    case 'c':
      basicWage = 10.00;
      break;
    case 'd':
      basicWage = 11.20;
      break;
    }
    if (choice == 'q')
    {
      break;
    }
    printf("Enter this week working time:\n");

    scanf("%lf", &hours);
    if (hours > 0)
    {

      if (hours > 40)
      {
        hours = 40 + (hours - 40) * 1.5;
      }
      totalSalary = hours * basicWage;
      tax = 300 * TAXRATE300 + 150 * TAXRATE150 + (totalSalary - 300 - 150) * TAXRATE;
      netIncome = totalSalary - tax;
      printf("Total salary: %.2lf\n", totalSalary);
      printf("Tax: %.2lf\n", tax);
      printf("Net income: %.2lf\n", netIncome);
    }
    else
      printf("Please enter the corrent time.\n");
  }
  return 0;
}