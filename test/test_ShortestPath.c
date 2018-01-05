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
    initNode(&node1,&node5,&node15,1,2,0);
    initNode(&node5,&node20,NULL,3,0,INFINITY);
    initNode(&node15,&node35,&node25,7,4,INFINITY);
    initNode(&node20,NULL,&node35,0,6,INFINITY);
    initNode(&node25,&node35,NULL,5,0,INFINITY);
    initNode(&node35,NULL,NULL,0,0,INFINITY);

}
