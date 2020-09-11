/*
 * 面试题10-II：青蛙跳台阶问题
 * 链接：https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
 */

// MARK: - 解法1
// 根据动态规划状态转移方程f(n) = f(n-1) + f(n-2)求解。
// 其中f(0)=1，f(1)=1，f(2)=2。
func numWays(_ n: Int) -> Int {
    // dp[i] = dp[i-1] + dp[i-2]
    var dp: [Int] = Array<Int>(repeating: 0, count: 101)
    
    // 初始化dp
    dp[0] = 1
    dp[1] = 1
    dp[2] = 2
    
    // 动态规划
    if n >= 3 {
        for i in 3 ... n {
            dp[i] = (dp[i-1] + dp[i-2]) % 10_0000_0007
        }
        
    }
    
    return dp[n]
}

// main
func main() {
    let n = 7
    print(numWays(n))
}

main()



