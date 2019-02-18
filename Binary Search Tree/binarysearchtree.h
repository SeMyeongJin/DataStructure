#pragma once

typedef struct BinSearchTreeNodeType
{
	int key;
	char value;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
}BinSearchTreeNode;

typedef struct BinSearchTreeType
{
	BinSearchTreeNode* pRootNode;
}BinSearchTree;

#define TRUE 1
#define FALSE 0

BinSearchTree* createBST();
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree* pBinSearchTree, int key);

BinSearchTreeNode* searchRecursiveBST(BinSearchTree* pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTree* pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);