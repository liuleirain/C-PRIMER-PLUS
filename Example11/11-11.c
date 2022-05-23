#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define ROW 10
#define COL 50

void ShowMenu(char (*st)[COL], int n);
void ShowOriginalList(char (*st)[COL], int n);
void ShowASCIIList(char (*st)[COL], int n);
void ShowLengthList(char (*st)[COL], int n);
void ShowWordList(char (*st)[COL], int n);
int word(char *st);

int main(int argc, char *argv[])
{
  char st[ROW][COL] = {
      "Thank you",
      "Your airport Please",
      "Where is the bus stop",
      "How old are you",
      "have a nice day",
      "What time do you need",
      "What is your name",
      "Our teacher is Miss white",
      "Good moring",
      "They are good boys"};
  char tempList[ROW][COL];
  int i;
  for (i = 0; i < ROW; i++)
  {
    strcpy(tempList[i], st[i]);
  }

  char choice;
  while (1)
  {
    ShowMenu(st, ROW);
    choice = getchar();
    while (getchar() != '\n')
      continue;
    if (choice == 'q')
      break;
    switch (choice)
    {
    case 'a':
      puts("Original string list:");
      ShowOriginalList(st, ROW);
      break;
    case 'b':
      puts("ASCII string list:");
      ShowASCIIList(tempList, ROW);
      break;
    case 'c':
      puts("Length string list:");
      ShowLengthList(tempList, ROW);
      break;
    case 'd':
      puts("Words string list:");
      ShowWordList(tempList, ROW);
      break;
    default:
      puts("You enter the incorrectly, Please re -enter");
    }
  }
  return 0;
}

int word(char *st)
{
  int length = 0;
  bool inword = false;

  while (*st)
  {
    if (!isspace(*st) && !inword)
    {
      inword = true;
      st++;
      length++;
    }
    else if (!isspace(*st) && inword)
    {
      st++;
      length++;
    }
    else if (isspace(*st) && inword)
    {
      inword = false;
      break;
    }
  }
  return length;
}

void ShowWordList(char (*st)[COL], int n)
{
  int i, j;
  char *temp;

  for (i = 0; i < n - 1; i++)
  {
    for (j = i; j < n; j++)
    {
      if (word(st[i]) > word(st[j]))
      {
        strcpy(temp, st[i]);
        strcpy(st[i], st[j]);
        strcpy(st[j], temp);
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    puts(st[i]);
  }
}

void ShowLengthList(char (*st)[COL], int n)
{
  int i, j;
  char *temp;
  for (i = 0; i < n - 1; i++)
  {
    for (j = i; j < n; j++)
    {
      if (strlen(st[i]) > strlen(st[j]))
      {
        strcpy(temp, st[i]);
        strcpy(st[i], st[j]);
        strcpy(st[j], temp);
      }
    }
  }
  for (i = 0; i < n; i++)
  {
    puts(st[i]);
  }
}

void ShowMenu(char (*st)[COL], int n)
{
  puts("Please select below:");
  puts("a) Original list\t\tb) ASCII list");
  puts("c) Length list\t\t\td) Word list");
  puts("q) quit");
}

void ShowOriginalList(char (*st)[COL], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    puts(st[i]);
  }
}

void ShowASCIIList(char (*st)[COL], int n)
{
  int i, j;
  char temp[COL];
  for (i = 0; i < n - 1; i++)
  {
    for (j = i; j < n; j++)
    {
      // puts(st[i]);
      if (strcmp(st[i], st[j]) > 0)
      {

        strcpy(temp, st[i]);
        strcpy(st[i], st[j]);
        strcpy(st[j], temp);
        // puts(temp);
      }
    }
  }

  for (i = 0; i < n; i++)
  {
    puts(st[i]);
  }
}