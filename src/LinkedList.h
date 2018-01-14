#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct Item Item;
typedef struct LinkedList LinkedList;
typedef struct Vertex Vertex;
typedef struct Vertexlink Vertexlink;

struct Item{
  Item *next;
  Vertexlink *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;

};

struct Vertex {
  char *name;
  int PathCost;
  LinkedList *list;
};


struct Vertexlink{
  Vertex *NextVertex;
  int cost;
};


void ListInit(LinkedList *list);
void ListAdd(LinkedList *list, Item *item);
void createItem(Item *item, Vertexlink *vertexlink,Item *next);

#endif // _LINKLIST_H
