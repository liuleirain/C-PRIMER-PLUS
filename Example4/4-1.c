#include <stdio.h>
#define N 20

int main(void)
{
  char firstName[N] = {0};
  char lastName[N] = {0};
  printf("Please enter your first name:");
  scanf("%s", firstName);
  printf("Please enter your last name:");
  scanf("%s", lastName);
  printf("Your name is %s %s.\n", firstName, lastName);
  return 0;
}