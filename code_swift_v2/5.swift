/*
 * 面试题5：替换空格
 * 链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 */

// MARK: - 解法1
// 生成一个新的字符串，用空间换时间。
func replaceSpace_method1(_ s: String) -> String {
    var res: String = ""
    for c in s {
        if c == " " {
            res += "%20"
        } else {
            res += String(c)
        }
    }
    return res
}

// main()
func main() {
    let s = readLine()
    if let s = s {
        let res = replaceSpace_method1(s)
        print(res)
    } else {
        print("")
    }
}

main()
