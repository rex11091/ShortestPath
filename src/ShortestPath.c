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
  //free(newItem);
  }
}

/**
*/

int avladdVertex(Node **root,Vertex *vertex){
    Node *smallestCost;
    LinkedList *templist  = vertex->list;
    Item *TempToPoint1 = NULL ;
    Item *TempToPoint2 = templist->head;

      	if(templist->head == NULL)
      	return 0;

      	else
      	{
      		while(TempToPoint2 !=NULL)
      		{
            Node *newNode = (Node *)malloc(sizeof(Node));
            createNodeofVertexLink(newNode,TempToPoint2->data);
            VertexaddAvl(root,newNode);
      			TempToPoint1 = TempToPoint2;
            TempToPoint2 = TempToPoint2->next;

      	}
      }
        while(root!=NULL){
           smallestCost = findSmallestNode(root);
           Vertex *tempVertex = smallestCost->data->NextVertex;
           ListReplaceVertexPathCost(templist,smallestCost);
           VertexRemoveNodeAvl(root,smallestCost->data);
          if(tempVertex->list->head!=NULL){
           avladdVertex(root,tempVertex);
          }
    }
}




Node *findSmallestNode(Node **rootPtr)
{
Node *temp1;
Node *current = (*rootPtr)->left;
    /* loop down to find the leftmost leaf */
 if(current!=NULL){
      if(current->left != NULL)
         findSmallestNode(&(*rootPtr)->left);
     else{
         if(current->right !=NULL){
          return current->right;
        }
        else
         return current;
        }
  }
  else
    temp1 = *rootPtr;
     return temp1;
    }
    




    
void ListReplaceVertexPathCost(LinkedList *list,Node *VertexNode)
{
	Item *temp;
	for(temp = list->head; temp!=NULL;temp = temp->next){
		if(temp->data->NextVertex == VertexNode->data->NextVertex){
      if(temp->data->NextVertex == INT_MAX){
        temp->data->NextVertex->PathCost = VertexNode->data->cost;
      }
      else{
        if(temp->data->NextVertex->PathCost < VertexNode->data->cost)
        temp->data->NextVertex->PathCost = VertexNode->data->cost;
        else
        temp->data->NextVertex->PathCost = temp->data->NextVertex->PathCost;
      }
  }
 }
}







void createNodeofVertexLink(Node *node,Vertexlink *vertexlink){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->data = vertexlink;
}

int CostCompare(Vertexlink *nodedata, Node *refNode)
{
	
	int data1 = refNode->data->cost;

  int data2 = nodedata->cost;

  if (data2 < data1)
  {
    return -1;
  }
  else if(data2 > data1)
  {
    return 1;
  }
  else
    return 0;
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
