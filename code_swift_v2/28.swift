/*
 * 面试题28：对称二叉树
 * 链接：https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
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
// 判断二叉树是否对称，可以这样考虑：
// 如果右子树是左子树的镜像，则二叉树对称；
// 同样地，如果左子树是右子树的镜像，则二叉树对称；
// 反之，二叉树不对称。
func isSymmetric(_ p: TreeNode?, _ q: TreeNode?) -> Bool {
	if p == nil && q == nil {  // 两者皆为空结点
		return true
	}
	if q == nil || p == nil {  // 只有一方为空结点
		return false
	}
	
	if p!.val == q!.val {
		return isSymmetric(p!.left, q!.right) && isSymmetric(p!.right, q!.left)
	} else {
		return false
	}
}

func isSymmetric(_ root: TreeNode?) -> Bool {
	return isSymmetric(root, root)
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
	
	// 判读二叉树是否对称
	let flag = isSymmetric(root)
	print(flag)
}

main()

