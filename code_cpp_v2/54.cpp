/*
 * 题目：二叉搜索树的第k大节点
 * 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
 */

#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int v) {
		this->val = v;
		left = nullptr;
		right = nullptr;
	}
};

void dfs(TreeNode *root, int &res, int &k) {
	if (root) {
		dfs(root->right, res, k);
		k--;
		if (k == 0) {
			res = root->val;
			return;
		}
		dfs(root->left, res, k);
	}
}

int kthLargest(TreeNode *root, int k) {
	int res = root->val;
	dfs(root, res, k);

	return res;
}

int main() {
	int k;
	cin >> k;

	// 手动创建二叉树
	auto root = new TreeNode(5);
	auto n1 = new TreeNode(3);
	auto n2 = new TreeNode(6);
	auto n3 = new TreeNode(2);
	auto n4 = new TreeNode(4);
	auto n5 = new TreeNode(1);
	root->left = n1;
	root->right = n2;
	n1->left = n3;
	n1->right = n4;
	n3->left = n5;

	// 返回二叉树的第k大结点
	int target = kthLargest(root, k);
	cout << target << endl;

	return 0;
}