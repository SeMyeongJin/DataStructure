#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack* createArrayStack(int size)
{
	ArrayStack* pReturn = NULL;

	if (size > 0)
	{
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));

		if (pReturn != NULL)
		{
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCount = size;
		}
		else
		{
			printf("CreateStack error\n");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * size);

		if (pReturn->pElement != NULL)
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode)*size);
	}

	return pReturn;
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int ret = FALSE;

	if (pStack != NULL)
	{
		if (isArrayStackFull(pStack) == FALSE)
		{
			pStack->pElement[pStack->currentElementCount] = element;

			pStack->currentElementCount++;

			ret = TRUE;
		}
	}

	return ret;
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode* pNode = NULL;

	if (pStack != NULL)
	{
		if (isArrayStackEmpty(pStack) == FALSE)
		{
			pNode = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			if (pNode != NULL)
			{
				*pNode = pStack->pElement[pStack->currentElementCount];
				pStack->currentElementCount--;
			}
		}
	}
	
	return pNode;
}

ArrayStackNode* peakAS(ArrayStack* pStack) {
	ArrayStackNode* pReturn = NULL;

	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));

			if (pReturn != NULL) {
				pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
			}
		}
	}

	return pReturn;
}