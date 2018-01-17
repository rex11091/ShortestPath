#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include "LinkedList.h"
#include "avlAdd.h"
#include "remove.h"
#include "node.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"


#define VertexaddAvl(root, nodeToAdd)  avlAdd(root,nodeToAdd,(Compare)CostCompare);
#define VertexRemoveNodeAvl(rootptr,nodeToAdd)      *avlRemove(rootptr,nodeToAdd,(Compare)CostCompareforRemove);

/*
typedef struct VertexNode VertexNode;
struct VertexNode {
  VertexNode *left;
  VertexNode *right;
  int balanceFactor;
  Vertexlink *data;
};
*/

Vertex *createVertex(char *name, int PathCost);
Vertex *SearchVertex(LinkedList *list, Vertex *vertex);
Item *getVertexFromLinkedList(Vertex *vertex);

void createNodeForAddAVL(Node *node,Vertexlink *vertexlink,Vertex *Vertex);
void addNeighbors(Vertex *vertex,int numbofneighbors,...);
LinkedList *ComputeShortestPath(Node **root,Vertex *vertex);
int CostCompare(Vertexlink *nodedata, Node *refNode);
int CostCompareforRemove(int nodedata, Node *refNode);
Node *findSmallestNode(Node **rootPtr);
void ListReplaceVertexPathCost(Node *VertexNode);
void freeVertexNode(Node *Vertexroot);




#endif // _SHORTESTPATH_H
