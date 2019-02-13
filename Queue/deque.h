#pragma once

typedef int Data;

typedef struct DequeNodeType
{
	Data data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
}DequeNode;

typedef struct DequeType
{
	DequeNode* pHead;
	DequeNode* pTail;
}Deque;

void DequeInit(Deque* pDeque);
int DequeIsEmpty(Deque* pDeque);

void DequeAddFirst(Deque* pDeque, Data element);
void DequeAddLast(Deque* pDeque, Data data);

Data DequeRemoveFirst(Deque* pDeque);
Data DequeRemoveLast(Deque* pDeque);

Data DequeGetFirst(Deque* pDeque);
Data DequeGetLast(Deque* pDeque);

#define TRUE 1
#define FALSE 0