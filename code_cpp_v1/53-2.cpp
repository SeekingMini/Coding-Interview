/*
 * 题目：0～n-1中缺失的数字
 * 链接：https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
 */

#include <vector>
#include <iostream>

using namespace std;

int missingNumber(vector<int>& nums) {
	int length = nums.size();
	
	// 等差数列求和
	int expect = length * (length + 1) / 2;
	int sum = 0;
	for (int num : nums) sum += num;
	
	return expect - sum;
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}
	
	// 查找缺失的数字
	int num = missingNumber(nums);
	cout << num << endl;

	return 0;
}
