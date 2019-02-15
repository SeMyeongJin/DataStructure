#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreetraversal.h"

void preorderTraversalBinTree(BinTree *pBinTree)
{
	LinkdedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

	if (pBinTree == NULL) return;
	pRootNode = getRootNode(pBinTree);
	if (pRootNode == NULL) return;
	pStack = createLinkedStack();
	if (pStack == NULL) return;
	pushLSBinTreeNode(pStack, pRootNode);

	while (1)
	{
		if (isLinkedStackEmpty(pStack) == TRUE)
			break;
		else
		{
			pStackNode = popLS(pStack);
			if (pStackNode != NULL)
			{
				pRootNode = pStackNode->data;
				printf("%c ", pRootNode->data);

				pLeftChildNode = getLeftChildNode(pRootNode);
				pRightChildNode = getRightChildNode(pRootNode);

				if (pRightChildNode != NULL)
					pushLSBinTreeNode(pStack, pRightChildNode);

				if (pLeftChildNode != NULL)
					pushLSBinTreeNode(pStack, pLeftChildNode);
				free(pStackNode)
			}
		}
	}
	deleteLinkedStack(pStack);
}

void inorderTraversalBinTree(BinTree *pBinTree)
{
	LinkdedStack* pStack = NULL;
	StackNode* pStackNode = NULL;
	BinTreeNode *pRootNode = NULL, *pNode = NULL;

	if (pBinTree == NULL) return;
	pRootNode = getRootNode(pBinTree);
	if (pRootNode == NULL) return;
	pStack = createLinkedStack();
	if (pStack == NULL) return;
	pNode = pRootNode;

	while (1)
	{
		for (; pNode != NULL; pNode = getLeftChildNode(pNode))
			pushLSBinTreeNode(pStack, pNode);

		if (isLinkedStackEmpty(pStack) == TRUE)
			break;
		else
		{
			pStackNode = popLS(pStack);
			if (pStackNode != NULL)
			{
				pNode = pStackNode->data;
				printf("%c ", pNode->data);
				pNode = getRightChildNode(pNode);

				free(pStackNode);
			}
		}
	}
	deleteLinkedStack(pStack);
}

void levelOrderTraversalBinTree(BinTree *pBinTree)
{
	LinkedQueue* pQueue = NULL;
	QueueNode* pQueueNode = NULL;
	BinTree* pSubTree = NULL;
	BinTreeNode* pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

	if (pBinTree == NULL) return;
	
	pRootNode = getRootNode(pBinTree);
	if (pRootNode == NULL) return;

	pQueue = createLinkedQueue();
	if (pQueue == NULL) return;
	enqueueLQBinTreeNode(pQueue, pRootNode);

	while (1)
	{
		if (isLinkedQueueEmpty(pQueue) == TRUE)
			break;
		else
		{
			pQueueNode = dequeueLQ(pQueue);
			if (pQueueNode != NULL)
			{
				pRootNode = pQueueNode->data;
				if (pRootNode != NULL)
					printf("%c ", pRootNode->data);

				pLeftChildNode = getLeftChildNode(pRootNode);
				pRightChildNode = getRightChildNode(pRootNode);
				if (pLeftChildNode != NULL)
					enqueueLQBinTreeNode(pQueue, pLeftChildNode);
				if (pRightChildNode != NULL)
					enqueueLQBinTreeNode(pQueue, pRightChildNode);
			}
			free(pQueueNode);
		}
	}
	deleteLinkedQueue(pQueue);
}