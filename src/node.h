#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>


typedef struct STPNode STPNode;
struct STPNode {
  STPNode *left;
  STPNode *right;
  int LeftCost;
  int RightCost;
  int VertexCost;
};


typedef struct Vertex Vertex;
struct Vertex {
  char *name;
  int value;
};


typedef struct Vertexlink Vertexlink;
struct Vertexlink{
  Vertex *next;
  int cost;
};




#endif // _NODE_H
