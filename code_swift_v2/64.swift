/*
 * 面试题64：求1+2+...+n
 * 链接：https://leetcode-cn.com/problems/qiu-12n-lcof/solution/da-ying-wo-bie-zai-ifelse-zou-tian-xia-liao-hao-ma/
 */

import Foundation

// MARK: - 解法1
// 由于循环会用到for，所以采用递归。
// 可以列出方程：f(n) = f(n-1) + n，其中f(n)表示1+2+...+n的和。
func sumNums(_ n: Int) -> Int {
	var sum = n
	(n > 0) && { sum += sumNums(n - 1); return true }()
	return sum;
}


// main
func main() {
	// 输入数据
	if let input = readLine() {
		let n = Int(input)!
		
		// 求和
		let sum = sumNums(n)
		print(sum)
	}
}

main()