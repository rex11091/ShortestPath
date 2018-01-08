#include "build/temp/_test_ShortestPath.c"
#include "ShortestPath.h"
#include "LinkedList.h"
#include "unity.h"


void setUp(void)

{



}



void tearDown(void)

{

}



void test_ShortestPath_NeedToImplement(void)

{

    UnityIgnore( (("Need to Implement ShortestPath")), (UNITY_UINT)(17));

}



void test_ShortestPath_create_node(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",9);

    Vertex *VC = createVertex("C",10);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};



    addNeighbors1(VA,2,LAB,LAC);





    if ((((VA->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(32))));};

    vt = (Vertex *)(VA->list->head->data);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(34));

    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((VB->value)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("A")), (UNITY_INT)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((VC)), (UNITY_INT)((LAC.next)), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((LAC.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_INT);





}
