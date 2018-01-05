#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


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

// A structure to represent an adjacency liat

// A utility function to create a new adjacency list node
Vertex *createVertex(char *name, int value)
{
    Vertex *newVertex=(Vertex*) malloc(sizeof(Vertex));
    newVertex->name = name;
    newVertex->value = value;
    return newVertex;
}



void addNeighbour(int zz, int NumberToaddNeighbour,...){

  va_list args;
  int i;
  va_start(args, NumberToaddNeighbour);
for(i=0;i<NumberToaddNeighbour;i++)
  printf("%d\n",va_arg(args,int ));
}
