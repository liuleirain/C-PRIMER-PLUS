#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 255

int main(int argc, char *argv[])
{
  char **words;
  int i, n, length;
  static char temp[LEN];

  printf("How many words do you wish to enter?");
  while (scanf("%d", &n) == 1 && n > 0)
  {

    if ((words = (char **)malloc(n * sizeof(char *))) != NULL)
    {
      printf("Enter %d words now:\n", n);
      for (i = 0; i < n; i++)
      {
        scanf("%255s", temp);
        length = strlen(temp) + 1;
        words[i] = (char *)malloc(length * sizeof(char));
        if (NULL == words[i])
        {
          printf("Memory allcation failed!\n");
          exit(EXIT_FAILURE);
        }
        strcpy(words[i], temp);
      }
      printf("Here are your words:\n");
      for (i = 0; i < n; i++)
      {
        printf("%s\n", words[i]);
        free(words[i]);
        words[i] = NULL;
      }
      free(words);
      words = NULL;
    }
    else
    {
      printf("Memory allcation failed!\n");
      exit(EXIT_FAILURE);
    }
    printf("How many words do you wish to enter? ");
  }
  return 0;
}