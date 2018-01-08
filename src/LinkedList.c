#include "LinkedList.h"
#include <stdio.h>

void ListInit(LinkedList *list){
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void ListAdd(LinkedList *list, Item *item)
{
  if(list->len==0){
    list->head = item;
    list->tail = item;
    list->len  = 1;
    item->next = NULL;
  }
  else{
    list->tail->next=item;
    list->tail = item;
    list->len += 1;
    item->next = NULL;
  }
}

void createItem(Item *item, void *data, Item *next){
  item->data = data;
  item->next = next;
}
