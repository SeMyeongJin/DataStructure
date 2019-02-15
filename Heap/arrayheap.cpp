#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap* pReturn = NULL;
	
	if (maxElementCount > 0)
	{
		pReturn = (ArrayMaxHeap*)malloc(sizeof(ArrayMaxHeap));
		if (pReturn != NULL)
		{
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = (HeapNode*)malloc(sizeof(HeapNode) * (maxElementCount + 1));

			if (pReturn->pElement == NULL)
			{
				printf("createArrayMaxHeap() error\n");
				free(pReturn);
				return NULL;
			}
			memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount + 1));
		}
		else
			printf("createArrayMaxHeap() error\n");
	}
	else
		printf("최대 원소 개수는 0보다 커야 합니다.\n");

	return pReturn;
}

void insertArrayMaxHeap(ArrayMaxHeap* pHeap, HeapNode element)
{
	if (pHeap != NULL)
	{
		if (pHeap->currentElementCount == pHeap->maxElementCount)
		{
			printf("힙이 가득 찼습니다.\n");
			return;
		}

		pHeap->currentElementCount++;
		int i = pHeap->currentElementCount;

		while ((i != 1) && (element.key > pHeap->pElement[i / 2].key))
		{
			pHeap->pElement[i] = pHeap->pElement[i / 2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

HeapNode* deleteArrayMaxHeapNode(ArrayMaxHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int parent = 0, child = 0;
	
	if (pHeap != NULL && pHeap->currentElementCount > 0)
	{
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL)
		{
			printf("deleteArrayMaxHeapNode()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[1];

		int i = pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[i]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while (child <= pHeap->currentElementCount)
		{
			if ((child < pHeap->currentElementCount) && pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
				child++;

			if (pTemp->key >= pHeap->pElement[child].key)
				break;

			pHeap->pElement[parent] = pHeap->pElement[child];
			parent = child;
			child *= 2;
		}

		pHeap->pElement[parent] = *pTemp;
	}

	return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pHeap)
{
	if (pHeap != NULL)
	{
		if (pHeap->pElement != NULL)
			free(pHeap->pElement);

		free(pHeap);
	}
}