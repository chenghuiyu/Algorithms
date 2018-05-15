struct BinaryTreeNode
{
	int m_pValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


// 12.1-3:实现中序遍历的非递归算法，采用栈来进行实现，为了思维的扩展，
//下面实现了中序遍历、前序遍历和后续遍历的非递归实现方式


#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

//中序遍历的非递归调用
void InorderTree(BinaryTreeNode* treeRoot) {
	stack<BinaryTreeNode*> treeStack;
	BinaryTreeNode* treeNode = treeRoot;

	while (treeNode != nullptr || !treeStack.empty())
	{
		while (treeNode != nullptr)
		{
			treeStack.push(treeNode);
			treeNode = treeNode->m_pLeft;
		}

		treeNode = treeStack.top();
		treeStack.pop();
		printf("%d\n", treeNode->m_pValue);
		treeNode = treeNode->m_pRight;
	}
}


//前序遍历的非递归调用

void PreorderTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;

	BinaryTreeNode* treeNode = treeRoot;
	stack<BinaryTreeNode*> treeStack;

	while (treeNode != nullptr || !treeStack.empty())
	{
		while (treeNode != nullptr)
		{
			printf("%d\n", treeNode->m_pValue);
			treeStack.push(treeNode);
			treeNode = treeNode->m_pLeft;
		}
		if (!treeStack.empty()) {
			treeNode = treeStack.top();
			treeStack.pop();
			treeNode = treeNode->m_pRight;
		}
	}
}

//后续遍历的非递归调用
//后序遍历递归定义：先左子树，后右子树，再根节点。
//后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。若是位于左子树，
//则需跳过根节点，先进入右子树，再回头访问根节点；若是位于右子树，则直接访问根节点。
void PostorderTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;

	stack<BinaryTreeNode*> treeStack;
	BinaryTreeNode* treeCurrent;
	BinaryTreeNode* treeLastVist = nullptr;
	treeCurrent = treeRoot;

	//先把treeCurrent移动到左子树最下边
	while (treeCurrent != nullptr)
	{
		treeStack.push(treeCurrent);
		treeCurrent = treeCurrent->m_pLeft;
	}
	while (!treeStack.empty())
	{
		////走到这里，treeCurrent都是空，并已经遍历到左子树底端(看成扩充二叉树，则空，亦是某棵树的左孩子) 
		treeCurrent = treeStack.top();
		treeStack.pop();
		////一个根节点被访问的前提是：无右子树或右子树已被访问过  
		if (treeCurrent->m_pRight == nullptr || treeLastVist == treeCurrent->m_pRight) {
			printf("%d\n", treeCurrent->m_pValue);
			treeLastVist = treeCurrent;
		}
		else if (treeCurrent->m_pLeft == treeLastVist)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		{
			treeStack.push(treeCurrent);
			treeCurrent = treeCurrent->m_pRight;
			while (treeCurrent != nullptr)
			{
				treeStack.push(treeCurrent);
				treeCurrent = treeCurrent->m_pLeft;
			}
		}
	}
}

