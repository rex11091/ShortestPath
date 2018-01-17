#include "build/temp/_test_ShortestPath.c"
#include "CException.h"
#include "Exception.h"
#include "nodeVerifier.h"
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

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("b")), (UNITY_INT)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)(("C")), (UNITY_INT)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);



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

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((LAC.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((VB)), (UNITY_INT)((LAB.NextVertex)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((LAB.cost)), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);



}



void test_ShortestPath_CreateNodeForInsertAVL(void)

{



    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);



    if ((((VertexNodeB)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(76))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VertexNodeB->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((&LAB)), (UNITY_INT64)((VertexNodeB->data)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX64);

    if ((((VertexNodeC)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(79))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VertexNodeC->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((&LAC)), (UNITY_INT64)((VertexNodeC->data)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX64);



    free(VertexNodeC);

    free(VertexNodeB);

    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_Graph1(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};



    addNeighbors(VA,2,&LAB,&LAC);



    if ((((VA->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(111))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(113))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(116));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(119));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_Graph2(void)

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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(155))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(156), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(157))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(160));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(161), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(163));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(166))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(168))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(171));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(174));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(175), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_Graph3(void)

{ Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);

    Vertex *VE = createVertex("E",0);

    Vertex *VD = createVertex("D",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAE = {VE,5};

    Vertexlink LAB = {VB,3};

    Vertexlink LBD = {VD,1};

    Vertexlink LBE = {VE,4};



    addNeighbors(VA,3,&LAB,&LAC,&LAE);

    addNeighbors(VB,2,&LBD,&LBE);



    if ((((VA->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(212))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(214))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(216))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((VA->list->head->next->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(217), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(219));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(220), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(222));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(223), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(225));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(228))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(229), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(230))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(231), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(233));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(236));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(237), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);

}

void test_ShortestPath_VertexaddAvl_add_VertexNodeB_VertexNodeC_VertexNodeD_to_avl_expect_balance(void)

{

    Vertex *VA = createVertex("a",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);

    Vertex *VD = createVertex("D",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};

    Vertexlink LAD = {VD,1};



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    Node *VertexNodeD = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    createNodeForAddAVL(VertexNodeD,&LAD,VA);





    avlAdd(&VertexNodeC,VertexNodeB,(Compare)CostCompare);;

    avlAdd(&VertexNodeC,VertexNodeD,(Compare)CostCompare);;



    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,276);



    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_VertexaddAvl_Finding_smallestNode_when_only_root_expect_return_VertexNodeC(void)

{

    Vertex *VA = createVertex("a",0);

    Vertex *VC = createVertex("C",0);



    Vertexlink LAC = {VC,2};



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeC,&LAC,VA);



    Node *root = VertexNodeC;



    Node *smallest = findSmallestNode(&root);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(308), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VC);

    free(VA);



}

void test_ShortestPath_VertexaddAvl_Finding_smallestNode_expect_return_VertexNodeD(void)

{

    Vertex *VA = createVertex("a",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);

    Vertex *VD = createVertex("D",0);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};

    Vertexlink LAD = {VD,1};



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    Node *VertexNodeD = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    createNodeForAddAVL(VertexNodeD,&LAD,VA);



    Node *root = VertexNodeC;



    avlAdd(&root,VertexNodeB,(Compare)CostCompare);;

    avlAdd(&root,VertexNodeD,(Compare)CostCompare);;

    Node *smallest = findSmallestNode(&root);

    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,345);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(346), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VB);

    free(VC);



}















void test_ShortestPath_VertexaddAvl_Finding_smallestNode_expect_return_VertexNodeE(void)

{

    Vertex *VA = createVertex("a",0);

    Vertex *VB = createVertex("b",0);

    Vertex *VC = createVertex("C",0);

    Vertex *VD = createVertex("D",0);

    Vertex *VE = createVertex("E",0);



    Vertexlink LAC = {VC,4};

    Vertexlink LAB = {VB,5};

    Vertexlink LAD = {VD,2};

    Vertexlink LAE = {VE,3};



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    Node *VertexNodeD = (Node *)malloc(sizeof(Node));

    Node *VertexNodeE = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    createNodeForAddAVL(VertexNodeD,&LAD,VA);

    createNodeForAddAVL(VertexNodeE,&LAE,VA);



    Node *root = VertexNodeC;



    avlAdd(&root,VertexNodeB,(Compare)CostCompare);;

    avlAdd(&root,VertexNodeD,(Compare)CostCompare);;

    avlAdd(&root,VertexNodeE,(Compare)CostCompare);;

    Node *smallest = findSmallestNode(&root);

    testAssertEqualNode(VertexNodeD,VertexNodeB,-1,VertexNodeC,389);

    testAssertEqualNode(

   ((void *)0)

   ,VertexNodeE,1,VertexNodeD,390);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(391), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VertexNodeE);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);



}

void test_ShortestPath_test_ListReplaceAndUpdateVertexPathCost(void){

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAB = {VB,2};





    addNeighbors(VA,2,&LAB,&LAC);



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    ListReplaceAndUpdateVertexPathCost(VertexNodeC);

    ListReplaceAndUpdateVertexPathCost(VertexNodeB);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(433));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(434), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(435));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(436), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_test_ListReplaceAndUpdateVertexPathCost_with_NextVertex_PC_smaller_than_PC_Plus_cost_expected_no_update(void){

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAD = {VD,3};

    Vertexlink LAB = {VB,2};

    Vertexlink LBD = {VD,4};





    addNeighbors(VA,3,&LAB,&LAC,&LAD);

    addNeighbors(VB,1,&LBD);



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    Node *VertexNodeD = (Node *)malloc(sizeof(Node));

    Node *VNDafterUpdate = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    createNodeForAddAVL(VertexNodeD,&LAD,VA);

    createNodeForAddAVL(VNDafterUpdate,&LBD,VB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeC);

    ListReplaceAndUpdateVertexPathCost(VertexNodeB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeD);

    ListReplaceAndUpdateVertexPathCost(VNDafterUpdate);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(489));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(490), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(491));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(492), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(493));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(494), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VNDafterUpdate);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_test_ListReplaceAndUpdateVertexPathCost_with_NextVertex_PC_smaller_than_PC_Plus_cost_expected_update(void){

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAD = {VD,7};

    Vertexlink LAB = {VB,2};

    Vertexlink LBD = {VD,3};





    addNeighbors(VA,3,&LAB,&LAC,&LAD);

    addNeighbors(VB,1,&LBD);



    Node *VertexNodeC = (Node *)malloc(sizeof(Node));

    Node *VertexNodeB = (Node *)malloc(sizeof(Node));

    Node *VertexNodeD = (Node *)malloc(sizeof(Node));

    Node *VNDafterUpdate = (Node *)malloc(sizeof(Node));

    createNodeForAddAVL(VertexNodeB,&LAB,VA);

    createNodeForAddAVL(VertexNodeC,&LAC,VA);

    createNodeForAddAVL(VertexNodeD,&LAD,VA);

    createNodeForAddAVL(VNDafterUpdate,&LBD,VB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeC);

    ListReplaceAndUpdateVertexPathCost(VertexNodeB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeD);

    ListReplaceAndUpdateVertexPathCost(VNDafterUpdate);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(550));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(551), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(552));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(553), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(554));

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(555), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VNDafterUpdate);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_trying_sorting(void)

{ ExceptionPtr ex;

    Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

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

    { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[MY_ID].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; if (

   _setjmp((

   NewFrame

   ), __builtin_frame_address (0)) 

   == 0) { if (1){

    ComputeShortestPath(&root,VA);

    }else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    }



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(605));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(606), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(607));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(608), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(609));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(610), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("E")), (const char*)((VE->name)), (

   ((void *)0)

   ), (UNITY_UINT)(611));

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((VE->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(612), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(613));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(614), UNITY_DISPLAY_STYLE_INT);





    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);

}
