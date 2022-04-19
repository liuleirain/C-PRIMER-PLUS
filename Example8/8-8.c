#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char get_first(void);
float get_num(void);
char get_choice(void);

int main(void)
{
  char choice;
  float first_num;
  float second_num;
  while (1)
  {

    while ((choice = get_choice()) != 'q')
    {

      printf("Enter first number:");
      first_num = get_num();
      printf("Enter second number:");
      second_num = get_num();
      switch (choice)
      {
      case 'a':
        printf("%g + %g = %g\n", first_num, second_num, first_num + second_num);
        break;
      case 's':
        printf("%g - %g = %g\n", first_num, second_num, first_num - second_num);
        break;
      case 'm':
        second_num = get_num();
        printf("%g x %g = %g\n", first_num, second_num, first_num * second_num);
        break;
      case 'd':
        while (fabs(second_num) <= 1e-6)
        {
          printf("Enter a number other than 0:");
          second_num = get_num();
        }
        printf("%g / %g = %g\n", first_num, second_num, first_num / second_num);
        break;
      }
    }
  }
  return 0;
}

char get_choice(void)
{
  char ch;
  printf("Enter the operation of your choice:\n");
  printf("a. add\t\t\ts. subtract\n");
  printf("m. multiply\t\td. divide\n");
  printf("q. quit\n");
  ch = get_first();
  while (ch != 'a' && ch != 's' && ch != 'm' && ch != 'd')
  {
    printf("Please enter with a, s, m, d or q :");
    ch = get_first();
  }
  return ch;
}

char get_first(void)
{
  char ch;
  do
  {
    ch = tolower(getchar());
  } while (isspace(ch));
  while (getchar() != '\n')
    continue;
  return ch;
}

float get_num(void)
{
  float num;
  char ch;
  while (scanf("%f", &num) != 1)
  {
    while ((ch = getchar()) != '\n')
      putchar(ch);
    printf(" is not a number.\n");
    printf("Please enter a number, such as 2.5, -1.78E8, or 3:");
  }

  return num;
}