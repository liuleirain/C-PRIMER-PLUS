#include <stdio.h>

int main(void)
{
  int i = 0, j, k, l;
  char letter;
  char start = 'A';
  printf("Enter a letter:");
  while (scanf("%c", &letter) == 1 && (letter < 'A' && letter > 'Z'))
  {
    printf("Enter the letters between 'A' to 'Z'");
  };
  // printf("%c", letter);
  while (start + i <= letter)
  {
    for (j = 0; j <= letter - start - i; j++)
    {
      printf(" ");
    }
    for (k = 0; k <= (letter - start) - (letter - start - i); k++)
    {
      printf("%c", start + k);
    }
    for (l = k - 2; l >= 0; l--)
    {
      printf("%c", start + l);
    }
    putchar('\n');
    i++;
  }
  return 0;
}