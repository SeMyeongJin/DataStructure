#include <cstdio>
#include <stdlib.h>
#include <cstring>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
	ArrayList *pReturn = NULL;
	
	// �ִ� ���� ���� ����
	if (maxElementCount > 0)
	{
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));

		// ArrayList ���� ����
		if (pReturn != NULL)
		{
			pReturn->maxElementCount = maxElementCount;
			pReturn->curElementCount = 0;
			pReturn->pElement = NULL;
		}
		else
		{
			printf("�迭����Ʈ ���� ����\n");
			return NULL;
		}
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElementCount);
	// Array ���� ����
	if (pReturn->pElement == NULL)
	{
		printf("�迭 ���� ����\n");
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
				printf("��ġ �ε��� �ʰ�\n");
		}
		else
			printf("����Ʈ �뷮 �ʰ�\n");
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
			printf("��ġ �ε��� �ʰ�\n");
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
			printf("��ġ �ε��� �ʰ�\n");
	}
}

void displayArrayList(ArrayList* pList)
{
	if (pList != NULL)
	{
		printf("�ִ� ���� ���� : %d\n", pList->maxElementCount);
		printf("���� ���� ���� : %d\n", pList->curElementCount);

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