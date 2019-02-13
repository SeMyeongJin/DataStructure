#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "doublylist.h"


DoublyListNode* getElement(DoublyList* pList, int position)
{
	int i = 0;
	DoublyListNode* pReturn = NULL;
	DoublyListNode* pNode = NULL;
	if (pList != NULL)
	{
		if (position >= 0 && position < pList->curElementCount)
		{
			pNode = pList->pHead.pRLink;
			for (i = 0; i < position; i++)
				pNode = pNode->pRLink;
			pReturn = pNode;
		}
		else
			printf("��ġ �ε��� ����\n");
	}

	return pNode;
}

DoublyList* createDoublyList()
{
	DoublyList *pReturn = NULL;

	pReturn = (DoublyList*)malloc(sizeof(DoublyList));
	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(DoublyList));
		pReturn->pHead.pLLink = &(pReturn->pHead);
		pReturn->pHead.pRLink = &(pReturn->pHead);
	}
	else
	{
		printf("���� ����Ʈ ���� ����\n");
		return NULL;
	}
	return pReturn;
}

void displayDoublyList(DoublyList* pList)
{
	if (pList != 0)
	{
		printf("���� ���� ���� : %d\n", pList->curElementCount);
		for (int i = 0; i < pList->curElementCount; i++)
			printf("[%d], %d\n", i, getElement(pList, i)->data);
	}
	else
		printf("�����ϴ� ���Ұ� �����ϴ�\n");
}

int getDoublyListLength(DoublyList* pList)
{
	int ret = 0;
	if (pList != NULL)
		ret = pList->curElementCount;

	return ret;
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList != NULL)
	{
		clearDoublyList(pList);
		free(pList);
	}
}

void clearDoublyList(DoublyList* pList)
{
	if (pList != NULL)
	{
		while (pList->curElementCount > 0)
			removeElement(pList, 0);
	}
}

int addElement(DoublyList* pList, int position, DoublyListNode element)
{
	int ret = FALSE;

}