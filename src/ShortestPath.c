#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "LinkedList.h"

Vertex *createVertex(char *name, int value)
{
    Vertex *newVertex=(Vertex*) malloc(sizeof(Vertex));
    newVertex->name = name;
    newVertex->PathCost = value;

    newVertex->list = (LinkedList *)malloc(sizeof(LinkedList));
    ListInit(newVertex->list);
    return newVertex;
}


void addNeighbors(Vertex *vertex,int numbofneighbors,...)
{
  int i;
  Vertexlink *Vtl;
  va_list args;
  va_start(args, numbofneighbors);
  for(i=0;i<numbofneighbors;i++){
  Vtl = va_arg(args,Vertexlink *);
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,Vtl,NULL);
  ListAdd(vertex->list,newItem);
  }
}




/*
LinkedList *ComputeShortestPath(Vertex *vertex){
    Vertex *temp;
    LinkedList *templist  = vertex->list;

    Item *TempToPoint1 = NULL ;
  	Item *TempToPoint2 = templist->head;

  	if(templist->head == NULL)
  	return NULL;

  	else
  	{
  		while(TempToPoint2 !=NULL)
  		{
        if(TempToPoint2->data->value == INT_MAX){
        TempToPoint2->data->value = TempToPoint2->cost;
        }
        else if(TempToPoint2->data->value > TempToPoint2->cost){
        TempToPoint2->data->value = TempToPoint2->cost;
        }
        else
        {
        TempToPoint2->data->value = TempToPoint2->data->value;
        }
        //here is if the data->LinkedList have things then do storing cost to Vertex->value
        if(TempToPoint2->data->list->head!=NULL)
          {
            Item *previous = NULL;
            Item *current  = TempToPoint2->data->list->head;

            while(current !=NULL)
            {
              current->data->value = (TempToPoint2->data->value + current->cost);
              previous = current;
              current = current->next;
            }
          }

  			TempToPoint1 = TempToPoint2;
  			TempToPoint2 = TempToPoint2->next;
  	}
    return templist;
    }

}
*/
