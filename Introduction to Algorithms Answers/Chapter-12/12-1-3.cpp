struct BinaryTreeNode
{
	int m_pValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


// 12.1-3:ʵ����������ķǵݹ��㷨������ջ������ʵ�֣�Ϊ��˼ά����չ��
//����ʵ�������������ǰ������ͺ��������ķǵݹ�ʵ�ַ�ʽ


#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

//��������ķǵݹ����
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


//ǰ������ķǵݹ����

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

//���������ķǵݹ����
//��������ݹ鶨�壺���������������������ٸ��ڵ㡣
//����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ��������������������������λ����������
//�����������ڵ㣬�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻����λ������������ֱ�ӷ��ʸ��ڵ㡣
void PostorderTree(BinaryTreeNode* treeRoot) {
	if (treeRoot == nullptr)
		return;

	stack<BinaryTreeNode*> treeStack;
	BinaryTreeNode* treeCurrent;
	BinaryTreeNode* treeLastVist = nullptr;
	treeCurrent = treeRoot;

	//�Ȱ�treeCurrent�ƶ������������±�
	while (treeCurrent != nullptr)
	{
		treeStack.push(treeCurrent);
		treeCurrent = treeCurrent->m_pLeft;
	}
	while (!treeStack.empty())
	{
		////�ߵ����treeCurrent���ǿգ����Ѿ��������������׶�(�����������������գ�����ĳ����������) 
		treeCurrent = treeStack.top();
		treeStack.pop();
		////һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ�  
		if (treeCurrent->m_pRight == nullptr || treeLastVist == treeCurrent->m_pRight) {
			printf("%d\n", treeCurrent->m_pValue);
			treeLastVist = treeCurrent;
		}
		else if (treeCurrent->m_pLeft == treeLastVist)//���������ձ����ʹ��������Ƚ���������(���ڵ����ٴ���ջ)
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

