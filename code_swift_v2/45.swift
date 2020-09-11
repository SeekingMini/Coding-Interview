/* 
 * 圆圈中最后剩下的数字
 */
func lastRemaining(_ n: Int, _ m: Int) -> Int {
    if n == 1 {
        return 0
    }
    
    var pos: Int = 0
    for i in 2 ..< n+1 {
        pos = (pos + m) % i
    }
    return pos
}

/***** 测试部分 *****/
let ans = lastRemaining(8, 3)
print(ans)
/******************/
