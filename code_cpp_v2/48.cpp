/*
 * 题目：最长不含重复字符的子字符串
 * 链接：https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 */

#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
	const int len = s.length();
	if (len < 2) return len;

	unordered_map<char, int> hash;
	int res = 1;
	for (int tail = 0, head = 0; tail < len; ++tail) {
		// s[tail]的出现次数+1
		hash[s[tail]]++;
		// 遇到重复字符，head指针向右偏移
		while (hash[s[tail]] > 1) hash[s[head++]]--;
		// 更新结果
		res = max(res, tail - head + 1);
	}

	return res;
}

int main() {
	string s;
	cin >> s;

	// 计算最长子字符串
	int len = lengthOfLongestSubstring(s);
	cout << len << endl;

	return 0;
}