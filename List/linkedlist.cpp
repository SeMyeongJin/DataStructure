#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "linkedlist.h"


LinkedList* createLinkedList()
{
	LinkedList* pReturn = NULL;

	pReturn = (LinkedList*)malloc(sizeof(LinkedList));

	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(LinkedList));
	}
	else
	{
		printf("연결리스트 생성 오류\n");
		return NULL;
	}
	return pReturn;
}

int addElement(LinkedList* pList, int position, ListNode element)
{
	int ret = FALSE;
	ListNode* pPreNode = NULL;
	ListNode* pNewNode = NULL;
	
	if (pList != NULL)
	{
		if (position >= 0 && position <= pList->curElementCount)
		{
			pNewNode = (ListNode*)malloc(sizeof(ListNode));

			if (pNewNode != NULL)
			{
				*pNewNode = element;
				pNewNode->pLink = NULL;

				pPreNode = &(pList->headerNode);

				for (int i = 0; i < position; i++)
					pPreNode = pPreNode->pLink;

				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;

				pList->curElementCount++;
				ret = TRUE;
			}
			else
				printf("노드 생성 불가\n");
		}
		else
			printf("위치 인덱스 오류\n");
	}

	return ret;
}

int removeElement(LinkedList* pList, int position)
{
	int ret = FALSE;
	int arrayCount = 0;
	ListNode* pNode = NULL;
	ListNode* pDelNode = NULL;
	
	if (pList != NULL)
	{
		arrayCount = getLinkedListLength(pList);
		if (position >= 0 && position < arrayCount)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i < position; i++)
				pNode = pNode->pLink;
		}

		pDelNode = pNode->pLink;
		pNode->pLink = pDelNode->pLink;
		free(pDelNode);
		pList->curElementCount--;
		ret = TRUE;
	}
	else
		printf("위치 인덱스 오류\n");

	return ret;
}

ListNode* getElement(LinkedList* pList, int position)
{
	ListNode* pReturn = NULL;
	ListNode* pNode = NULL;

	if (pList != NULL)
	{
		if (position >= 0 && position < pList->curElementCount)
		{
			pNode = &(pList->headerNode);
			for (int i = 0; i <= position; i++)
				pNode = pNode->pLink;

			pReturn = pNode;
		}
	}

	return pReturn;
}

void deleteLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		clearLinkedList(pList);
		free(pList);
	}
}

void clearLinkedList(LinkedList* pList)
{
	if (pList != NULL)
	{
		while (pList->curElementCount > 0)
		{
			removeElement(pList, 0);
		}
	}
}

int getLinkedListLength(LinkedList* pList)
{
	int ret = 0;

	if (pList != NULL)
		ret = pList->curElementCount;

	return ret;
}

int isEmpty(LinkedList* pList)
{
	int ret = FALSE;

	if (pList != NULL)
	{
		if (pList->curElementCount == 0)
			ret = TRUE;
	}

	return ret;
}