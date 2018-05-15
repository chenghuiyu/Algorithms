
struct BinaryTreeNode
{
	int m_pValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;


//中序遍历的递归实现方式

void InOrderBinaryTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;
	InOrderBinaryTree(treeRoot->m_pLeft);
	printf("%d\n", treeRoot->m_pValue);
	InOrderBinaryTree(treeRoot->m_pRight);
}

//前序遍历的递归实现方式

void PreOrderBianryTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;
	printf("%d\n", treeRoot->m_pValue);
	PreOrderBianryTree(treeRoot->m_pLeft);
	PreOrderBianryTree(treeRoot->m_pRight);
}

//后序遍历的递归实现方式
void PostOrderBianryTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;
	PostOrderBianryTree(treeRoot->m_pLeft);
	PostOrderBianryTree(treeRoot->m_pRight);
	printf("%d\n", treeRoot->m_pValue);
}
