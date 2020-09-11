/*
 * 题目：链表中倒数第k个结点
 */

class Node {
    var val: Int
    var next: Node?
    init(_ val: Int) {
        self.val = val
    }
}

func findKthToTail(_ head: Node?, _ k: Int) -> Node? {
    if head == nil || k == 0 {
        return nil
    }
    
    var slow: Node? = head
    var fast: Node? = head
    // 先让快指针遍历k次
    for i in 0..<k {
        if fast?.next != nil {
            fast = fast?.next
        } else {
            return nil
        } 
    }
    while fast != nil {
        fast = fast?.next
        slow = slow?.next
    }
    return slow
}
