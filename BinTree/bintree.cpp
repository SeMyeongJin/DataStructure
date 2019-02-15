#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree* pReturn = NULL;
	pReturn = (BinTree*)malloc(sizeof(BinTree));
	if (pReturn != NULL)
	{
		pReturn->pRootNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if (pReturn->pRootNode != NULL)
		{
			*(pReturn->pRootNode) = rootNode;
			pReturn->pRootNode->pLeftChild = NULL;
			pReturn->pRootNode->pRightChild = NULL;
		}
		else
			printf("메모리 할당 오류\n");
	}
	else
		printf("메모리 할당 오류\n");

	return pReturn;
}

BinTreeNode* insertLeftChildNode(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL)
	{
		if (pParentNode->pLeftChild == NULL)
		{
			pParentNode->pLeftChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			if (pParentNode->pLeftChild != NULL)
			{
				*(pParentNode->pLeftChild) = element;
				pParentNode->pLeftChild->pLeftChild = NULL;
				pParentNode->pLeftChild->pRightChild = NULL;
				pReturn = pParentNode->pLeftChild;
			}
			else
				printf("메모리 할당 오류\n");
		}
		else
		{
			printf("이미 자식 노드가 존재합니다\n");
		}
	}

	return pReturn;
}

BinTreeNode* insertRightChildNode(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode* pReturn = NULL;
	if (pParentNode != NULL)
	{
		if (pParentNode->pRightChild == NULL)
		{
			pParentNode->pRightChild = (BinTreeNode*)malloc(sizeof(BinTreeNode));
			if (pParentNode->pRightChild != NULL)
			{
				*(pParentNode->pRightChild) = element;
				pParentNode->pRightChild->pLeftChild = NULL;
				pParentNode->pRightChild->pRightChild = NULL;
				pReturn = pParentNode->pRightChild;
			}
			else
				printf("메모리 할당 오류\n");
		}
		else
		{
			printf("이미 자식 노드가 존재합니다\n");
		}
	}

	return pReturn;
}

BinTreeNode* getRootNode(BinTree* pBinTree)
{
	BinTreeNode* pReturn = NULL;

	if (pBinTree != NULL)
	{
		pReturn = pBinTree->pRootNode;
	}

	return pReturn;
}

BinTreeNode* getLeftChildNode(BinTreeNode* pNode)
{
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL)
	{
		pReturn = pNode->pLeftChild;
	}

	return pReturn;
}

BinTreeNode* getRightChildNode(BinTreeNode* pNode)
{
	BinTreeNode* pReturn = NULL;

	if (pNode != NULL)
	{
		pReturn = pNode->pRightChild;
	}

	return pReturn;
}

// 루트 노드를 인자로 하여 함수 deleteBinTreeNode()를 호출하며 재귀적으로 모든 노드에 대한 삭제 수행
void deleteBinTree(BinTree* pBinTree)
{
	if (pBinTree != NULL)
	{
		deleteBinTreeNode(pBinTree->pRootNode);
		free(pBinTree);
	}
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (pNode != NULL)
	{
		deleteBinTreeNode(pNode->pLeftChild);
		deleteBinTreeNode(pNode->pRightChild);
		free(pNode);
	}
}