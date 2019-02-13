#include <stdio.h>   
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack* pReturn = NULL;
	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));

	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(LinkedStack));
	}
	else 
	{
		printf("createLinkedStack Error\n");
		return NULL;
	}

	return pReturn;
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	int ret = FALSE;
	StackNode* pNode = NULL;

	if (pStack != NULL)
	{
		pNode = (StackNode*)malloc(sizeof(StackNode));

		if (pNode != NULL)
		{
			memset(pStack, 0, sizeof(LinkedStack));

			*pNode = element;
			
			pNode->pLink = pStack->pTopElement;

			pStack->pTopElement = pNode;

			pStack->currentElementCount++;

			ret = TRUE;
		}
	}

	return ret;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;

	if (pStack != NULL)
	{
		if (isLinkedStackEmpty(pStack) == FALSE)
		{
			pReturn = pStack->pTopElement;
			pStack->pTopElement = pReturn->pLink;

			pReturn->pLink = NULL;

			pStack->currentElementCount--;
		}
	}

	return pReturn;
}