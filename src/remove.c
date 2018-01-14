#include "remove.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"
#include "Exception.h"
#include "CException.h"



Node *findnearest(Node **rootPtr, int *heightchange)
{
Node *temp1;
Node *current = (*rootPtr)->left;
    /* loop down to find the leftmost leaf */
 if(current!=NULL){
      if(current->left != NULL)
         findnearest(&(*rootPtr)->left,heightchange);
     else{
         if(current->right !=NULL){
          (*rootPtr)->left = current->right;
          (*rootPtr)->balanceFactor +=1;
           current->right = NULL;
           *heightchange = CHANGED;
         }
         else{
           (*rootPtr)->left = NULL;
           (*rootPtr)->balanceFactor +=1;
           if((*rootPtr)->balanceFactor >= 2)
              avlBalanceRightTree(&(*rootPtr));
           else if((*rootPtr)->balanceFactor <= -2)
              avlBalanceLeftTree(&(*rootPtr));
           else{
                (*rootPtr) = (*rootPtr);
               }
            if((*rootPtr)->balanceFactor!=0)
              *heightchange = UNCHANGE;
           else
             *heightchange = CHANGED;
         }
       return current;
        }
  }
  else
    temp1 = *rootPtr;
    *heightchange = CHANGED;
     *rootPtr = NULL;
     return temp1;
 }


Node *avlRemove(Node **rootPtr, int data,Compare CompareFunc){
    int heightchange;
    Node *avlRemove = _avlRemove(rootPtr, data, &heightchange,CompareFunc);
    if(avlRemove == NULL){
        printf("deleted value doesn't exist!");
    }
    return avlRemove;
}


Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange,Compare CompareFunc){

        Node *temp = *root;
        //heightchange to determine either root's heigh change or unchange
       //standard removing
       // 0 is no height change
       if (*root == NULL)
           return NULL; //heigh change

       int compareResult = CompareFunc((void *)nodeToRemove,*root);
       if(compareResult==-1){
         if(temp->left==NULL){
           Throw(createException("This data cannot be found in this Avl tree ",Data_not_found));
           *heightchange = UNCHANGE;
           return temp;
         }
         temp=_avlRemove(&(*root)->left, nodeToRemove,heightchange,CompareFunc);
         if(*heightchange == CHANGED)
            (*root)->balanceFactor +=1;
            if((*root)->balanceFactor != 0)
            *heightchange = UNCHANGE;
       }
       else  if(compareResult==1){
         if(temp->right==NULL){
           Throw(createException("This data cannot be found in this Avl tree ",Data_not_found));
          *heightchange = UNCHANGE;
           return temp;
         }
         temp=_avlRemove(&(*root)->right, nodeToRemove,heightchange,CompareFunc);
         if(*heightchange==CHANGED)
            (*root)->balanceFactor -=1;
            if((*root)->balanceFactor != 0)
            *heightchange = UNCHANGE;
       }
       else if(compareResult==0){
           // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *current = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (current == NULL)
             {
                 current = *root;
                 *root = NULL;
                 *heightchange=CHANGED; //heigh change
             }
             else // One child case
             {
              *root = current; // Copy the contents of the non-empty child
              *heightchange=CHANGED; // height change
             }
        }
        else// node with two children case
        {
            //find the nearest in removenode->right->most left
            Node* temp1 = findnearest(&(*root)->right,heightchange);
            //checking whether have heightchange ?
            if(*heightchange==CHANGED){
            (*root)->balanceFactor -=1;
              if((*root)->balanceFactor !=0)
              *heightchange = UNCHANGE;
            }
            else{
            (*root)->balanceFactor=(*root)->balanceFactor;
            *heightchange = CHANGED;
            }
            // Copy the nearest's data to this node
            if(temp1->right!=NULL){
              temp1->balanceFactor = ((*root)->balanceFactor);
              temp1->left = (*root)->left;
              (*root) = temp1;
            }
            else{
            temp1->balanceFactor = ((*root)->balanceFactor);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;
            }
             if(*root==NULL){
               return temp;
             }
			       if((*root)->balanceFactor >= 2)
                avlBalanceRightTree(&(*root));
             else if((*root)->balanceFactor <= -2)
                 avlBalanceLeftTree(&(*root));
             else{
                *root = *root;
               }
            if((*root)->balanceFactor == 0)
            *heightchange = CHANGED;
            else
            *heightchange = UNCHANGE;
            return temp;
        }
    }
    if(*root==NULL){
          return temp;
        }
    if((*root)->balanceFactor >= 2)
          avlBalanceRightTree(&(*root));
    else if((*root)->balanceFactor <= -2)
          avlBalanceLeftTree(&(*root));
    else{
          *root = *root;
        }
    if((*root)->balanceFactor == 0)
        *heightchange = CHANGED;
    else
        *heightchange = UNCHANGE;
    return temp;
}
