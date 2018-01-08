#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H


typedef struct Item Item;
typedef struct LinkedList LinkedList;
typedef struct Vertex Vertex;

struct Item{
  Item *next;
  Vertex *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;

};


struct Vertex {
  char *name;
  int value;
  LinkedList *list;
};

typedef struct Vertexlink Vertexlink;
struct Vertexlink{
  Vertex *next;
  int cost;
};




void ListInit(LinkedList *list);
void ListAdd(LinkedList *list, Item *item);
void createItem(Item *item, void *data, Item *next);

#endif // _LINKLIST_H
