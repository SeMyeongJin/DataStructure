#pragma once

#define QUE_LEN 100
typedef int Data;

typedef struct CircularQueueType
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
}CircularQueue;

typedef CircularQueue Queue;

void QueueInit(Queue* pQueue);
int QueueIsEmpty(Queue* pQueue);

void Enqueue(Queue* pQueue, Data element);
Data Dequeue(Queue* pQueue);
Data Peek(Queue* pQueue);

#define TRUE 1
#define FALSE 0