#include "unity.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "ShortestPath.h"

void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}

void test_ShortestPath_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement ShortestPath");
}


void test_Create_ShortestPath_tree_set(void)
{
    initNode(&node1,&node5,&node15,0,0);
    initNode(&node5,&node20,&node35,2,0);
    initNode(&node15,&node35,&node25,1,0);
    initNode(&node20,NULL,&node35,6,0);
    initNode(&node25,&node35,NULL,3,0);
    initNode(&node1,&node5,&node15,0,0);

    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);

}
