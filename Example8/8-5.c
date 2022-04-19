#include <stdio.h>
int main(void)
{
  int guess = 1;
  int response;
  printf("Pick an integer from 1 to 100. I will try to guess ");
  printf("it.\nRespond with a y if my guess is right and with");
  printf("\nan n if it is wrong.\n");
  while ((scanf("%d", &response)) == 1 && response != guess)
  {
    if (response < guess)
      printf("Too small!\n");
    else
      printf("Too big!\n");
    while (getchar() != '\n')
      continue;
  }
  printf("I knew I could do it!\n");
  return 0;
}