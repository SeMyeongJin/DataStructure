#pragma once

typedef struct ListNodeType
{
	int data;
	ListNodeType* pLink;
}ListNode;

typedef struct LinkedListType
{
	int curElementCount;
	ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
void deleteLnkedList(LinkedList* pList);
int addElement(LinkedList* pList, int position, ListNode element);
int removeElement(LinkedList* pList, int position);
ListNode* getElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);

#define TRUE 1
#define FALSE 0