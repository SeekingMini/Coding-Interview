/*
 * 题目：复杂链表的复制
 * 链接：https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
 */

#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;

	explicit Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

Node *copyRandomList(Node *head) {
	if (!head) return nullptr;
	Node* p = head;

	// 先复制结点
	while (p) {
		Node* copied = new Node(p->val);
		copied->next = p->next;
		p->next = copied;
		p = copied->next;
	}

	// 再复制随机指针
	p = head;
	while (p) {
		Node* copied = p->next;
		if (p->random) copied->random = p->random->next;
		p = copied->next;
	}

	// 分离
	Node* prev = new Node(-1);
	Node* q = prev;
	p = head;
	while (p) {
		Node* copied = p->next;
		q->next = copied;
		q = q->next;
		p->next = copied->next;
		p = p->next;
	}

	return prev->next;
}

int main() {
	// 手动创建链表
	auto head = new Node(1);
	auto n1 = new Node(2);
	auto n2 = new Node(3);
	auto n3 = new Node(4);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	head->random = n3;
	n3->random = n2;

	// 复制链表
	Node *newhead = copyRandomList(head);
	Node *p = newhead;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}

	return 0;
}