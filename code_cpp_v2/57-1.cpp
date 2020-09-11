/*
 * 题目：和为s的两个数字
 * 链接：https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
	const int len = nums.size();

	int start = 0;  // 指向第1个数字
	int end = len - 1;  // 指向最后1个数字

	while (start < end) {
		int n1 = nums[start];
		int n2 = nums[end];

		if (n1 + n2 == target) {
			vector<int> res = {n1, n2};
			return res;
		} else if (n1 + n2 < target) {
			start++;
		} else if (n1 + n2 > target) {
			end--;
		}
	}

	return vector<int>(2, 0);
}

int main() {
	int n, target;
	vector<int> nums;

	// 输入数据
	cin >> target;
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 返回和为s的两个数字
	vector<int> pair = twoSum(nums, target);
	cout << pair[0] << " " << pair[1] << endl;

	return 0;
}