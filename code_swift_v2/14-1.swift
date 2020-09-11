/*
 * 面试题14-I：剪绳子
 * 链接：https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 */

import Foundation

// MARK: - 解法1
// 动态规划。有递推公式f(n) = Max(f(i) * f(n-i))，其中i=1,2,...,n-1。
// 时间复杂度：O(N) 空间复杂度：O(N)
func cuttingRope_method1(_ n: Int) -> Int {
    if n == 2 {
        return 1
    }
    if n == 3 {
        return 2
    }
    
    // dp[i]表示绳子长度为i时的最大乘积
    var dp: [Int] = Array<Int>(repeating: 1, count: n+1)
    dp[2] = 2
    dp[3] = 3
    
    // 动态规划
    for i in 4 ... n {
        for j in 1 ..< i {
            dp[i] = max(dp[i], dp[i-j] * j)
        }
    }
    
    return dp[n]
}

// MARK: - 解法2
// 贪心算法。尽可能地多剪长度为3的绳子，当剩下的绳子长度为4时，把绳子剪成两段长度为2的绳子。
// 时间复杂度：O(N) 空间复杂度：O(1)
func cuttingRope_method2(_ n: Int) -> Int {
    if n == 2{
        return 1
    }
    if n == 3 {
        return 2
    }
    
    // 尽可能地多剪长度为3的绳子
    var countOf3: Int = n / 3
    
    // 当最后长度为4的时候，剪成长度为2的两段
    if n - countOf3 * 3 == 1 {
        countOf3 -= 1
    }
    let countOf2: Int = (n - countOf3 * 3) / 2
    
    return Int(pow(3.0, Double(countOf3)) * pow(2.0, Double(countOf2)))
}

// main
func main() {
    let numString = readLine()
    let num = Int(numString!)!
    print(cuttingRope_method2(num))
}

main()

