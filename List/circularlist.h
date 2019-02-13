#pragma once


typedef struct CircularListNodeType
{
	int data;
	struct CircularListNodeType* pLink;
}CircularListNode;

typedef struct CircularListType
{
	int curElementCount;
	CircularListNode* pHead;
}CircularList;

CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
int addElement(CircularList* pList, int position, CircularListNode element);
int removeElement(CircularList* pList, int position);
CircularListNode* getElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);

#define TRUE 1
#define FALSE 0