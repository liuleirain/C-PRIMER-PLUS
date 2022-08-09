#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

void InitializeList(List* plist) {
  int i;

  for (i = 0; i < MAXSIZE; i++) {
    strcpy((plist->entries[i]).title, "");
    (plist->entries[i]).rating = 0;
    plist->items = 0;

  }
}

int ListIsEmpty(const List* plist) {
  if (plist->items == 0)
    return 1;
  else
    return 0;
}

int ListIsFull(const List* plist) {
  if (plist->items == MAXSIZE)
    return 1;
  else
    return 0;
}

int AddItem(List* plist, Item item) {
  if (plist->items == MAXSIZE) {
    fprintf(stderr, "The list is full.\n");
    return 0;
  }

  plist->entries[plist->items] = item;
  (plist->items)++;

  return 1;
}

unsigned int ListItemCount(List* plist) {
  return plist->items;
}

void Traverse(const List* plist, void(*pfun)(Item item)) {
  int i;

  for (i = 0; i < plist->items; i++) {
    (*pfun)(plist->entries[i]);
  }
}

void DeleteAll(List* plist) {
  int i;

  for (i = 0; i < plist->items; i++) {
    strcpy((plist->entries[i]).title, "");
    (plist->entries[i]).rating = 0;
    plist->items = 0;
  }
}