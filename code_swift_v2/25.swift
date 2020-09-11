/*
 * 面试题25：合并两个排序的链表
 * 链接：https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/
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
// 递归合并
func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }
    
    var p: ListNode? = nil
    if l1!.val < l2!.val {
        p = l1
        p?.next = mergeTwoLists(l1?.next, l2)
    } else {
        p = l2
        p?.next = mergeTwoLists(l1, l2?.next)
    }
    
    return p
}

// main
func main() {
    // 手动创建链表
    let n11: ListNode = ListNode(1)
    let n12: ListNode = ListNode(2)
    let n13: ListNode = ListNode(3)
    let n21: ListNode = ListNode(2)
    let n22: ListNode = ListNode(4)
    let n23: ListNode = ListNode(7)
    n11.next = n12
    n12.next = n13
    n21.next = n22
    n22.next = n23
    
    // 返回链表倒数第k个结点
    let new = mergeTwoLists(n11, n21)
    var p: ListNode? = new
    while p != nil {
        print(p!.val, terminator: "\t")
        p = p?.next
    }
}

main()




