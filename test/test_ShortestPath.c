#include "unity.h"
#include "stdlib.h"
#include "nodeHelper.h"
//#include "nodeVerifier.h"
#include "ShortestPath.h"

void setUp(void)
{
//  giveInitdata();
}

void tearDown(void)
{
}

void test_ShortestPath_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement ShortestPath");
}

/*
void test_Create_ShortestPath_tree_set(void)
{
    initNode(&node1,&node5,&node15,1,2,0);
    initNode(&node5,&node20,NULL,3,0,INFINITY);
    initNode(&node15,&node35,&node25,7,4,INFINITY);
    initNode(&node20,NULL,&node35,0,6,INFINITY);
    initNode(&node25,&node35,NULL,5,0,INFINITY);
    initNode(&node35,NULL,NULL,0,0,INFINITY);

}


void test_Create_ShortestPath_tree_set1(void)
{
    initNode(&node1,&node5,&node15,1,4,0);
    initNode(&node5,NULL,&node15,0,2,0);
    initNode(&node15,NULL,NULL,0,0,0);

    STPNode *main = &node1;

    ShortestPath(&main);
    TEST_ASSERT_EQUAL(1,node5.VertexCost);
    TEST_ASSERT_EQUAL(3,node15.VertexCost);
}
*/




void test_ShortestPath_create_node(void)
{
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",9);
    Vertex *VC = createVertex("C",10);

    Vertexlink LAC = {VC,2};

    //TEST_ASSERT_NULL(VB);
    TEST_ASSERT_EQUAL(9,VB->value);
    TEST_ASSERT_EQUAL("A",VA->name);
    TEST_ASSERT_EQUAL(VC,LAC.next);
    TEST_ASSERT_EQUAL(2,LAC.cost);
}

void test_ShortestPath_create_node1(void)
{
  addNeighbour(26,5,25,26,27,24,67);
}
