#include <stdio.h>
#include <string.h>
#define N 20

int main(void)
{
  char firstName[N];
  char lastName[N];
  printf("Please enter your first name:");
  scanf("%s", firstName);
  printf("Please enter your last name:");
  scanf("%s", lastName);
  printf("%s %s\n", firstName, lastName);
  printf("%*d %*d\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));
  printf("%s %s\n", firstName, lastName);
  printf("%-*d %-*d\n", strlen(firstName), strlen(firstName), strlen(lastName), strlen(lastName));
  return 0;
}