/*
 * 面试题3：数组中重复的数字
 * 链接：https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
 */

// MARK: - 解法1
// 使用辅助数组记录每个数字出现的次数
// 时间复杂度：O(N) 空间复杂度：O(N)
func findRepeatNumber_method1(_ nums: [Int]) -> Int {
    let len = nums.count
    // hash[i]表示数字i出现在nums中出现了hash[i]次
    var hash = Array<Int>(repeating: 0, count: len)
    
    for i in 0 ..< len {
        if hash[nums[i]] >= 1 {
            return nums[i]
        } else {
            hash[nums[i]] += 1
        }
    }
    return -1
}

// MARK: - 解法2
// 扫描一遍数字，记下标为i的数字为m。如果这个数组是没有重复数字的，那么排序后m应该等于i。
// 例如：令n=4，则数组为[0, 1, 2, 3]，其下标为[0, 1, 2, 3]。
// 我们将nums[m]与nums[i]的数字进行交换，在交换过程中，如果nums[m]和nums[i]相同，则m是重复的数字。
// 时间复杂度：O(N) 空间复杂度：O(1)
func findRepeatNumber_method2(_ nums: inout [Int]) -> Int {
    let len = nums.count  // 数组长度
    
    for i in 0 ..< len {
        while i != nums[i] {  // 下标i和nums[i]不相等
            let m = nums[i]
            if m == nums[m] {  
                return nums[i]
            }
            let tmp = m
            nums[i] = nums[m]
            nums[m] = tmp
        }
    }
    return -1
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
        
        // 寻找数组中重复的数字
        print(findRepeatNumber_method2(&nums))
    } else {
        print("Input Error!")
    }
}

main()

