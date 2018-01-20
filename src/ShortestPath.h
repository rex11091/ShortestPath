#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include "LinkedList.h"
#include "avlAdd.h"
#include "remove.h"
#include "node.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "Exception.h"
#include "CException.h"


#define VertexaddAvl(root, nodeToAdd)  avlAdd(root,nodeToAdd,(Compare)CostCompare);
#define VertexRemoveNodeAvl(rootptr,nodeToAdd)      *avlRemove(rootptr,nodeToAdd,(Compare)CostCompareforRemove);

Vertex *createVertex(char *name, int PathCost);
Vertex *SearchVertex(LinkedList *list, Vertex *vertex);
Item *getVertexFromLinkedList(Vertex *vertex);

void createNodeForAddAVL(Node *node,Vertexlink *vertexlink,Vertex *Vertex);
void addNeighbors(Vertex *vertex,int numbofneighbors,...);
void ComputeShortestPath(Node **root,Vertex *vertex);
int CostCompare(Vertexlink *nodedata, Node *refNode);
int CostCompareforRemove(int nodedata, Node *refNode);
Node *findSmallestNode(Node **rootPtr);
void ListReplaceAndUpdateVertexPathCost(Node *VertexNode);
Item *checking(Item *TempToPoint1,Item *TempToPoint2,Vertex *Vertex);




#endif // _SHORTESTPATH_H
