#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define LEN 60

int main(int argc, char *argv)
{
  int words, upletter, loletter, punct, digit;
  words = upletter = loletter = punct = digit = 0;
  char ch;
  bool inword = false;
  while (ch = getchar() && ch != EOF)
  {
    if (isupper(ch))
    {
      upletter++;
    }
    else if (islower(ch))
    {
      loletter++;
    }
    else if (ispunct(ch))
    {
      punct++;
    }
    else if (isdigit(ch))
    {
      digit++;
    }
    if (!isspace(ch) && !inword)
    {
      words++;
      inword = true;
    }
    else if (isspace(ch) && inword)
    {
      inword = false;
    }
  }

  printf("Words: %d\n", words);
  printf("Upper: %d\n", upletter);
  printf("Lower: %d\n", loletter);
  printf("Punct: %d\n", punct);
  printf("Digit: %d\n", digit);

  return 0;
}