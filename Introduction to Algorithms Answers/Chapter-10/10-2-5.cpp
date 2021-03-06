#include <stdlib.h>

struct node_t
{
	int key;
	node_t* next;
};

struct list_t
{
	node_t nil;
};
// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用


//单向循环链表的初始化
void init_list(list_t* list) {
	list->nil.key = 0;
	//指向表头
	list->nil.next = &(list->nil);
}

void destroy_list(list_t* list) {
	//初始化链表节点指向头结点
	node_t* node = list->nil.next;
	//定义下一个节点
	node_t* next;

	while (node != &(list->nil))
	{
		//保存下一个节点
		next = node->next;
		free(node);
		node = next;
	}
}

//插入操作
void insert_list(list_t* list, int value) {
	//为新节点创建内存空间
	node_t* new_node = (node_t*)malloc(sizeof(node_t));
	new_node->key = value;
	//新节点指向头节点
	new_node->next = list->nil.next;
	//重新定义头节点
	list->nil.next = new_node;

}

node_t* search_node(list_t* list, int value) {
	node_t* node = list->nil.next;

	//为了在后面的循环中省去对哨兵nil的检查
	list->nil.key = value;

	while (node->key != value)
	{
		node = node->next;
	}

	if (node == &(list->nil)) {
		return nullptr;
	}
	else
	{
		return node;
	}

}


void delete_node(list_t* list, int value) {
	node_t* node = &(list->nil);

	while (node->next != &(list->nil))
	{
		if (node->next->key == value) {
			node_t* to_delete = node->next;
			node->next = node->next->next;
			delete(node->next);
		}
		else
		{
			node = node->next;
		}
	}
}
