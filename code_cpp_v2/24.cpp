/*
 * 题目：反转链表
 * 链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
 */
 
#include <iostream>

using namespace std;

// 链表结点
struct ListNode {
	int val;
	ListNode *next;

	explicit ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

// 递归函数含义：反转以head为头结点的链表，并返回新的头结点。
ListNode* reverseList(ListNode* head) {
	// 空链表
	if (!head) return nullptr;
	// 链表只有一个结点
	if (!head->next) return head;
	
	ListNode* newhead = reverseList(head->next);
	head->next->next = head;
	head->next = nullptr;
	
	return newhead;
}

int main() {
	// 手动创建链表
	auto head = new ListNode(1);
	auto n1 = new ListNode(2);
	auto n2 = new ListNode(-3);
	auto n3 = new ListNode(3);
	auto n4 = new ListNode(4);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	
	// 反转链表
	ListNode* newhead = reverseList(head);
	ListNode* p = newhead;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	
	return 0;
}
