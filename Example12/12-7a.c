#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12-7b.h"

int main(void)
{
  int dice, roll;
  int sides;
  int status;
  int times;
  int i;

  srand((unsigned int)time(0));
  printf("ENter the number of sets; enter q to stop: ");
  while (scanf("%d", &times) == 1 && times > 0)
  {
    printf("How many sides and how many dice? ");
    if ((status = scanf("%d %d", &sides, &dice)) != 2)
    {
      if (status == EOF)
        break;
      else
      {
        printf("You should have entered an integer.");
        printf(" Let's begin agin.\n");
        while (getchar() != '\n')
          continue;
        printf("How many sides? Enter 0 to stop.\n");
        continue;
      }
    }
    for (i = 0; i < times; i++)
    {

      roll = roll_n_dice(dice, sides);
      printf("%d ", roll);
      if ((i + 1) % 15 == 0)
        putchar('\n');
    }
    putchar('\n');
    printf("How many sets? Enter q to stop:\n");
  }
  printf("The rollem() function was called %d times.\n", roll_count);
  printf("GOOD FORTUNE TO YOU!\n");

  return 0;
}