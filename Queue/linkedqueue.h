#pragma once


typedef int Data;

typedef struct QueueNodeType
{
	Data data;
	struct QueueNodeType* pLink;
}QueueNode;

typedef struct LinkedQueueType
{
	QueueNode* front;
	QueueNode* rear;
}LinkedQueue;

typedef LinkedQueue Queue;

void QueueInit(Queue* pQueue);
int QueueIsEmpty(Queue* pQueue);

void Enqueue(Queue* pQueue, Data element);
Data Dequeue(Queue* pQueue);
Data Peek(Queue* pQueue);

#define TRUE 1
#define FALSE 0