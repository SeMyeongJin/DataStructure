#pragma once

typedef struct ArrayListNodeType
{
	int data;
}ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;
	int curElementCount;
	ArrayListNode *pElement;
}ArrayList;


ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addElement(ArrayList* pList, int position, ArrayListNode element);
int removeElement(ArrayList* pList, int position);
ArrayListNode* getElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#define TRUE 1
#define FALSE 0