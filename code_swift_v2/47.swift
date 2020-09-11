/*
 * 面试题47：礼物的最大价值
 * 链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
 */

import Foundation

// MARK: - 解法1
// 动态规划
func maxValue(_ grid: [[Int]]) -> Int {
	// dp[i][j]表示从左上角到grid[i][j]的最大价值
	let row = grid.count  // 行数
	let col = grid[0].count  // 列数
	
	// 初始化dp数组
	var dp = [[Int]](repeating: [Int](repeating: 0, count: col+1), count: row+1)
	for i in 1 ... row {
		dp[i][1] = dp[i-1][1] + grid[i-1][0]
	}
	for j in 1 ... col {
		dp[1][j] = dp[1][j-1] + grid[0][j-1]
	}
	
	// 动态规划
	for i in 1 ... row {
		for j in 1 ... col {
			// 比较从上面还是左面的价值大小
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i-1][j-1]
		}
	}
	
	return dp[row][col]
}

// main
func main() {
	// 手动创建测试用例
	let grid: [[Int]] = [
		[1, 10, 3, 8],
		[12, 2, 9, 6],
		[5, 7, 4, 11],
		[3, 7, 16, 5]
	]
	let val = maxValue(grid)
	print(val)
}

main()

