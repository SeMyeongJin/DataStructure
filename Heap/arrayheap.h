#pragma once

typedef struct HeapElementType
{
	int key;
	char data;
}HeapNode;

typedef struct ArrayHeapType
{
	int maxElementCount;
	int currentElementCount;
	HeapNode *pElement;
}ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);
void insertArrayMaxHeap(ArrayMaxHeap* pArrayHeap, HeapNode element);
HeapNode* deleteArrayMaxHeapNode(ArrayMaxHeap* pHeap);

#define TRUE 1
#define FALSE 0