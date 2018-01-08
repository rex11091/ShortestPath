#ifndef _INSERT_H
#define _INSERT_H
#include "node.h"
#include "rotate.h"

typedef int(*Compare)(void *add , Node *refNode);

//typedef int(*Compare)(void *targetData, void *treeNodedata);



int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare CompareFunc);


#endif // _INSERT_H
