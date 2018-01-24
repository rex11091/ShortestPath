# ShortestPath


#Purpose Using shortest path(Dijkstra algorithm)
Shortest Path issue plays an important role in applications of road network such as handling city emergency way and guiding driver system. The condition of traffic among a city changes periodically and there are usually large amounts of requests occur, it needs to be solve quickly. By using the Dijkstra's Algorithm, the above problems can be solved through shortest paths. The shortest path and the best path is computed based on the problem of traffic condition shortest path. This plays an important role in navigation systems as it can help to make sensible decision and time saving decisions. The main purpose is to get the implementation at low cost. Thus, it brings a new framework called towards shortest path which enables drivers to quickly and effectively collect the shortest path as well as alternative path and traffic information. An impressive the result is that the driver can get their shortest path result and also gives alternative paths for the same route with the traffic count.

#Coding Methodology

The Vertex created by the Function below:

Vertex *createVertex(char *name, int value)

The struct of vertexLink is store the vertex and the destination of it:

struct Vertexlink{
  Vertex *NextVertex;
  int cost;
};

The neigbouring between vertex and it’s neighbour can be link by function below:

-LinkedList will be use in this function for storing it's neighbour
void addNeighbors(Vertex *vertex,int numbofneighbors,...)

To create a node which need to insert to AVL Tree for sorting purpose:

void createNodeForAddAVL(Node *node,Vertexlink *vertexlink,Vertex *Vertex)

To insert the node to AVL Tree :

define VertexaddAvl(root, nodeToAdd)  avlAdd(root,nodeToAdd,(Compare)CostCompare);

Finding the smallest node from AVL tree :

Node *findSmallestNode(Node **rootPtr)

To remove the node from AVL Tree after the node has being visit:

define VertexRemoveNodeAvl(rootptr,nodeToAdd)      *avlRemove(rootptr,nodeToAdd,(Compare)CostCompareforRemove);

For updating the Pathcost of vertex :

void ListReplaceAndUpdateVertexPathCost(Node *VertexNode);

The main function which using the function above  will be used to pass in the cost to vertex's PathCost:

void ComputeShortestPath(Node **root,Vertex *vertex);

#References
1.http://ieeexplore.ieee.org/document/8073641/
2.https://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/