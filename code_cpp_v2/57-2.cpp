/*
 * 题目：和为s的连续正数序列
 * 链接：https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findContinuousSequence(int target) {
	vector<vector<int>> res;

	int start = 1;  // 滑动窗口左侧
	int end = 1;  // 滑动窗口右侧
	int sum = 0;

	while (start <= target / 2) {
		if (sum < target) {
			// 右侧移动
			sum += end;
			end++;
		} else if (sum > target) {
			// 左侧移动
			sum -= start;
			start++;
		} else {
			// 添加数组
			vector<int> nums;
			for (int i = start; i < end; ++i) {
				nums.push_back(i);
			}
			res.push_back(nums);
			sum -= start;
			start++;
		}
	}

	return res;
}

int main() {
	int target;

	// 输入数据
	cin >> target;

	// 返回和为s的两个数字
	vector<vector<int>> pairs = findContinuousSequence(target);
	for (const vector<int> &nums : pairs) {
		for (int num : nums)
			cout << num << " ";
		cout << endl;
	}

	return 0;
}