/*
 * 面试题15：二进制中1的个数
 * 链接：https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/
 */

// MARK: - 解法1
// 因为是32位整数，所以只需要移位32次即可。为了避免溢出，不对n进行移位，而是使用一个flag进行移位。
func hammingWeight(_ n: Int) -> Int {
    var count = 0
    var flag: Int = 1
    for _ in 0 ..< 32 {
        if n & flag > 0 {
            count += 1
        }
        flag = flag << 1
    }
    return count
}

// main
func main() {
    let n = 9
    print(hammingWeight(n))
}

main()

