#include <cstdio>
#include <cstdlib>
#include "circularqueue.h"


void QueueInit(Queue* pQueue)
{
	pQueue->front = 0;
	pQueue->rear = 0;
}

int QueueIsEmpty(Queue* pQueue)
{
	if (pQueue->front == pQueue->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pQueue, Data element)
{
	if (NextPosIdx(pQueue->rear) == pQueue->front)
	{
		printf("Queue Memory Error\n");
		exit(-1);
	}

	pQueue->rear = NextPosIdx(pQueue->rear);
	pQueue->queArr[pQueue->rear] = element;
}

Data Dequeue(Queue* pQueue)
{
	if (QueueIsEmpty(pQueue))
	{
		printf("Queue Memory Error\n");
		exit(-1);
	}

	pQueue->front = NextPosIdx(pQueue->front);
	return pQueue->queArr[pQueue->front];
}

Data Peek(Queue* pQueue)
{
	if (QueueIsEmpty(pQueue))
	{
		printf("Queue Memory Error\n");
		exit(-1);
	}

	return pQueue->queArr[NextPosIdx(pQueue->front)];
}