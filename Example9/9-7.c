#include <stdio.h>
#include <ctype.h>

void readCharacter(void);
int lookUp(char);

int main(void)
{
  readCharacter();
  return 0;
}

void readCharacter(void)
{
  char ch;
  int location;
  printf("Enter a character:");
  while ((ch = getchar()) != EOF)
  {
    if (ch == '\n')
    {
      printf("Enter character again:");
      continue;
    }
    location = lookUp(ch);
    if (location > 0)
    {
      printf("%c is a letter, it is location %d\n", ch, location);
    }
    else
      printf("%c isn't letter\n", ch);
  }
}

int lookUp(char a)
{
  if (isupper(a))
    return a - 'A' + 1;
  else if (islower(a))
    return a - 'a' + 1;
  else
    return -1;
}