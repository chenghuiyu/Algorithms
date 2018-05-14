
//开始的时候，我们需要一个指向父节点的指针，并且需要保存之前的指针(开始的时候设置为null)，接下来做以下的步骤：
// 1、如果我们来自父节点，下一步移到左子节点
// 2、如果我们来自左子节点，下一步移到右子节点
// 3、如果我们来自右子节点，下一步移到父节点
//
//对于少于两个子节点的情况，我们采用下面的步骤来进行处理：
// 如果只有一个右子节点，并且来自父节点，下一步移到右子节点
// 如果来自左子节点，并且没有右子节点，下一步移到父节点
// 如果没有子节点，下一步移到父节点

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
