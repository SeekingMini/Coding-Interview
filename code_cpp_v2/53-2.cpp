/*
 * 题目：0～n-1中缺失的数字
 * 链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &nums) {
	const int len = nums.size();
	int left = 0;
	int right = len - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		// 中间元素等于下标
		if (nums[mid] == mid) left = mid + 1;
		else {
			if (mid == 0 || nums[mid - 1] == mid - 1) return mid;
			right = mid - 1;
		}
	}

	if (left == len) return len;
	else return -1;
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

	// 返回缺失的数字
	int res = missingNumber(nums);
	cout << res << endl;

	return 0;
}