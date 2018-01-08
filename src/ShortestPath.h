#ifndef _SHORTESTPATH_H
#define _SHORTESTPATH_H

#include "LinkedList.h"

//STPNode *ShortestPath(STPNode **mainNode);
Vertex *createVertex(char *name, int value);
void addNeighbors(Vertex *vertex,Vertexlink *Vertexlink);
void addNeighbors1(Vertex *vertex,int numbofneighbors,...);

#endif // _SHORTESTPATH_H
