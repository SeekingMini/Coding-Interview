/*
 * 面试题46：把数字翻译成字符串
 * 链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
 */

import Foundation

// MARK: - 解法1
// 动态规划
func translateNum(_ num: Int) -> Int {
	// 把数字转换为字符数组
	let str = String(num)
	var chars = [Character]()
	str.forEach { c in
		chars.append(c)
	}
	let len = chars.count  // 数组长度
	
	// dp[i]表示子串string[1...i]可以翻译的个数
	var dp = [Int](repeating: 0, count: len + 1)
	dp[0] = 1
	dp[1] = 1
	if chars.count == 1 {
		return 1
	}
	
	// 动态规划
	for i in 2 ... len {
		// 计算数值
		let first = chars[i-2].wholeNumberValue!
		let second = chars[i-1].wholeNumberValue!
		let res = first * 10 + second
		
		if res >= 0 && res <= 25 && first != 0 {
			dp[i] = dp[i-2] + dp[i-1]
		} else {
			dp[i] = dp[i-1]
		}
	}
	
	return dp[len]
}

// main
func main() {
	if let input = readLine() {
		if let num = Int(input) {
			let count = translateNum(num)
			print(count)
		} else {
			print("Input Error!")
		}
	} else {
		print("Input Error!")
	}
}

main()

