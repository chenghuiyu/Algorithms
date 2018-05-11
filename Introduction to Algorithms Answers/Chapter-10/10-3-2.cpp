#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef int list_t;
typedef int obj_t;

// 10-3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

int empty_list = -1;

//数组的总长度
int cells[MAX_SIZE * 3];
int free_list;

#define NEXT(i) cells[(i) + 1]
#define PREV(i) cells[(i) + 2]
#define KEY(i)  cells[i]


void int_storage() {
	int i;
	for (i = 0; i < (MAX_SIZE - 1) * 3; i += 3)
		NEXT(i) = i + 3;
	NEXT(i) = -1;
	free_list = 0;
}

list_t allocate_object() {
	if (free_list == -1) {
		fprintf(stderr, "Storage delete\n");
		exit(1);
	}

	list_t new_list = free_list;
	free_list = NEXT(free_list);

	return new_list;
}


void free_object(list_t list) {
	NEXT(list) = free_list;
	free_list = list;
}


list_t cons(obj_t key, list_t list) {
	list_t new_list = allocate_object();

	NEXT(new_list) = list;
	PREV(new_list) = empty_list;
	KEY(new_list) = key;

	if (list != empty_list)
		PREV(list) = new_list;

	return new_list;
}


void delete_list(list_t list) {
	if (PREV(list) != empty_list) {
		NEXT(PREV(list)) = NEXT(list);
	}

	if (NEXT(list) != empty_list) {
		PREV(NEXT(list)) = PREV(list);
	}

	free_object(list);
}


obj_t get(list_t list) {
	if (list == empty_list)
		return -1;
	return KEY(list);
}


list_t next(list_t list) {
	if (list == empty_list)
		return -1;
	return NEXT(list);
}


int main()
{
	int_storage();
	list_t new_list = cons(6, empty_list);
	new_list = cons(5, new_list);
	new_list = cons(7, new_list);

	printf("%d\n", get(new_list));
	printf("%d\n", get(NEXT(new_list)));
	printf("%d\n", get(PREV(new_list)));
	return 0;
}

