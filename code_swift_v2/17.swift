/*
 * 面试题17：打印从1到最大的n位数
 * 链接：https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/
 */

import Foundation

// MARK: - 解法1
// 这题和《剑指offer》的原题不一样，返回的值的类型类整型数组，意味着不可能发生溢出。
func printNumbers(_ n: Int) -> [Int] {
    var nums: [Int] = []
    
    for i in 1 ..< Int(pow(10.0, Double(n))) {
        nums.append(i)
    }
    return nums
}

// main
func main() {
    let n = 2
    let nums = printNumbers(n)
    print(nums)
}

main()



