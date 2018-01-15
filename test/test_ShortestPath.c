#include "unity.h"
#include "stdlib.h"
#include "LinkedList.h"
#include "ShortestPath.h"
#include "avlAdd.h"
#include "remove.h"
#include "rotate.h"
#include "nodeVerifier.h"
#include "Exception.h"
#include "CException.h"

void setUp(void)
{
//  giveInitdata();
}

void tearDown(void)
{
}


void test_ShortestPath_create_node(void)
{
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",9);
    Vertex *VC = createVertex("C",10);

    TEST_ASSERT_EQUAL("A",VA->name);
    TEST_ASSERT_EQUAL(0,VA->PathCost);
    TEST_ASSERT_EQUAL("b",VB->name);
    TEST_ASSERT_EQUAL(9,VB->PathCost);
    TEST_ASSERT_EQUAL("C",VC->name);
    TEST_ASSERT_EQUAL(10,VC->PathCost);

    free(VA);
    free(VB);
    free(VC);

}

void test_ShortestPath_Vertexlink(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",9);
    Vertex *VC = createVertex("C",10);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};

    TEST_ASSERT_EQUAL(VC,LAC.NextVertex);
    TEST_ASSERT_EQUAL(2,LAC.cost);
    TEST_ASSERT_EQUAL(VB,LAB.NextVertex);
    TEST_ASSERT_EQUAL(3,LAB.cost);

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
    createNodeForAddAVL(VertexNodeB,&LAB);
    createNodeForAddAVL(VertexNodeC,&LAC);

    TEST_ASSERT_NOT_NULL(VertexNodeB);
    TEST_ASSERT_EQUAL(3,VertexNodeB->data->cost);
    TEST_ASSERT_EQUAL_PTR(&LAB,VertexNodeB->data);
    TEST_ASSERT_NOT_NULL(VertexNodeC);
    TEST_ASSERT_EQUAL(2,VertexNodeC->data->cost);
    TEST_ASSERT_EQUAL_PTR(&LAC,VertexNodeC->data);
    
    free(VertexNodeC);
    free(VertexNodeB);
    free(VA);
    free(VB);
    free(VC);
}


void test_ShortestPath_VertexaddAvl_add_VertexNodeB_VertexNodeC_VertexNodeD_to_avl_expect_balance(void)
{  

    Vertex *VB = createVertex("b",0);
    Vertex *VC = createVertex("C",0);
    Vertex *VD = createVertex("D",0);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    Vertexlink LAD = {VD,1};

    Node *VertexNodeC = (Node *)malloc(sizeof(Node));
    Node *VertexNodeB = (Node *)malloc(sizeof(Node));
    Node *VertexNodeD = (Node *)malloc(sizeof(Node));
    createNodeForAddAVL(VertexNodeB,&LAB);
    createNodeForAddAVL(VertexNodeC,&LAC);
    createNodeForAddAVL(VertexNodeD,&LAD);


    VertexaddAvl(&VertexNodeC,VertexNodeB);
    VertexaddAvl(&VertexNodeC,VertexNodeD);

    TEST_ASSERT_EQUAL_NODE(VertexNodeD,VertexNodeB,0,VertexNodeC);

    free(VertexNodeC);
    free(VertexNodeB);
    free(VertexNodeD);
    free(VB);
    free(VC);
}

/*
                    VertexNodeC(0)
                     /       \                         ------search smallest----->          VertexNodeD
             vertexNodeD(0)  VertexNodeB(0)     


*/
void test_ShortestPath_VertexaddAvl_Finding_smallestNode_expect_return_VertexNodeD(void)
{  

    Vertex *VB = createVertex("b",0);
    Vertex *VC = createVertex("C",0);
    Vertex *VD = createVertex("D",0);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    Vertexlink LAD = {VD,1};

    Node *VertexNodeC = (Node *)malloc(sizeof(Node));
    Node *VertexNodeB = (Node *)malloc(sizeof(Node));
    Node *VertexNodeD = (Node *)malloc(sizeof(Node));
    createNodeForAddAVL(VertexNodeB,&LAB);
    createNodeForAddAVL(VertexNodeC,&LAC);
    createNodeForAddAVL(VertexNodeD,&LAD);

    Node *root = VertexNodeC;

    VertexaddAvl(&root,VertexNodeB);
    VertexaddAvl(&root,VertexNodeD); 
    Node *smallest = findSmallestNode(&root);
    TEST_ASSERT_EQUAL_NODE(VertexNodeD,VertexNodeB,0,VertexNodeC);
    TEST_ASSERT_EQUAL(1,smallest->data->cost);
    free(VertexNodeC);
    free(VertexNodeB);
    free(VertexNodeD);
    free(VB);
    free(VC);
}







/*
                      C
                      |
                      |2
                      |
                   (0)A------B
                          3

*/
void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_vertex(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",0);
    Vertex *VC = createVertex("C",0);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};

    addNeighbors(VA,2,&LAB,&LAC);

    TEST_ASSERT_NOT_NULL(VA->list->head);
    TEST_ASSERT_EQUAL(3,VA->list->head->data->cost);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    TEST_ASSERT_EQUAL(2,VA->list->head->next->data->cost);
    vt = (Vertex *)(VA->list->head->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("b",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("C",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);

    free(VA);
    free(VB);
    free(VC);
}

/*
                      C
                      |
                      |2
                      |          1
                   (0)A------B------D
                          3  |
                             |4
                             |
                             E
*/

void test_ShortestPath_addneighbour_VA_expect_neigboring_with_another_vertex1(void)
{   Vertex *vt;
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

    TEST_ASSERT_NOT_NULL(VA->list->head);
    TEST_ASSERT_EQUAL(3,VA->list->head->data->cost);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    TEST_ASSERT_EQUAL(2,VA->list->head->next->data->cost);
    vt = (Vertex *)(VA->list->head->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("b",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("C",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);

    TEST_ASSERT_NOT_NULL(VB->list->head);
    TEST_ASSERT_EQUAL(1,VB->list->head->data->cost);
    TEST_ASSERT_NOT_NULL(VB->list->head->next);
    TEST_ASSERT_EQUAL(4,VB->list->head->next->data->cost);
    vt = (Vertex *)(VB->list->head->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("D",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);
    vt = (Vertex *)(VB->list->head->next->data->NextVertex);
    TEST_ASSERT_EQUAL_STRING("E",vt->name);
    TEST_ASSERT_EQUAL(0,vt->PathCost);

    free(VA);
    free(VB);
    free(VC);
}

void test_ShortestPath_trying_sorting(void)
{   CEXCEPTION_T ex;
    Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("b",INT_MAX);
    Vertex *VC = createVertex("C",INT_MAX);
    Vertex *VE = createVertex("E",INT_MAX);
    Vertex *VD = createVertex("D",INT_MAX);

    Vertexlink LAC = {VC,3};
    Vertexlink LAB = {VB,2};
    Vertexlink LBD = {VD,1};
    Vertexlink LBE = {VE,4};

    addNeighbors(VA,2,&LAB,&LAC);
    addNeighbors(VB,2,&LBD,&LBE);


    Node *root = NULL;
    Try{
    LinkedList *shortestpath = ComputeShortestPath(&root,VA);
    }Catch(ex){
    dumpException(ex);
    }
    //freeException1(ex);

    //TEST_ASSERT_NOT_NULL(VA->list->head);
    //TEST_ASSERT_EQUAL(3,root->data->cost);
    //TEST_ASSERT_EQUAL_PTR(NULL,root);



    free(VA);
    free(VB);
    free(VC);
}





/*
                      C(2)
                      |
                      |2
                      |       (3)
                   (0)A-------B-------D (4)
                          3   |   1
                              | 4
                              |
                              E(7)


void test_ShortestPath_compute_shortestPath(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("B",INT_MAX);
    Vertex *VC = createVertex("C",INT_MAX);
    Vertex *VD = createVertex("D",INT_MAX);
    Vertex *VE = createVertex("E",INT_MAX);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    Vertexlink LBD = {VD,1};
    Vertexlink LBE = {VE,4};

    addNeighbors(VA,2,LAB,LAC);
    addNeighbors(VB,2,LBD,LBE);

    LinkedList *ShortestPath = ComputeShortestPath(VA);

    TEST_ASSERT_NOT_NULL(VA->list->head);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    vt = (Vertex *)(VA->list->head->data);
    TEST_ASSERT_EQUAL_STRING("B",vt->name);
    TEST_ASSERT_EQUAL(3,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->data);
    TEST_ASSERT_EQUAL_STRING("C",vt->name);
    TEST_ASSERT_EQUAL(2,vt->PathCost);


    TEST_ASSERT_NOT_NULL(VB->list->head);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    vt = (Vertex *)(VB->list->head->data);
    TEST_ASSERT_EQUAL_STRING("D",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);
    vt = (Vertex *)(VB->list->head->next->data);
    TEST_ASSERT_EQUAL_STRING("E",vt->name);
    TEST_ASSERT_EQUAL(7,vt->PathCost);


    free(VA);
    free(VB);
    free(VC);
    free(VD);
    free(VE);
}
*/
/*
                      C(2)
                      |
                      |2
                      |       (3)
                   (0)A-------B-------D (4)
                      |   3   |   1
                      |       | 4
                      |       |
                  4   +-------E (4)    // get smaller cost




void test_ShortestPath_compute_shortestPath_va_and_vb_have_same_next_vertex_expect_smaller_cost_will_be_stored(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("B",INT_MAX);
    Vertex *VC = createVertex("C",INT_MAX);
    Vertex *VD = createVertex("D",INT_MAX);
    Vertex *VE = createVertex("E",INT_MAX);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    Vertexlink LBD = {VD,1};
    Vertexlink LBE = {VE,4};
    Vertexlink LAE = {VE,4};

    addNeighbors(VA,3,LAB,LAC,LAE);
    addNeighbors(VB,2,LBD,LBE);

    LinkedList *ShortestPath = ComputeShortestPath(VA);

    TEST_ASSERT_NOT_NULL(VA->list->head);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    TEST_ASSERT_NOT_NULL(VA->list->head->next->next);
    vt = (Vertex *)(VA->list->head->data);
    TEST_ASSERT_EQUAL_STRING("B",vt->name);
    TEST_ASSERT_EQUAL(3,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->data);
    TEST_ASSERT_EQUAL_STRING("C",vt->name);
    TEST_ASSERT_EQUAL(2,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->next->data);
    TEST_ASSERT_EQUAL_STRING("E",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);


    TEST_ASSERT_NOT_NULL(VB->list->head);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    vt = (Vertex *)(VB->list->head->data);
    TEST_ASSERT_EQUAL_STRING("D",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);
    vt = (Vertex *)(VB->list->head->next->data);
    TEST_ASSERT_EQUAL_STRING("E",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);


    free(VA);
    free(VB);
    free(VC);
    free(VD);
    free(VE);
}

*/
/*
                      C(2)------------+7
                      |               |
                      |2              |
                      |       (3)     |
                   (0)A-------B-------D (4)
                          3      1




void test_ShortestPath_compute_shortestPath_have_same_next_vertex_expect_smaller_cost_will_be_stored(void)
{   Vertex *vt;
    Vertex *VA = createVertex("A",0);
    Vertex *VB = createVertex("B",INT_MAX);
    Vertex *VC = createVertex("C",INT_MAX);
    Vertex *VD = createVertex("D",INT_MAX);

    Vertexlink LAC = {VC,2};
    Vertexlink LAB = {VB,3};
    Vertexlink LBD = {VD,1};
    Vertexlink LCD = {VD,7};

    addNeighbors(VA,2,LAB,LAC);
    addNeighbors(VB,1,LBD);
    addNeighbors(VC,1,LCD);

    LinkedList *ShortestPath = ComputeShortestPath(VA);

    TEST_ASSERT_NOT_NULL(VA->list->head);
    TEST_ASSERT_NOT_NULL(VA->list->head->next);
    vt = (Vertex *)(VA->list->head->data);
    TEST_ASSERT_EQUAL_STRING("B",vt->name);
    TEST_ASSERT_EQUAL(3,vt->PathCost);
    vt = (Vertex *)(VA->list->head->next->data);
    TEST_ASSERT_EQUAL_STRING("C",vt->name);
    TEST_ASSERT_EQUAL(2,vt->PathCost);

    TEST_ASSERT_NOT_NULL(VB->list->head);
    vt = (Vertex *)(VB->list->head->data);
    TEST_ASSERT_EQUAL_STRING("D",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);

    TEST_ASSERT_NOT_NULL(VC->list->head);
    vt = (Vertex *)(VC->list->head->data);
    TEST_ASSERT_EQUAL_STRING("D",vt->name);
    TEST_ASSERT_EQUAL(4,vt->PathCost);


    free(VA);
    free(VB);
    free(VC);
    free(VD);
}
*/
