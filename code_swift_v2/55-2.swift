/*
 * 面试题55-II：平衡二叉树
 * 链接：https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
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
// 递归检查每个非叶子结点的平衡性
func maxDepth(_ root: TreeNode?) -> Int {
	if root == nil {
		return 0
	}
	
	// 计算左右子树的高度
	let leftHeight = maxDepth(root?.left)
	let rightHeight = maxDepth(root?.right)
	
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1
}

func isBalanced(_ root: TreeNode?) -> Bool {
	if root == nil {
		return true
	}
	
	// 左右子树高度之差
	let diff = abs(maxDepth(root?.left) - maxDepth(root?.right))
	
	return diff <= 1 && isBalanced(root?.left) && isBalanced(root?.right)
}

// main
func main() {
	// 手动创建二叉树
	let root = TreeNode(5)
	let n1 = TreeNode(3)
	let n2 = TreeNode(7)
	let n3 = TreeNode(2)
	let n4 = TreeNode(4)
	let n5 = TreeNode(8)
	root.left = n1
	root.right = n2
	n1.left = n3
	n1.right = n4
	n2.right = n5
	
	// 判断二叉树是否平衡
	let flag = isBalanced(root)
	print(flag)
}

main()
