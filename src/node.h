#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>
#include "LinkedList.h"

typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  Vertexlink *data;    // will be change ltr ,no neccessary integerd
  Vertex *ParentVertex;  
};
typedef struct intNode intNode;
struct intNode{
  intNode *left;
  intNode *right;
  int balanceFactor;
  int height;
  uint32_t *data;
};

typedef struct StringNode StringNode;
struct StringNode {
  StringNode *left;
  StringNode *right;
  int balanceFactor;
  char *data;
};


#endif // _NODE_H
