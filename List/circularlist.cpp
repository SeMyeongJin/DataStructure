#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "circularlist.h"

int addElement(CircularList* pList, int position, CircularListNode element)
{
	int ret = FALSE;
	CircularListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->curElementCount)
		{
			pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
			if (pNewNode == NULL)
			{
				printf("새로운 노드 할당 오류\n");
				return ret;
			}
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0)
			{
				if (pList->curElementCount == 0)
				{
					pList->pHead = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else
				{
					pLastNode = pList->pHead;
					while (pLastNode->pLink != pList->pHead)
						pLastNode = pLastNode->pLink;

					pList->pHead = pNewNode;
					pNewNode->pLink = pLastNode->pLink;
					pLastNode->pLink = pNewNode;
				}
			}
			else
			{
				pPreNode = pList->pHead;
				for (int i = 0; i < position - 1; i++)
					pPreNode = pPreNode->pLink;
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->curElementCount++;
			ret = TRUE;
		}
		else
			printf("위치 인덱스 오류\n");
	}

	return ret;
}

int removeElement(CircularList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

	if (pList != NULL)
	{
		arrayCount = getCircularListLength(pList);
		if (position >= 0 && position < arrayCount)
		{
			if (position == 0)
			{
				pDelNode = pList->pHead;
				if (arrayCount == 1)
				{
					free(pDelNode);
					pList->pHead = NULL;
				}
				else
				{
					pLastNode = pList->pHead;
					while (pLastNode->pLink != pList->pHead)
						pLastNode = pLastNode->pLink;
					pLastNode->pLink = pDelNode->pLink;
					pList->pHead = pDelNode->pLink;
					free(pDelNode);
				}
			}
			else
			{
				pPreNode = pList->pHead;
				for (int i = 0; i < position - 1; i++)
					pPreNode = pPreNode->pLink;
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				free(pDelNode);
			}
			pList->curElementCount--;
			ret = TRUE;
		}
		else
			printf("위치 인덱스 오류\n");
	}

	return ret;
}

CircularListNode* getElement(CircularList* pList, int position)
{
	int i = 0;
	CircularListNode* pNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->curElementCount)
		{
			pNode = pList->pHead;
			for (i = 0; i < position; i++)
				pNode = pNode->pLink;
		}
	}

	return pNode;
}

CircularList* createCircularList()
{
	CircularList *pReturn = NULL;

	pReturn = (CircularList*)malloc(sizeof(CircularList));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(CircularList));
	else
	{
		printf("원형 리스트 생성 오류\n");
		return NULL;
	}
	return pReturn;
}

void displayCircularList(CircularList* pList)
{
	if (pList != 0)
	{
		printf("현재 원소 개수 : %d\n", pList->curElementCount);
		for (int i = 0; i < pList->curElementCount; i++)
			printf("[%d], %d\n", i, getElement(pList, i)->data);
	}
	else
		printf("존재하는 원소가 없습니다\n");
}

int getCircularListLength(CircularList* pList)
{
	int ret = 0;
	if (pList != NULL)
		ret = pList->curElementCount;

	return ret;
}

void deleteCircularList(CircularList* pList)
{
	if (pList != NULL)
	{
		clearCircularList(pList);
		free(pList);
	}
}

void clearCircularList(CircularList* pList)
{
	if (pList != NULL)
	{
		while (pList->curElementCount > 0)
			removeElement(pList, 0);
	}
}