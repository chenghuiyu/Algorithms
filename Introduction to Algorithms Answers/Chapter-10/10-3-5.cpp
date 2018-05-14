
#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

int empty_list = -1;

#define MAX_SIZE 100

typedef int list_t;
typedef int obj_t;


//定义三个数组
int prev[MAX_SIZE];
int next[MAX_SIZE];
obj_t keys[MAX_SIZE];

int free_list;

void init_storage() {
	int i;
	for (i = 0; i < MAX_SIZE - 1; i++)
		next[i] = i + 1;
	next[i] = -1;
	free_list = 0;
}


list_t allocate_object() {
	if (free_list == -1)
	{
		fprintf(stderr, "Storage depleted\n");
		exit(-1);
	}

	list_t new_list = free_list;
	free_list = next[free_list];

	return new_list;
}

void free_object(list_t list) {
	next[list] = free_list;
	free_list = list;
}


list_t cons(obj_t key, list_t list) {
	list_t new_list = allocate_object();
	next[new_list] = list;
	prev[new_list] = empty_list;
	keys[new_list] = key;

	if (list != empty_list)
		prev[list] = new_list;

	return new_list;
}


void delete_list(list_t list) {
	if (prev[list] != empty_list)
		next[prev[list]] = next[list];
	if (next[list] != empty_list)
		prev[next[list]] = prev[list];

	free_object(list);
}

obj_t get_list(list_t list) {
	if (list == empty_list)
		return -1;
	return keys[list];
}

list_t next_obj(list_t list) {
	if (list == empty_list)
		return -1;
	return next[list];
}

list_t compactify_list(list_t list) {
	list_t left, right, i;
	if (free_list == empty_list)
		return list;
	//初始化free_list的prev,先遍历free_list,
	//给每个item的prev标记一下，用来区别L中的item
	i = free_list;
	while (i != empty_list)
	{
		prev[i] = -2;
		i = next[i];
	}

	//定义两个指针left和right,left在array的头，另一个right在尾巴.
	//left向右移动知道遇到free item, right向左移动直到遇到used item,然后交换left和right的内容
	left = 0;
	right = MAX_SIZE - 1;
	while (1)
	{
		while (prev[left] != -2)
		{
			left++;
		}
		while (prev[right] == -2)
		{
			right++;
		}
		if (left > right)
			break;

		prev[left] = prev[right];
		next[left] = next[right];
		keys[left] = keys[right];

		next[right] = left;

		right--;
		left++;
	}

	right++;

	for (int i = 0; i < right; i++)
	{
		if (prev[i] >= right)
			prev[i] = next[prev[i]];
		if (next[i] >= right)
			next[i] = next[next[i]];
	}

	if (list >= right) {
		list = next[list];
	}

	for (int i = right; i < MAX_SIZE - 1; i++)
	{
		next[i] = i + 1;
	}
	next[i] = -1;
	free_list = right;

	return list;

}
