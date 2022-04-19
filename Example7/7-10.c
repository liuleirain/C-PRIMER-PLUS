#include <stdio.h>
#define SINGLE 17850
#define HOUSEHOLD 23900
#define MARRIEDTOTAL 29750
#define MARRIEDDIVORCED 14875

int main(void)
{
  int income;
  double tax;
  char choice;
  while (1)
  {
    tax = 0.0;
    choice = '5';
    printf("Please select your category:\n");
    printf("1) Single\t\t2) House Hold\n");
    printf("3) Married Total\t4) Married Divorced\n");
    printf("5) quit\n");
    choice = getchar()

        // printf("%c", choice);

        if (choice == '5')
    {
      break;
    }
    else
    {
      printf("Enter your income:\n");
      scanf("%d", &income);
    }
    switch (choice)
    {
    case '1':
      if (income > SINGLE)
        tax = 0.15 * SINGLE + 0.28 * (income - SINGLE);
      else
        tax = 0.15 * income;
      break;
    case '2':
      if (income > HOUSEHOLD)
        tax = 0.15 * HOUSEHOLD + 0.28 * (income - HOUSEHOLD);
      else
        tax = 0.15 * income;
      break;
    case '3':
      if (income > MARRIEDTOTAL)
        tax = 0.15 * MARRIEDTOTAL + 0.28 * (income - MARRIEDTOTAL);
      else
        tax = 0.15 * income;
      break;
    case '4':
      if (income > MARRIEDDIVORCED)
        tax = 0.15 * MARRIEDDIVORCED + 0.28 * (income - MARRIEDDIVORCED);
      else
        tax = 0.15 * income;
      break;
    default:
      printf("Please enter a number between 1-4.\n");
      getchar();
      break;
    }
    if (tax > 0)
    {

      printf("Your need pay $%.2lf a $%d salary taxes.\n", tax, income);
      getchar();
    }
  }
  printf("Done.\n");
  return 0;
}