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


void createNodeForAddAVL(Node *node,Vertexlink *vertexlink,Vertex *Vertex){
    node->left = NULL;
    node->right = NULL;
    node->balanceFactor =0;
    node->ParentVertex = Vertex;    // the parent of the child.
    node->data = vertexlink;
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

void ListReplaceAndUpdateVertexPathCost(Node *VertexNode)
{
	Item *temp = VertexNode->ParentVertex->list->head;
	for(temp; temp!=NULL;temp = temp->next){
		if(temp->data->NextVertex == VertexNode->data->NextVertex){
      if(temp->data->NextVertex->PathCost == INT_MAX){
        temp->data->NextVertex->PathCost = (VertexNode->data->cost +VertexNode->ParentVertex->PathCost);
      }
      else{
        //here is if(vertex's path cost + vertexlink->cost >  NextVertex->Pathcost than remain )
        if(temp->data->NextVertex->PathCost > (VertexNode->ParentVertex->PathCost + VertexNode->data->cost))
        temp->data->NextVertex->PathCost = (VertexNode->ParentVertex->PathCost + VertexNode->data->cost);
        else
        temp->data->NextVertex->PathCost = temp->data->NextVertex->PathCost;
      }
  }
 }
}


/**
*/

void ComputeShortestPath(Node **root,Vertex *vertex){
    Node *smallestCost;
    LinkedList *templist  = vertex->list;
    Item *TempToPoint1 = NULL ;
    Item *TempToPoint2 = templist->head;

      	if(templist->head == NULL)
      	return ;

      	else
      	{
      		while(TempToPoint2 !=NULL)
      		{
            Node *newNode = (Node *)malloc(sizeof(Node));
            createNodeForAddAVL(newNode,TempToPoint2->data,vertex);
            VertexaddAvl(root,newNode);
      			TempToPoint1 = TempToPoint2;
            TempToPoint2 = TempToPoint2->next;

      	}
      }
        while(*root!=NULL){
           smallestCost = findSmallestNode(root);
           Vertex *tempVertex = smallestCost->data->NextVertex;
           int *nodetoRemove = (int*)((uintptr_t)(smallestCost->data->cost));
           ListReplaceAndUpdateVertexPathCost(smallestCost);
           VertexRemoveNodeAvl(root,nodetoRemove);
          if(tempVertex->list->head!=NULL){
           ComputeShortestPath(root,tempVertex);
          }
    }
    return;
}



void freeVertexNode(Node *Vertexroot){
  if(Vertexroot ==NULL){
  return;
  }
  freeVertexNode(Vertexroot->right);
  freeVertexNode(Vertexroot->left);
  free(Vertexroot->data);
  free(Vertexroot->ParentVertex);
  free(Vertexroot);
}

int CostCompare(Vertexlink *nodedata, Node *refNode)
{
  int data  = nodedata->cost;
	int data1 = refNode->data->cost;

  if (data < data1)
  {
    return -1;
  }
  else if(data > data1)
  {
    return 1;
  }
  else
    return 0;
}
int CostCompareforRemove(int nodedata, Node *refNode)
{
	int data1 = refNode->data->cost;

  if (nodedata < data1)
  {
    return -1;
  }
  else if(nodedata > data1)
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
