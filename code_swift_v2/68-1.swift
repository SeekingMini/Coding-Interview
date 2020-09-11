/*
 * 面试题68-I：二叉搜索树的最近公共祖先
 * 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
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
// 1. 如果p和q的节点值都大于root结点值，则最近公共祖先在root或root右子树上；
// 2. 如果p和q的节点值都小于root结点值，则最近公共祖先在root或root左子树上；
// 3. 否则，root为最近公共祖先。
func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
	if let root = root, let p = p, let q = q {
		if root.val < p.val && root.val < q.val {
			return lowestCommonAncestor(root.right, p, q)
		} else if root.val > p.val && root.val > q.val {
			return lowestCommonAncestor(root.left, p, q)
		} else {
			return root
		}
	} else {
		return nil
	}
}

// main
func main() {
	// 手动创建二叉搜索树
	let root = TreeNode(3)
	let n1 = TreeNode(2)
	let n2 = TreeNode(6)
	let n3 = TreeNode(1)
	let n4 = TreeNode(5)
	let n5 = TreeNode(7)
	root.left = n1
	root.right = n2
	n1.left = n3
	n2.left = n4
	n2.right = n5
	
	// 寻找两个结点的最近祖先
	let p = n3
	let q = n4
	let ancestor = lowestCommonAncestor(root, p, q)
	if let ancestor = ancestor {
		print(ancestor.val)
	} else {
		print("nil")
	}
}

main()




