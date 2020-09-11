/*
 * 面试题22：链表中倒数第k个节点
 * 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
 */

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

// MARK: - 解法1
// 定义快慢指针。先让快指针向前移k次，再让慢指针向前遍历。
func getKthFromEnd(_ head: ListNode?, _ k: Int) -> ListNode? {
    if head == nil {
        return nil
    }
    
    //  定义快慢指针
    var fast: ListNode? = head
    var slow: ListNode? = head
    
    // 快指针先移动
    for _ in 0 ..< k {
        fast = fast?.next
    }
    
    while fast != nil {
        fast = fast?.next
        slow = slow?.next
    }
    
    return slow
}

// main
func main() {
    // 手动创建链表
    let n1: ListNode = ListNode(1)
    let n2: ListNode = ListNode(2)
    let n3: ListNode = ListNode(3)
    let n4: ListNode = ListNode(4)
    let n5: ListNode = ListNode(5)
    let n6: ListNode = ListNode(6)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    n5.next = n6
    
    // 返回链表倒数第k个结点
    let k = 4
    let node = getKthFromEnd(n1, k)
    if let node = node {
        print(node.val)
    } else {
        print("nil")
    }
}

main()



