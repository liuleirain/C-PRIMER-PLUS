#include <stdio.h>
#include <stdlib.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
  int *pa;
  int size;
  int value;

  printf("Enter the number of elements: ");
  while (scanf("%d", &size) == 1 && size > 0)
  {
    printf("Enter the initialization value: ");
    scanf("%d", &value);
    pa = make_array(size, value);
    if (pa)
    {
      show_array(pa, size);
      free(pa);
    }
    printf("Enter the number of elements (<1 to quit): ");
  }
  printf("Done.\n");
  return 0;
}

int *make_array(int elem, int val)
{
  int *parr = (int *)malloc(elem * sizeof(int));
  int i;
  if (NULL == parr)
  {
    printf("Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }
  printf("Output %d numbers:\n", val);
  for (i = 0; i < elem; i++)
  {
    parr[i] = val;
  }
  return parr;
}

void show_array(const int ar[], int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d ", ar[i]);
    if (0 == (i + 1) % 8)
    {
      putchar('\n');
    }
  }
  putchar('\n');
}