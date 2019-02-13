#include <cstdio>
#include <cstdlib>
#include "linkedqueue.h"

void QueueInit(Queue* pQueue)
{
	pQueue->front = NULL;
	pQueue->rear = NULL;
}

int QueueIsEmpty(Queue* pQueue)
{
	if (pQueue->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pQueue, Data element)
{
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	pNewNode->pLink = NULL;
	pNewNode->data = element;

	if (QueueIsEmpty(pQueue))
	{
		pQueue->front = pNewNode;
		pQueue->rear = pNewNode;
	}
	else
	{
		pQueue->rear->pLink = pNewNode;
		pQueue->rear = pNewNode;
	}
}

Data Dequeue(Queue* pQueue)
{
	QueueNode* pDelNode = NULL;
	Data retData;

	if (QueueIsEmpty(pQueue))
	{
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	pDelNode = pQueue->front;
	retData = pDelNode->data;
	pQueue->front = pQueue->front->pLink;

	free(pDelNode);
	return retData;
}

Data Peek(Queue* pQueue)
{
	if (QueueIsEmpty(pQueue))
	{
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	return pQueue->front->data;
}