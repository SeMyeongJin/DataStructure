#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *pReturn = NULL;
	
	// 최대 원소 개수 점검
	if (maxElementCount > 0)
	{
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));

		// ArrayList 생성 점검
		if (pReturn != NULL)
		{
			pReturn->maxElementCount = maxElementCount;
			pReturn->curElementCount = 0;
			pReturn->pElement = NULL;
		}
		else
		{
			printf("배열리스트 생성 오류\n");
			return NULL;
		}
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	// Array 생성 점검
	if (pReturn->pElement == NULL)
	{
		printf("배열 생성 오류\n");
		free(pReturn);
		return NULL;
	}
	memset(pReturn->pElement, 0, sizeof(ArrayListNode)*maxElementCount);

	return pReturn;
}

int AddElement(ArrayList* pList, int position, ArrayListNode element)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (isArrayListFull(pList) != TRUE)
		{
			if (position >= 0 && position <= pList->curElementCount)
			{
				for (int i = pList->curElementCount - 1; i >= position; i--)
				{
					pList->pElement[i + 1] = pList->pElement[i];
				}
				pList->pElement[position] = element;
				pList->curElementCount++;
				ret = TRUE;
			}
			else
				printf("위치 인덱스 초과\n");
		}
		else
			printf("리스트 용량 초과\n");
	}

	return ret;
}

int removeElement(ArrayList* pList, int position)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (position >= 0 && position < pList->curElementCount)
		{
			for (int i = position; i < pList->curElementCount - 1; i++)
				pList->pElement[i] = pList->pElement[i + 1];

			pList->curElementCount--;
			ret = TRUE;
		}
		else
			printf("위치 인덱스 초과\n");
	}

	return ret;
}

ArrayListNode* getElement(ArrayList* pList, int position)
{
	ArrayListNode * pReturn = NULL;
	
	if (pList != NULL)
	{
		if (position >= 0 && position < getArrayListLength(pList))
		{
			pReturn = &(pList->pElement[position]);
		}
		else
			printf("위치 인덱스 초과\n");
	}
}

void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("최대 원소 개수 : %d\n", pList->maxElementCount);
		printf("현재 원소 개수 : %d\n", pList->curElementCount);

		for (int i = 0; i < pList->curElementCount; i++)
			printf("[%d], %d\n", i, getElement(pList, i)->data);

		int num = pList->curElementCount;
		for (; num < pList->maxElementCount; num++)
			printf("[%d], Empty\n", num);
	}
	else
		printf("ArrayList is NULL\n");
}

int isArrayListFull(ArrayList* pList)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (pList->curElementCount == pList->maxElementCount)
			ret = TRUE;
	}
	return ret;
}

int getArrayListLength(ArrayList* pList)
{
	int ret = 0;

	if (pList != NULL)
		ret = pList->curElementCount;

	return ret;
}

void deleteArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		free(pList->pElement);
		free(pList);
	}
}