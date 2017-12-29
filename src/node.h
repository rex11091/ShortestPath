#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  void *data;    // will be change ltr ,no neccessary integer
};

typedef struct STPNode STPNode;
struct STPNode {
  STPNode *left;
  STPNode *right;
  int LeftCost;
  int RightCost;
  int Vertex;
};



#endif // _NODE_H
