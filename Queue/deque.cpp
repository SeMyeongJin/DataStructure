#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void DequeInit(Deque* pDeque)
{
	pDeque->pHead = NULL;
	pDeque->pTail = NULL;
}

int DequeIsEmpty(Deque* pDeque)
{
	if (pDeque->pHead == NULL)
		return TRUE;
	else
		return FALSE;
}

void DequeAddFirst(Deque* pDeque, Data element)
{
	DequeNode* pNewNode = (DequeNode*)malloc(sizeof(DequeNode));
	pNewNode->data = element;

	pNewNode->pRLink = pDeque->pHead;

	if (DequeIsEmpty(pDeque))
		pDeque->pTail = pNewNode;
	else
		pDeque->pHead->pLLink = pNewNode;

	pNewNode->pLLink = NULL;
	pDeque->pHead = pNewNode;
}

void DequeAddLast(Deque* pDeque, Data element)
{
	DequeNode* pNewNode = (DequeNode*)malloc(sizeof(DequeNode));
	pNewNode->data = element;
	pNewNode->pLLink = pDeque->pTail;

	if (DequeIsEmpty(pDeque))
		pDeque->pHead = pNewNode;
	else
		pDeque->pTail->pRLink = pNewNode;

	pNewNode->pRLink = NULL;
	pDeque->pTail = pNewNode;
}

Data DequeRemoveFirst(Deque* pDeque)
{
	DequeNode* pRNode = pDeque->pHead;
	Data data;
	if(DequeIsEmpty(pDeque)){
		printf("Deque Memory Error\n");
		exit(-1);
	}
	data = pDeque->pHead->data;

	pDeque->pHead = pDeque->pHead->pRLink;
	free(pRNode);

	if (pDeque->pHead == NULL)
		pDeque->pTail = NULL;
	else
		pDeque->pHead->pLLink = NULL;

	return data;
}

Data DequeRemoveLast(Deque* pDeque)
{
	DequeNode* pRNode = pDeque->pTail;
	Data data;
	if (DequeIsEmpty(pDeque)) {
		printf("Deque Memory Error\n");
		exit(-1);
	}
	data = pDeque->pTail->data;

	pDeque->pTail = pDeque->pTail->pLLink;
	free(pRNode);

	if (pDeque->pTail == NULL)
		pDeque->pHead = NULL;
	else
		pDeque->pTail->pRLink = NULL;

	return data;
}

Data DequeGetFirst(Deque* pDeque)
{
	if (DequeIsEmpty(pDeque)) {
		printf("Deque Memory Error\n");
		exit(-1);
	}

	return pDeque->pHead->data;
}

Data DequeGetLast(Deque* pDeque)
{
	if (DequeIsEmpty(pDeque)) {
		printf("Deque Memory Error\n");
		exit(-1);
	}

	return pDeque->pTail->data;
}