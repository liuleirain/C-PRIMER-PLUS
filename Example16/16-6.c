#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 3
#define SIZE 40

struct names {
  char first[SIZE];
  char last[SIZE];
};

void fillarray(struct names* ar[NUM], int n);
void showarray(struct names ar[], int n);
int mycomp(const void* p1, const void* p2);
char* s_gets(char* st, int n);

int main(void) {
  struct names staff[NUM];
  struct names* ps[NUM];
  for (int i = 0; i < NUM; i++) {
    ps[i] = &staff[i];
  }
  fillarray(ps, NUM);
  puts("Source list:");
  showarray(staff, NUM);
  qsort(staff, NUM, sizeof(struct names), mycomp);
  puts("\nSorted list:");
  showarray(staff, NUM);
  return 0;
}

char* s_gets(char* st, int n) {
  char* ret_val;
  char* find;

  ret_val = fgets(st, n, stdin);
  if (ret_val) {
    find = strchr(st, '\n');
    if (find)
      *find = '\0';
    else
      while (getchar() != '\n')continue;
  }
  return ret_val;
}

void fillarray(struct names* ar[NUM], int n) {
  int index;
  char temp[SIZE];
  for (index = 0; index < n; index++) {
    puts("Please enter you first name:");
    s_gets(ar[index]->first, SIZE);
    puts("Enter your last name:");
    s_gets(ar[index]->last, SIZE);
  }
}

void showarray(struct names ar[], int n) {
  int index;

  for (index = 0; index < n; index++) {
    printf("%-10s %-10s\n", ar[index].first, ar[index].last);
  }
}

int mycomp(const void* p1, const void* p2)
{
  const struct names* a1 = (const struct names*)p1;
  const struct names* a2 = (const struct names*)p2;
  int res;
  res = strcmp(a1->first, a2->first);
  if (res) {
    return res;
  }
  else
    return strcmp(a1->last, a2->last);
}
