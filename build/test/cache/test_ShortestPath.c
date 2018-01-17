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



    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,119);



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

   ), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,0,VertexNodeC,188);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_INT);

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

    testAssertEqualNode(VertexNodeD,VertexNodeB,-1,VertexNodeC,232);

    testAssertEqualNode(

   ((void *)0)

   ,VertexNodeE,1,VertexNodeD,233);

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((smallest->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_INT);

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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(272))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(273), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(274))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(275), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(277));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(278), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(280));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(281), UNITY_DISPLAY_STYLE_INT);



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

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(316))));};

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VA->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(317), UNITY_DISPLAY_STYLE_INT);

    if ((((VA->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(318))));};

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VA->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(319), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("b")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(321));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(322), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VA->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("C")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(324));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(325), UNITY_DISPLAY_STYLE_INT);



    if ((((VB->list->head)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(327))));};

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((VB->list->head->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(328), UNITY_DISPLAY_STYLE_INT);

    if ((((VB->list->head->next)) != 

   ((void *)0)

   )) {} else {UnityFail( (((" Expected Non-NULL"))), (UNITY_UINT)((UNITY_UINT)((UNITY_UINT)(329))));};

    UnityAssertEqualNumber((UNITY_INT)((4)), (UNITY_INT)((VB->list->head->next->data->cost)), (

   ((void *)0)

   ), (UNITY_UINT)(330), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->data->NextVertex);

    UnityAssertEqualString((const char*)(("D")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(332));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(333), UNITY_DISPLAY_STYLE_INT);

    vt = (Vertex *)(VB->list->head->next->data->NextVertex);

    UnityAssertEqualString((const char*)(("E")), (const char*)((vt->name)), (

   ((void *)0)

   ), (UNITY_UINT)(335));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((vt->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(336), UNITY_DISPLAY_STYLE_INT);



    free(VA);

    free(VB);

    free(VC);

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

    LinkedList *shortestpath = ComputeShortestPath(&root,VA);

    }else { } CExceptionFrames[MY_ID].Exception = ((ExceptionPtr)0x5A5A5A5A); ; } else { ex = CExceptionFrames[MY_ID].Exception; (void)ex; ; } CExceptionFrames[MY_ID].pFrame = PrevFrame; ; } if (CExceptionFrames[(0)].Exception != ((ExceptionPtr)0x5A5A5A5A)){

    dumpException(ex);

    }

    UnityAssertEqualString((const char*)(("B")), (const char*)((VB->name)), (

   ((void *)0)

   ), (UNITY_UINT)(381));

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((VB->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(382), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("C")), (const char*)((VC->name)), (

   ((void *)0)

   ), (UNITY_UINT)(383));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VC->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(384), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("D")), (const char*)((VD->name)), (

   ((void *)0)

   ), (UNITY_UINT)(385));

    UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((VD->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(386), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("E")), (const char*)((VE->name)), (

   ((void *)0)

   ), (UNITY_UINT)(387));

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((VE->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(388), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualString((const char*)(("A")), (const char*)((VA->name)), (

   ((void *)0)

   ), (UNITY_UINT)(389));

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((VA->PathCost)), (

   ((void *)0)

   ), (UNITY_UINT)(390), UNITY_DISPLAY_STYLE_INT);





    free(VA);

    free(VB);

    free(VC);

    free(VD);

    free(VE);

}
