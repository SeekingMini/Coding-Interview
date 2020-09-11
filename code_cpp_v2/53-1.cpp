/*
 * 题目：在排序数组中查找数字 I
 * 链接：https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 */

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
	if (nums.empty()) return 0;
	if (nums.size() == 1) return nums[0] == target ? 1 : 0;

	int start = 0, end = nums.size() - 1;
	int left = 0, right = 0;

	// 二分查找找出最左边的target
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (nums[mid] < target) start = mid + 1;
		else if (nums[mid] > target) end = mid - 1;
		else {
			int t1 = mid - 1;
			if (t1 >= 0 && nums[t1] == target) {
				end = t1;
			} else {
				left = mid;
				break;
			}
		}
	}
	// 二分查找找出最右边的target
	start = 0;
	end = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (nums[mid] < target) start = mid + 1;
		else if (nums[mid] > target) end = mid - 1;
		else {
			int t2 = mid + 1;
			if (t2 != nums.size() && nums[t2] == target) {
				start = t2;
			} else {
				right = mid;
				break;
			}
		}
	}

	if (right == 0 && nums[right] != target) return 0;
	else return right - left + 1;
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

	// 返回target在排序数组中出现的次数
	int count = search(nums, target);
	cout << count << endl;

	return 0;
}