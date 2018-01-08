#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include "LinkedList.h"
#include "avlAdd.h"

//STPNode *ShortestPath(STPNode **mainNode);
Vertex *createVertex(char *name, int PathCost);
Vertex *SearchVertex(LinkedList *list, Vertex *vertex);
//LinkedList *ComputeShortestPath(Vertex *vertex);
Item *getVertexFromLinkedList(Vertex *vertex);

void addNeighbors(Vertex *vertex,int numbofneighbors,...);

#endif // _SHORTESTPATH_H
