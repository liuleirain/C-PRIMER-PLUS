#include <stdio.h>
#include <string.h>
#define N 20

int main(void)
{
  char firstName[N];
  char lastName[N];
  printf("Please enter your first name:");
  scanf("%s", firstName);
  printf("Please enter last name:");
  scanf("%s", lastName);
  printf("Your name is \"%20s %20s\"\n", firstName, lastName);
  printf("Your name is \"%-20s %-20s\"\n", firstName, lastName);
  printf("Your name is \"%*s %*s\"\n", strlen(firstName) + 3, firstName, strlen(lastName) + 3, lastName);
  return 0;
}