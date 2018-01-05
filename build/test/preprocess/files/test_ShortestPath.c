#include "build/temp/_test_ShortestPath.c"
#include "ShortestPath.h"
#include "nodeHelper.h"
#include "unity.h"




void setUp(void)

{



}



void tearDown(void)

{

}



void test_ShortestPath_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement ShortestPath")), (UNITY_UINT)(18));

}

void test_ShortestPath_create_node(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",9);

    Vertex *VC = createVertex("C",10);



    Vertexlink LAC = {VC,2};





    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((VB->value)), (

   ((void *)0)

   ), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("A")), (UNITY_INT)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(61), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((VC)), (UNITY_INT)((LAC.next)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((LAC.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);

}



void test_ShortestPath_create_node1(void)

{

  addNeighbour(26,3,25,26,27);

}
