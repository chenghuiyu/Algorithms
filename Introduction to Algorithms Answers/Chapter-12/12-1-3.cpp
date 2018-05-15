struct BinaryTreeNode
{
	int m_pValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


// 12.1-3:ʵ����������ķǵݹ��㷨������ջ������ʵ��
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

void inorderTree(BinaryTreeNode* treeRoot) {
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

