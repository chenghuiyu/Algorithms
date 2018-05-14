//n���ڵ�Ķ����������÷ǵݹ鷽ʽ�����������ÿ���ڵ��ֵ������ջʵ��

struct BinaryTreeNode
{
	BinaryTreeNode* left_child;
	BinaryTreeNode* right_child;
	BinaryTreeNode* parent;
	int key;
};

#define MAX_SIZE 10
int keys[MAX_SIZE];
int count = 0;

void store(int);

void print_tree(BinaryTreeNode* tree) {
	BinaryTreeNode* stack_tree[MAX_SIZE];
	int number = 0;
	stack_tree[number++] = tree;

	while (number)
	{
		tree = stack_tree[--number];

		store(tree->key);
		if (tree->left_child)
			stack_tree[++number] = tree->left_child;
		if (tree->right_child)
			stack_tree[++number] = tree->right_child;
	}

}

void reset_storage() {
	count = 0;
}

void store(int key) {
	keys[count++] = key;
}