#include <stdlib.h>

struct ListNode
{
	int p_value;
	ListNode* p_next;
};

//��ת�ַ�����������ͷ�ڵ�
ListNode* ReverseList(ListNode* pHead) {
	ListNode* pReverseHead = nullptr;
	ListNode* node = pHead;
	ListNode* node_prv = nullptr;

	while (node != nullptr)
	{
		ListNode* node_next = node->p_next;
		if (node_next == nullptr)
			pReverseHead = node;

		node->p_next = node_prv;
		node_prv = node;
		node = node_next;
	}

	return pReverseHead;
}

