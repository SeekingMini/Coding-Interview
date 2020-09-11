/*
 * 面试题21：调整数组顺序使奇数位于偶数前面
 * 链接：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 */

// MARK: - 解法1
// 维护两根指针，一根向后移动，一根向前移动。
func exchange(_ nums: [Int]) -> [Int] {
    var numsCopy = nums  // nums是let常量，不能改变值
    var begin = 0  // 指向数组第一个数字
    var end = nums.count - 1  // 指向数组最后一个数字
    
    while begin < end {
        // begin指针向后移动直到指向偶数
        while begin < end && numsCopy[begin] % 2 == 1 {
            begin += 1
        }
        // end指针向前移动直到指向奇数
        while begin < end && numsCopy[end] % 2 == 0 {
            end -= 1
        }
        // 交换数字
        let tmp = numsCopy[begin]
        numsCopy[begin] = numsCopy[end]
        numsCopy[end] = tmp
    }
    
    return numsCopy
}

// main()
func main() {
    let nums = [1, 2, 3, 4]
    print(exchange(nums))
}

main()

