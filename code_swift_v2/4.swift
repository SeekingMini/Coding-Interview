/*
 * 面试题4：二维数组中的查找
 * 链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
 */

// MARK: - 解法1
// 从左下角的数字开始查找。
// A. 如果target大于此数，则从此数的右方的第一个数字开始查找；
// B. 如果target小于此数，则从此数的上方的第一个数字开始查找；
// C. 如果target等于此数，则查找结束。
// 同理，也可以从右上角开始查找。
// 重点：为什么要从左下角或者右上角开始查找呢？
// 因为左下角的数字有这样的性质：它比上面的数字大，但比右边的数字小。这点很重要，我们只要判断一次就行了！
func findNumberIn2DArray(_ matrix: [[Int]], _ target: Int) -> Bool {
    let row: Int = matrix.count  // 行数
    if row <= 0 {
        return false
    }
    let col: Int = matrix[0].count // 列数
    
    // 从矩阵左下角开始向右上方向寻找
    var r = row - 1
    var c = 0
    while r >= 0 && c <= col - 1 {
        let num = matrix[r][c]
        if num == target {
            return true
        } else if num < target {
            c += 1
        } else if num > target {
            r -= 1
        }
    }
    return false
}

// main
func main() {
    // 手动创建二维数组
    let matrix: [[Int]] = [[1, 2, 8, 9], [2, 4, 9, 12], [4, 7, 10, 13], [6, 8, 11, 15]]
    
    // 查找
    let target: Int = 7
    let flag = findNumberIn2DArray(matrix, target)
    print(flag)
}

main()
