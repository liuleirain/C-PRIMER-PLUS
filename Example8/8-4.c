#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
  bool inword = false;
  int letter = 0;
  int words = 0;
  char ch;
  float count;
  while ((ch = getchar()) != EOF)
  {
    if (ispunct(ch))
      continue;
    if (isalpha(ch))
      letter++;
    if (!isspace(ch) && !inword)
    {
      inword = true;
      words++;
    }
    if (isspace(ch) && inword)
      inword = false;
  }
  count = (float)letter / words;
  printf("letter is %d\n", letter);
  printf("words is %d\n", words);
  printf("ave is %.2f\n", count);
  return 0;
}