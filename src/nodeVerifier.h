#ifndef _NODEVERIFIER_H
#define _NODEVERIFIER_H
#include "Node.h"
#include "LinkedList.h"

#define TEST_ASSERT_EQUAL_NODE(left,right,bf,node) \
                          testAssertEqualNode(left,right,bf,node,__LINE__)

#define TEST_ASSERT_EQUAL_STRING_NODE(left,right,bf,node) \
                                                    testAssertEqualNodeString(left,right,bf,node,__LINE__)

#define TEST_ASSERT_EQUAL_VERTEX(name,PathCost,vertex) \
                                                    testAssertEqualVertex(name ,PathCost,vertex,__LINE__)


void testAssertEqualNode(Node *left, Node *right, int bf, Node *node,int lineNo);
void testAssertEqualNodeString(StringNode *left, StringNode *right, int bf, StringNode *node,int lineNo);
void testAssertEqualVertex(char* name ,int PathCost,Vertex *vertex,int lineNo);

#endif // _NODEVERIFIER_H
