/*
 * 面试题39：数组中出现次数超过一半的数字
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof/
 */

// MARK: - 解法1
func majorityElement(_ nums: [Int]) -> Int {
	var res = nums[0]
	var count = 1
	
	let len = nums.count  // 数组长度
	for i in 1 ..< len {
		if nums[i] == res {
			count += 1
		} else {
			count -= 1
			if count == 0 {
				res = nums[i]
				count = 1
			}
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
		
		// 寻找数组中出现次数超过一半的数字
		print(majorityElement(nums))
	} else {
		print("Input Error!")
	}
}

main()

