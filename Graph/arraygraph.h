#pragma once

typedef struct ArrayGraphType
{
	int maxVertexCount;
	int curVertexCount;
	int graphType;
	int **ppAdjEdge; // ���� ������ ���� 2���� Array
	int *pVertex; // ��� ������ ���� 1���� Array
}ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);
void deleteArrayGraph(ArrayGraph* pGraph);
int isEmptyAG(ArrayGraph* pGraph);
int addVertexAG(ArrayGraph* pGraph, int vertexID);
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int removeVertexAG(ArrayGraph* pGraph, int vertexID);
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
void displayArrayGraph(ArrayGraph* pGraph);

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2