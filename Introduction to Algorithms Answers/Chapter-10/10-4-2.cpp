//n个节点的二叉树，采用递归方式遍历，并输出每个节点的值


struct BinaryTreeNode
{
	BinaryTreeNode* left_child;
	BinaryTreeNode* right_child;
	BinaryTreeNode* parent;
	int key;
};

void store(int);

void print_tree(BinaryTreeNode* tree) {
	store(tree->key);

	if (tree->left_child)
		print_tree(tree->left_child);
	if (tree->right_child)
		print_tree(tree->right_child);
}

#define MAX_SIZE 10
int keys[MAX_SIZE];
int count = 0;

void store(int key) {
	keys[count++] = key;
}

