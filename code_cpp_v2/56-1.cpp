/*
 * 题目：数组中数字出现的次数
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumbers(vector<int> &nums) {
	int s = 0;
	// s最终是2个只出现1次数字的异或结果
	for (int num : nums) {
		s ^= num;
	}

	// k的二进制表示中一定有1位是1
	int k = s & (-s);
	vector<int> res(2, 0);
	for (int num : nums) {
		if (num & k) {
			res[0] ^= num;
		} else {
			res[1] ^= num;
		}
	}

	return res;
}

int main() {
	int n;
	vector<int> nums;

	// 输入数据
	while (cin >> n) {
		nums.push_back(n);

		if (getchar() == '\n') break;
	}

	// 返回只出现1次的数字
	vector<int> res = singleNumbers(nums);
	for (int num : res)
		cout << num << " ";
	cout << endl;

	return 0;
}