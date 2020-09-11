/*
 * 面试题68-II：二叉树的最近公共祖先
 * 链接：https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
 */

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

// MARK: - 解法1
// p和q的分布有三种情况：
// 1. p和q在root的左子树上，那么最近公共祖先在root的左子树上；
// 2. p和q在root的右子树上，那么最近公共祖先在root的右子树上；
// 3. p和q在root的两侧，那么最近公共祖先就是root。
func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
    if root == nil {
        return nil
    }
    if root?.val == q?.val || root?.val == p?.val {
        return root
    }
    
    // 分别在左子树和右子树上寻找p和q的最近公共祖先
    let left: TreeNode? = lowestCommonAncestor(root?.left, p, q)
    let right: TreeNode? = lowestCommonAncestor(root?.right, p, q)
    
    // 左子树上没找到p和q的最近的公共祖先
    if (left == nil) {
        return right;
    }
    // 右子树上没找到p和q的最近的公共祖先
    if (right == nil) {
        return left;
    }
    // p和q分居根结点两侧
    if (left != nil && right != nil) {
        return root;
    }
    return nil;
}

// main
func main() {
    // 手动创建二叉树
    let root = TreeNode(5)
    let n1 = TreeNode(3)
    let n2 = TreeNode(3)
    let n3 = TreeNode(2)
    let n4 = TreeNode(2)
    root.left = n1
    root.right = n2
    n1.right = n3
    n2.left = n4
    
    // 寻找两个结点的最近祖先
    let p = n1
    let q = n4
    let ancestor = lowestCommonAncestor(root, p, q)
    if let ancestor = ancestor {
        print(ancestor.val)
    } else {
        print("nil")
    }
}

main()



