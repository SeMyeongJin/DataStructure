#pragma once


typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
}DoublyListNode;

typedef struct DoublyListType
{
	int curElementCount;
	DoublyListNode pHead;
}DoublyList;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
int addElement(DoublyList* pList, int position, DoublyListNode element);
int removeElement(DoublyList* pList, int position);
DoublyListNode* getElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);

#define TRUE 1
#define FALSE 0