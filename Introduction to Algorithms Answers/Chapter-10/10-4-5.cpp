
//��ʼ��ʱ��������Ҫһ��ָ�򸸽ڵ��ָ�룬������Ҫ����֮ǰ��ָ��(��ʼ��ʱ������Ϊnull)�������������µĲ��裺
// 1������������Ը��ڵ㣬��һ���Ƶ����ӽڵ�
// 2����������������ӽڵ㣬��һ���Ƶ����ӽڵ�
// 3����������������ӽڵ㣬��һ���Ƶ����ڵ�
//
//�������������ӽڵ����������ǲ�������Ĳ��������д���
// ���ֻ��һ�����ӽڵ㣬�������Ը��ڵ㣬��һ���Ƶ����ӽڵ�
// ����������ӽڵ㣬����û�����ӽڵ㣬��һ���Ƶ����ڵ�
// ���û���ӽڵ㣬��һ���Ƶ����ڵ�

struct BinaryTreeNode
{
	BinaryTreeNode* left_child;
	BinaryTreeNode* right_child;
	BinaryTreeNode* parent;
	int key;
};

#include "stdafx.h"

#define MAX_SIZE 10
int keys[MAX_SIZE];
int count = 0;

void store(int);

void print_tree(BinaryTreeNode* tree) {
	BinaryTreeNode* tree_Prv = nullptr;
	while (tree)
	{
		if (tree_Prv == tree->parent) {
			store(tree->key);
			tree_Prv = tree;
			tree = tree->left_child ? tree->left_child :
				tree->right_child ? tree->right_child :
				tree->parent;
		}
		else if (tree_Prv == tree->left_child && tree->right_child) {
			tree_Prv = tree;
			tree = tree->right_child;
		}
		else
		{
			tree_Prv = tree;
			tree = tree->parent;
		}
	}
}

void reset_storage() {
	count = 0;
}

void store(int key) {
	keys[count++] = key;
}
