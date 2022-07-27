#include <stdio.h>
#include <stdlib.h>
#include "movie.h"

void InitializeList(List* plist) {
  plist->head = NULL;
  plist->end = NULL;
}

int ListIsEmpty(const List* plist) {
  if (plist->head == NULL)
    return 1;
  else
    return 0;
}

int listIsFull(const List* plist) {
  Node* pt;
  int full;

  pt = (Node*)malloc(sizeof(Node));
  if (pt == NULL)
    full = 1;
  else
    full = 0;
  free(pt);

  return full;
}

int AddItem(List* plist, Item item) {
  Node* pnew;

  pnew = (Node*)malloc(sizeof(Node));
  if (pnew == NULL)
    return 0;
  pnew->next = NULL;
  pnew->item = item;

  if (plist->head == NULL)
    plist->head = pnew;
  else
    plist->end->next = pnew;
  plist->end = pnew;

  return 1
}

unsigned int ListItemCount(List* plist) {
  unsigned int count = 0;
  Node* pnode = plist->head;

  while (pnode != NULL) {
    pnode = pnode->next;
    count++;
  }

  return count;
}

void Traverse(const List* plist, void(*pfun)(Item item)) {
  Node* pnode = plist->head;

  while (pnode != NULL) {
    (*pfun)(pnode->item);
    pnode = pnode->next;
  }
}

void DeleteAll(List* plist) {
  Node* pnode;

  while (plist->head != NULL) {
    pnode = plist->head;
    plist->head = plist->head->next;
    free(pnode);
  }
}