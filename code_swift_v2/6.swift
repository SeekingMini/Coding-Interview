/*
 * 面试题6：从尾到头打印链表
 * 链接：https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
 */

class Node {
    var val: Int
    var next: Node?
    
    init(_ val: Int) {
        self.val = val
        next = nil
    }
}

// MARK: - 解法1
// 使用一个栈，遍历链表并将结点压入栈中，再弹出打印。
// 时间复杂度：O(N) 空间复杂度：O(N)
func reversePrint(_ head: Node?) -> [Int] {
    if head == nil {
        return Array<Int>()
    }
    
    // 定义一个栈用于逆序保存链表结点值
    var p:Node? = head
    var stack: [Int] = []
    while p != nil {
        stack.insert(p!.val, at: 0)
        p = p?.next
    }
    return stack
}

// main
func main() {
    // 手动创建链表
    let head = Node(4)
    let n1 = Node(2)
    let n2 = Node(-1)
    let n3 = Node(7)
    let n4 = Node(6)
    head.next = n1
    n1.next = n2
    n2.next = n3
    n3.next = n4
    
    //从尾到头打印
    let res = reversePrint(head)
    for n in res {
        print(n, terminator: " ")
    }
}

main()

