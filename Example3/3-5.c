#include <stdio.h>
#define PERYEARSECONDS 3.156E7

int main(void)
{
  int age;
  printf("Please enter your age:");
  scanf("%d", &age);
  printf("Your age is corresponding to the %e seconds\n", PERYEARSECONDS * age);
  return 0;
}