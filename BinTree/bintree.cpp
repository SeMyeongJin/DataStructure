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
			printf("�޸� �Ҵ� ����\n");
	}
	else
		printf("�޸� �Ҵ� ����\n");

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
				printf("�޸� �Ҵ� ����\n");
		}
		else
		{
			printf("�̹� �ڽ� ��尡 �����մϴ�\n");
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
				printf("�޸� �Ҵ� ����\n");
		}
		else
		{
			printf("�̹� �ڽ� ��尡 �����մϴ�\n");
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

// ��Ʈ ��带 ���ڷ� �Ͽ� �Լ� deleteBinTreeNode()�� ȣ���ϸ� ��������� ��� ��忡 ���� ���� ����
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