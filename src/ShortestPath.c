#include "ShortestPath.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "LinkedList.h"

CEXCEPTION_T ex;

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
    node->ParentVertex = Vertex;    // the source of neigbour for adding the source's pathcost with cost
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
         return current;
        }
  }
  else{
     return *rootPtr;
  }
}

void ListReplaceAndUpdateVertexPathCost(Node *VertexNode)
{
	Item *temp = VertexNode->ParentVertex->list->head;
	for(temp; temp!=NULL;temp = temp->next){
		if(temp->data->NextVertex == VertexNode->data->NextVertex){
      if(temp->data->NextVertex->PathCost == INT_MAX){
        temp->data->NextVertex->PathCost = (VertexNode->data->cost + VertexNode->ParentVertex->PathCost);
      }
      else{
        //here is if(vertex's path cost + vertexlink->cost >  NextVertex->Pathcost than remain )
        if(temp->data->NextVertex->PathCost > VertexNode->data->cost + VertexNode->ParentVertex->PathCost)
        temp->data->NextVertex->PathCost = ( VertexNode->data->cost + VertexNode->ParentVertex->PathCost);
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
          if(TempToPoint2->data->NextVertex->PathCost !=INT_MAX){
            int AddPathCost = (TempToPoint2->data->cost + vertex->PathCost );
              if(AddPathCost > TempToPoint2->data->NextVertex->PathCost )
              {
              TempToPoint1 = TempToPoint2;
              TempToPoint2 = TempToPoint2->next;
            }
            else{
              TempToPoint2 = TempToPoint2;
            }
          }
      		while(TempToPoint2 !=NULL)
      		{
            Node *newNode = (Node *)malloc(sizeof(Node));
            createNodeForAddAVL(newNode,TempToPoint2->data,vertex);

            Try{
            // adding duplicated to avl and it will throw str do the node and will be catch 
            //  do the duplicated node first
            VertexaddAvl(root,newNode);

            }Catch(ex){

            ListReplaceAndUpdateVertexPathCost(newNode);        // update the vertex's pathcost of the node
            Vertex *temp = newNode->data->NextVertex;
            if(temp->list->head!=NULL)                          //checking the node have neighbour?
            ComputeShortestPath(root,temp);
          }
          
			      TempToPoint1 = TempToPoint2;
            TempToPoint2 = TempToPoint2->next;

      	}
      }
        while(*root!=NULL){
           smallestCost = findSmallestNode(root);               //find smallest node in avltree
           Vertex *tempVertex = smallestCost->data->NextVertex;
           int *nodetoRemove = (int*)((uintptr_t)(smallestCost->data->cost)); 
           ListReplaceAndUpdateVertexPathCost(smallestCost);    // do updated vertex's path cost
           VertexRemoveNodeAvl(root,nodetoRemove);              // delete the smallest node on avl
          if(tempVertex->list->head!=NULL){                     // checking the vertex have neighbour?
           ComputeShortestPath(root,tempVertex);                // redo the process
          }
    }
    return;
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
