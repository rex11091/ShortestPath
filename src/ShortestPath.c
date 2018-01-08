#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "LinkedList.h"


/*
STPNode *ShortestPath(STPNode **mainNode)
{

  int tempVertexCost;
  if(*mainNode == NULL)
    return NULL;

  else{
    if(((*mainNode)->left)||((*mainNode)->right)==NULL){
      if((*mainNode)->LeftCost < (*mainNode)->RightCost)
      {
        ((*mainNode)->left)->VertexCost =(((*mainNode)->left)->VertexCost + (*mainNode)->LeftCost);

          if(((*mainNode)->left)->VertexCost < (*mainNode)->RightCost){

            if((*mainNode)->left->right == (*mainNode)->right){
                tempVertexCost = (((*mainNode)->left)->VertexCost + ((*mainNode)->left)->RightCost);
                  if(tempVertexCost < (*mainNode)->RightCost){
                    ((*mainNode)->right)->VertexCost = tempVertexCost;
                  }
                  else
                    ((*mainNode)->right)->VertexCost = (*mainNode)->RightCost;
              }
            else
            {
              ((*mainNode)->right)->VertexCost = (*mainNode)->RightCost;
            }

          }
      }
    }
    else
    {
      return NULL;
    }
  }

}

*/


Vertex *createVertex(char *name, int value)
{
    Vertex *newVertex=(Vertex*) malloc(sizeof(Vertex));
    newVertex->name = name;
    newVertex->value = value;

    newVertex->list = (LinkedList *)malloc(sizeof(LinkedList));
    ListInit(newVertex->list);
    return newVertex;
}


void addNeighbors(Vertex *vertex,Vertexlink *Vertexlink)
{
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,Vertexlink->next,NULL);
  ListAdd(vertex->list,newItem);
}

void addNeighbors1(Vertex *vertex,int numbofneighbors,...)
{
  int i;
  Vertexlink *Vtl;
  va_list args;
  va_start(args, numbofneighbors);
  for(i=0;i<numbofneighbors;i++){
  Vtl = va_arg(args,Vertexlink *);
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,Vtl->next,NULL);
  ListAdd(vertex->list,newItem);
  }
}
