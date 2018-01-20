#include "build/temp/_test_ShortestPath.c"
#include "CException.h"
#include "Exception.h"
#include "nodeVerifier.h"
#include "rotate.h"
#include "remove.h"
#include "avlAdd.h"
#include "ShortestPath.h"
#include "node.h"
#include "LinkedList.h"
#include "unity.h"




void setUp(void)

{



}



void tearDown(void)

{

}





void test_ShortestPath_create_Vertex(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",9);

    Vertex *VC = createVertex("C",10);



    testAssertEqualVertex("A" ,0,VA,29);

    testAssertEqualVertex("B" ,9,VB,30);

    testAssertEqualVertex("C" ,10,VC,31);





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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(75))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VertexNodeB->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((&LAB)), (UNITY_INT64)((VertexNodeB->data)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX64);

    if ((((VertexNodeC)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(78))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VertexNodeC->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT64)((&LAC)), (UNITY_INT64)((VertexNodeC->data)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX64);



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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(110))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(112))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(115));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(118));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_INT);



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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(154))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(155), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(156))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(157), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(159));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(162));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(165))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(167))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(170));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(173));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(174), UNITY_DISPLAY_STYLE_INT);



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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(211))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(213))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(215))));};

    UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((VA->list->head->next->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(216), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(218));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(219), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(221));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(222), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(224));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(225), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(227))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(229))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(230), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(232));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(233), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(235));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(236), UNITY_DISPLAY_STYLE_INT);



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



    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,275);



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

   ,-1,VertexNodeC,317);



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

   ), (UNITY_UINT)(349), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,386);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(387), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,-1,VertexNodeC,430);

    testAssertEqualNode(

   ((void *)0)

   ,VertexNodeE,1,VertexNodeD,431);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(432), UNITY_DISPLAY_STYLE_INT);

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



    testAssertEqualVertex("A" ,0,VA,474);

    testAssertEqualVertex("B" ,2,VB,475);

    testAssertEqualVertex("C" ,3,VC,476);

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

    ListReplaceAndUpdateVertexPathCost(VertexNodeC);

    ListReplaceAndUpdateVertexPathCost(VertexNodeB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeD);





    createNodeForAddAVL(VNDafterUpdate,&LBD,VB);

    ListReplaceAndUpdateVertexPathCost(VNDafterUpdate);



    testAssertEqualVertex("A" ,0,VA,532);

    testAssertEqualVertex("B" ,2,VB,533);

    testAssertEqualVertex("C" ,3,VC,534);

    testAssertEqualVertex("D" ,3,VD,535);

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

    ListReplaceAndUpdateVertexPathCost(VertexNodeC);

    ListReplaceAndUpdateVertexPathCost(VertexNodeB);

    ListReplaceAndUpdateVertexPathCost(VertexNodeD);



    createNodeForAddAVL(VNDafterUpdate,&LBD,VB);

    ListReplaceAndUpdateVertexPathCost(VNDafterUpdate);



    testAssertEqualVertex("A" ,0,VA,593);

    testAssertEqualVertex("B" ,2,VB,594);

    testAssertEqualVertex("C" ,3,VC,595);

    testAssertEqualVertex("D" ,5,VD,596);

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



    testAssertEqualVertex("A" ,0,VA,630);

    testAssertEqualVertex("B" ,2,VB,631);

    testAssertEqualVertex("C" ,3,VC,632);

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



    testAssertEqualVertex("A" ,0,VA,677);

    testAssertEqualVertex("B" ,2,VB,678);

    testAssertEqualVertex("C" ,3,VC,679);

    testAssertEqualVertex("D" ,3,VD,680);

    testAssertEqualVertex("E" ,6,VE,681);

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



    testAssertEqualVertex("A" ,0,VA,728);

    testAssertEqualVertex("B" ,2,VB,729);

    testAssertEqualVertex("C" ,3,VC,730);

    testAssertEqualVertex("D" ,3,VD,731);

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



    testAssertEqualVertex("A" ,0,VA,773);

    testAssertEqualVertex("B" ,3,VB,774);

    testAssertEqualVertex("C" ,2,VC,775);

    testAssertEqualVertex("D" ,4,VD,776);

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



    testAssertEqualVertex("A" ,0,VA,812);

    testAssertEqualVertex("B" ,1,VB,813);

    testAssertEqualVertex("C" ,1,VC,814);

    testAssertEqualVertex("D" ,2,VD,815);

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



    testAssertEqualVertex("A" ,0,VA,852);

    testAssertEqualVertex("B" ,3,VB,853);

    testAssertEqualVertex("C" ,4,VC,854);

    testAssertEqualVertex("D" ,5,VD,855);



    free(VA);

    free(VB);

    free(VC);

    free(VD);

}

void test_ShortestPath_main_Compute_shortest_path_With_adding_duplicated_cost_pattern3(void)

{

    Vertex *VA = createVertex("A",0);

    Vertex *VB = createVertex("B",0x7fffffff);

    Vertex *VC = createVertex("C",0x7fffffff);



    Vertexlink LAC = {VC,2};

    Vertexlink LAB = {VB,1};

    Vertexlink LCB = {VB,4};



    addNeighbors(VA,2,&LAB,&LAC);

    addNeighbors(VC,1,&LCB);



    Node *root = 

                ((void *)0)

                    ;

    ComputeShortestPath(&root,VA);



    testAssertEqualVertex("A" ,0,VA,891);

    testAssertEqualVertex("B" ,1,VB,892);

    testAssertEqualVertex("C" ,2,VC,893);

    free(VA);

    free(VB);

    free(VC);

}

void test_ShortestPath_main_Compute_shortest_path_complex_graph(void)

{

    ExceptionPtr ex;

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



    testAssertEqualVertex("A" ,0,VA,953);

    testAssertEqualVertex("B" ,4,VB,954);

    testAssertEqualVertex("C" ,8,VC,955);

    testAssertEqualVertex("D" ,9,VD,956);

    testAssertEqualVertex("E" ,14,VE,957);

    testAssertEqualVertex("F" ,11,VF,958);

    testAssertEqualVertex("G" ,12,VG,959);

    testAssertEqualVertex("H" ,19,VH,960);

    testAssertEqualVertex("I" ,21,VI,961);



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
