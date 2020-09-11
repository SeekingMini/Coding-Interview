/*
 * 面试题55-I：二叉树的深度
 * 链接：https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
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
// 1. Height(root) = Max{Height(root->left), Height(root->right)} + 1
// 2. 怎么计算Height(root->left)和Height(root->right)？请看步骤1
func maxDepth(_ root: TreeNode?) -> Int {
	if root == nil {
		return 0
	}
	
	// 计算左右子树的高度
	let leftHeight = maxDepth(root?.left)
	let rightHeight = maxDepth(root?.right)
	
	return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1
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
	
	// 计算二叉树高度
	let h = maxDepth(root)
	print(h)
}

main()
