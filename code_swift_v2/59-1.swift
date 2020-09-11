/*
 * 面试题59-I：滑动窗口的最大值
 * 链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
 */

import Foundation

// MARK: - 解法1
// 暴力解法。每次先计算滑动窗口中的最大值，再将窗口向前进一步。
// 时间复杂度：O(kN)
// PS: LeetCode上测试勉强能通过，但是速度极慢...
func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
	if nums.count == 0 {
		return [Int]()
	}
	
	// 循环次数
	let count = nums.count - k + 1
	
	// 初始化窗口
	var window = [Int]()
	for i in 0 ..< k {
		window.append(nums[i])
	}
	
	// 窗口推进
	var res = [Int]()
	for i in 0 ..< count {
		res.append(max(window))
		window.remove(at: 0)
		if i != count - 1 {
			window.append(nums[i+k])
		}
	}
	return res
}

// 返回数组最大值
func max(_ nums: [Int]) -> Int {
	var res = nums[0]
	for num in nums {
		if num > res {
			res = num
		}
	}
	return res
}


// main
func main() {
	// 输入数据
	if let inputs = readLine() {
		let stringNums = inputs.split(separator: " ")
		
		var nums : [Int] = []
		for i in 0 ..< stringNums.count {
			if let num = Int(stringNums[i]) {
				nums.append(num)
			}
		}
		
		// 计算滑动窗口最大值
		let res = maxSlidingWindow(nums, 3)
		print(res)
	} else {
		print("Input Error!")
	}
}

main()
