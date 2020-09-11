/*
 * 面试题50：第一个只出现一次的字符
 * 链接：https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
 */

import Foundation

// MARK: - 解法1
// 遍历字符串，使用一个哈希表记录每个字符出现的次数。
func firstUniqChar(_ s: String) -> Character {
	// map[key] = value表示key出现的次数
	var map: [Character: Int] = [:]
	// 需要一个数组来记录顺序，因为Swift中没有unordered_map
	var keys: [Character] = []
	
	//  统计次数
	for c in s {
		if map.keys.contains(c) {
			map[c]! += 1
		} else {
			keys.append(c)
			map[c] = 1
		}
	}
	
	// 遍历map
	var res: Character = " "
	for key in keys {
		if map[key]! == 1 {
			res = key
			break
		}
	}
	return res
}

// main
func main() {
	if let s = readLine() {
		let c = firstUniqChar(s)
		print(c)
	} else {
		print("Input Error!")
	}
}

main()

