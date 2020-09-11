/*
 * 题目：合并两个排序的链表
 * 链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (!l1) return l2;
	if (!l2) return l1;

	ListNode* p;
	if (l1->val < l2->val) {
		p = l1;
		p->next = mergeTwoLists(l1->next, l2);
	} else {
		p = l2;
		p->next = mergeTwoLists(l1, l2->next);
	}
	return p;
}

int main() {
	// 手动创建链表
	auto h1 = new ListNode(1);
	auto n11 = new ListNode(2);
	auto n12 = new ListNode(3);
	h1->next = n11;
	n11->next = n12;

	auto h2 = new ListNode(2);
	auto n21 = new ListNode(3);
	auto n22 = new ListNode(4);
	h2->next = n21;
	n21->next = n22;

	// 合并两个链表
	ListNode *newhead = mergeTwoLists(h1, h2);
	ListNode *p = newhead;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	return 0;
}