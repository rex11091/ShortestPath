#include "unity.h"
#include "stdlib.h"
#include "LinkedList.h"
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

void test_ShortestPath_create_node(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",9);
    Vertex *VC = createVertex("C",10);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    //addNeighbors(VA,&LAC);
    addNeighbors1(VA,2,LAB,LAC);

    //TEST_ASSERT_NULL(VB);
    TEST_ASSERT_NOT_NULL(VA->list->head);
    vt = (Vertex *)(VA->list->head->data);
    TEST_ASSERT_EQUAL_STRING("b",vt->name);
    TEST_ASSERT_EQUAL(9,VB->value);
    TEST_ASSERT_EQUAL("A",VA->name);
    TEST_ASSERT_EQUAL(VC,LAC.next);
    TEST_ASSERT_EQUAL(2,LAC.cost);


}
