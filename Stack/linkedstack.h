#pragma once


typedef struct StackNodeType {

	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStakType {

	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack(int maxElementCount);
int pushAS(LinkedStack* pStack, StackNode element);
StackNode* popAS(LinkedStack* pStack);
StackNode* peekAS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

#define TRUE 1
#define FALSE 0