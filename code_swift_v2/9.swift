/*
 * 面试题9：用两个栈实现队列
 * 链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */

// MARK: - 解法1
class CQueue {
    
    private var st1: [Int]  // 主栈
    private var st2: [Int]  // 辅助栈

    init() {
        st1 = []
        st2 = []
    }
    
    func appendTail(_ value: Int) {
        st1.append(value)
    }
    
    func deleteHead() -> Int {
        if st1.count == 0 {  // 队列中没有元素
            return -1
        }
        if st1.count == 1 {  // 队列中只有一个元素
            return st1.remove(at: 0)
        }
        
        // 队列中至少有两个元素
        while st1.count != 1 {
            st2.append(st1.removeLast())
        }
        let res = st1.removeLast()  // 队首元素
        while st2.count != 0 {
            st1.append(st2.removeLast())
        }
        return res
    }
}


