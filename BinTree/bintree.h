#pragma once

typedef struct BinTreeNodeType
{
	char data;

	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
}BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
}BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNode(BinTree* pBinTree);
BinTreeNode* insertLeftChildNode(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNode(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNode(BinTreeNode* pNode);
BinTreeNode* getRightChildNode(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);

#define TRUE 1
#define FALSE 0