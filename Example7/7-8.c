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
  int choice;
  while (1)
  {

    printf("Enter the number corresponding to the desired pay rate or action:\n");
    printf("1) $8.75/hr\t\t2) $9.33/hr\n");
    printf("3) $10.00/hr\t\t4) $11.20/hr\n");
    printf("5) quit\n");
    while (scanf("%d", &choice) != 1 && (choice <= 1 && choice >= 5))
    {
      printf("Please enter a number between 1 to 5:\n");
    }
    switch (choice)
    {
    case 1:
      basicWage = 8.75;
      break;
    case 2:
      basicWage = 9.33;
      break;
    case 3:
      basicWage = 10.00;
      break;
    case 4:
      basicWage = 11.20;
      break;
    }
    if (choice == 5)
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