#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "12-12.h"

int main(void)
{
  int dice, roll;
  int sides;
  int status;
  int sets;

  srand((unsigned int)time(0));
  printf("Enter the number of sets; enter q to stop.\n");
  while ((scanf("%d", &sets)) == 1 && sets > 0)
  {
    printf("How many sides and how many dice?\n");
    while (scanf("%d %d", &sides, &dice) != 2)
    {
      while (getchar() != '\n')
        continue;
      printf("How many sides and how many dice?\n");
    }
    printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
    for (int i = 1; i < sets + 1; i++)
    {
      printf("%d ", roll_n_dice(dice, sides));
      if (i % 15 == 0)
        putchar('\n');
    }
    putchar('\n');
    printf("How many sets? Enter q to stop.\n");
  }
}