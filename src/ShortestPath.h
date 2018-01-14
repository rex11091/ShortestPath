#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include "LinkedList.h"
#include "avlAdd.h"
#include "remove.h"
#include "node.h"


#define VertexaddAvl(root, nodeToAdd)  avlAdd(root,nodeToAdd,(Compare)CostCompare)
#define VertexRemoveNodeAvl(rootptr,nodeToAdd)      *avlRemove(rootptr,nodeToAdd,(Compare)CostCompare);

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
//LinkedList *ComputeShortestPath(Vertex *vertex);
Item *getVertexFromLinkedList(Vertex *vertex);

void createNodeofVertexLink(Node *node,Vertexlink *vertexlink);
void addNeighbors(Vertex *vertex,int numbofneighbors,...);
int avladdVertex(Node **root,Vertex *vertex);
int CostCompare(Vertexlink *nodedata, Node *refNode);
Node *findSmallestNode(Node **rootPtr);
void ListReplaceVertexPathCost(LinkedList *list,Node *VertexNode);




#endif // _SHORTESTPATH_H
