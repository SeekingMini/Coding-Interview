/*
 * 题目：二叉搜索树与双向链表
 * 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
 */

#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node *left;
	Node *right;

	explicit Node(int _val) {
		val = _val;
		left = nullptr;
		right = nullptr;
	}

	Node(int _val, Node *_left, Node *_right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

// 把root结点的左右子树转换为双向链表，再和root相连；
// head是双向链表头部，tail是双向链表尾部。
void convert(Node *r, Node *&head, Node *&tail) {
	if (r == nullptr) return;

	Node *lhead, *ltail, *rhead, *rtail;
	lhead = r;
	if (!r->left) {
		convert(r->left, lhead, ltail);
		r->left = ltail;
		ltail->right = r;
	}
	rtail = r;
	if (!r->right) {
		convert(r->right, rhead, rtail);
		r->right = rhead;
		rhead->left = r;
	}
	
	head = lhead;
	tail = rtail;
}

Node *treeToDoublyList(Node *root) {
	if (root == nullptr) {
		return nullptr;
	}
	Node *head, *tail;
	convert(root, head, tail);
	head->left = tail;
	tail->right = head;
	return head;
}

int main() {
	// 手动创建二叉树
	auto root = new Node(4);
	auto n1 = new Node(2);
	auto n2 = new Node(5);
	auto n3 = new Node(1);
	auto n4 = new Node(3);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;

	// 把二叉树转换为双向链表
	treeToDoublyList(root);

	return 0;
}