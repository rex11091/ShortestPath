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















void test_ShortestPath_VertexaddAvl_add_VertexNodeB_VertexNodeC_VertexNodeD_to_avl_expect_removed_VertexNodeB(void)

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



    int* nodoToremove = (int *)(uintptr_t)VertexNodeB->data->cost;

    *avlRemove(&VertexNodeC,nodoToremove,(Compare)CostCompareforRemove);;



    testAssertEqualNode(VertexNodeD,

   ((void *)0)

   ,-1,VertexNodeC,318);



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

   ), (UNITY_UINT)(350), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,387);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(388), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,-1,VertexNodeC,431);

    testAssertEqualNode(

   ((void *)0)

   ,VertexNodeE,1,VertexNodeD,432);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(433), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(475));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(476), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(477));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(478), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(531));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(532), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(533));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(534), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(535));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(536), UNITY_DISPLAY_STYLE_INT);

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

   ), (UNITY_UINT)(592));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(593), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(594));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(595), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(596));

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(597), UNITY_DISPLAY_STYLE_INT);

    free(VertexNodeC);

    free(VertexNodeB);

    free(VertexNodeD);

    free(VNDafterUpdate);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_graph1(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAB = {VB,2};



    addNeighbors(VA,2,&LAB,&LAC);



    Node *root = 

                ((void *)0)

                    ;

    ComputeShortestPath(&root,VA);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(630));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(631), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(632));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(633), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_main_Compute_shortest_path_graph2(void)

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

   ), (UNITY_UINT)(678));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(679), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(680));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(681), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(682));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(683), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("E")), (const char*)((VE->name)), (

   ((void *)0)

   ), (UNITY_UINT)(684));

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((VE->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(685), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(686));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(687), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);

}

void test_ShortestPath_main_Compute_shortest_path_graph3(void)

{ ExceptionPtr ex;

    Vertex *vt;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,3};

    Vertexlink LAB = {VB,2};

    Vertexlink LAD = {VD,7};

    Vertexlink LBD = {VD,1};



    addNeighbors(VA,3,&LAB,&LAC,&LAD);

    addNeighbors(VB,1,&LBD);





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

   ), (UNITY_UINT)(734));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(735), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(736));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(737), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(738));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(739), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(740));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(741), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_graph4(void)

{ ExceptionPtr ex;

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,3};

    Vertexlink LBD = {VD,1};

    Vertexlink LCD = {VD,7};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,1,&LBD);

    addNeighbors(VC,1,&LCD);





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

   ), (UNITY_UINT)(783));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(784), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(785));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(786), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(787));

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(788), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(789));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(790), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_With_adding_duplicated_cost_pattern1(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,1};

    Vertexlink LAB = {VB,1};

    Vertexlink LBD = {VD,4};

    Vertexlink LCD = {VD,1};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,1,&LBD);

    addNeighbors(VC,1,&LCD);



    Node *root = 

                ((void *)0)

                    ;

    ComputeShortestPath(&root,VA);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(826));

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(827), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(828));

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(829), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(830));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(831), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(832));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(833), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_With_adding_duplicated_cost_pattern2(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);



    Vertexlink LAC = {VC,4};

    Vertexlink LAB = {VB,3};

    Vertexlink LBD = {VD,4};

    Vertexlink LCD = {VD,1};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,1,&LBD);

    addNeighbors(VC,1,&LCD);



    Node *root = 

                ((void *)0)

                    ;

    ComputeShortestPath(&root,VA);



    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(870));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(871), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(872));

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(873), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(874));

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(875), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(876));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(877), UNITY_DISPLAY_STYLE_INT);

    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_complex_graph(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);

    Vertex *VD = createVertex("D",0x7fffffff);

    Vertex *VE = createVertex("E",0x7fffffff);

    Vertex *VF = createVertex("F",0x7fffffff);

    Vertex *VG = createVertex("G",0x7fffffff);

    Vertex *VH = createVertex("H",0x7fffffff);

    Vertex *VI = createVertex("I",0x7fffffff);



    Vertexlink LAC = {VC,8};

    Vertexlink LAB = {VB,4};

    Vertexlink LBG = {VG,8};

    Vertexlink LCB = {VB,11};

    Vertexlink LCD = {VD,1};

    Vertexlink LCE = {VE,7};

    Vertexlink LDE = {VE,6};

    Vertexlink LDF = {VF,2};

    Vertexlink LGE = {VE,2};

    Vertexlink LGH = {VH,7};

    Vertexlink LGF = {VF,4};

    Vertexlink LFI = {VI,10};

    Vertexlink LHI = {VI,9};

    Vertexlink LHF = {VF,14};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VB,1,&LBG);

    addNeighbors(VC,3,&LCB,&LCD,&LCE);

    addNeighbors(VD,2,&LDE,&LDF);

    addNeighbors(VG,3,&LGE,&LGH,&LGF);

    addNeighbors(VH,2,&LHI,&LHF);

    addNeighbors(VF,1,&LFI);







    Node *root = 

                ((void *)0)

                    ;

    ComputeShortestPath(&root,VA);



    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(937));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(938), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(939));

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(940), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(941));

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(942), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(943));

    UnityAssertEqualNumber((UNITY_INT)((9)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(944), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("E")), (const char*)((VE->name)), (

   ((void *)0)

   ), (UNITY_UINT)(945));

    UnityAssertEqualNumber((UNITY_INT)((14)), (UNITY_INT)((VE->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(946), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("F")), (const char*)((VF->name)), (

   ((void *)0)

   ), (UNITY_UINT)(947));

    UnityAssertEqualNumber((UNITY_INT)((11)), (UNITY_INT)((VF->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(948), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("G")), (const char*)((VG->name)), (

   ((void *)0)

   ), (UNITY_UINT)(949));

    UnityAssertEqualNumber((UNITY_INT)((12)), (UNITY_INT)((VG->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(950), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("H")), (const char*)((VH->name)), (

   ((void *)0)

   ), (UNITY_UINT)(951));

    UnityAssertEqualNumber((UNITY_INT)((19)), (UNITY_INT)((VH->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(952), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("I")), (const char*)((VI->name)), (

   ((void *)0)

   ), (UNITY_UINT)(953));

    UnityAssertEqualNumber((UNITY_INT)((21)), (UNITY_INT)((VI->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(954), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);

    free(VF);

    free(VG);

    free(VH);

    free(VI);

}
