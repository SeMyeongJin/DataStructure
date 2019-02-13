#pragma once


typedef struct ArrayStackNodeType {
	char data;
} ArrayStackNode;

typedef struct ArrayStackType {
	int maxElementCount;
	int currentElementCount;
	ArrayStackNode *pElement;   //배열은 메모리에 자료형을 저장하니까 이건 배열스택을 담을 1차원 array
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#define TRUE 1
#define FALSE 0