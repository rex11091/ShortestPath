#include "build/temp/_test_ShortestPath.c"
#include "CException.h"
#include "Exception.h"
#include "rotate.h"
#include "remove.h"
#include "avlAdd.h"
#include "ShortestPath.h"
#include "LinkedList.h"
#include "unity.h"


void setUp(void)

{



}



void tearDown(void)

{

}





void test_ShortestPath_create_node(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",9);

    Vertex *VC = createVertex("C",10);



    UnityAssertEqualNumber((UNITY_INT)(("A")), (UNITY_INT)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("b")), (UNITY_INT)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("C")), (UNITY_INT)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);



}



void test_ShortestPath_Vertexlink(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",9);

    Vertex *VC = createVertex("C",10);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};



    UnityAssertEqualNumber((UNITY_INT)((VC)), (UNITY_INT)((LAC.NextVertex)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((LAC.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((VB)), (UNITY_INT)((LAB.NextVertex)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((LAB.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);



}

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_vertex(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};



    addNeighbors(VA,2,&LAB,&LAC);



    if ((((VA->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(79))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(81))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(84));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(87));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_vertex1(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);

    Vertex *VE = createVertex("E",0);

    Vertex *VD = createVertex("D",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};

    Vertexlink LBD = {VD,1};

    Vertexlink LBE = {VE,4};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,2,&LBD,&LBE);



    if ((((VA->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(123))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(125))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(128));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(131));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(134))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(136))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(139));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(140), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(142));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

}



void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_vertex2(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VE = createVertex("E",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAB = {VB,2};

    Vertexlink LBD = {VD,1};

    Vertexlink LBE = {VE,4};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,2,&LBD,&LBE);



    Node *root = 

                ((void *)0)

                    ;

    avladdVertex(&root,VA);















    free(VA);

    free(VB);

    free(VC);

}
