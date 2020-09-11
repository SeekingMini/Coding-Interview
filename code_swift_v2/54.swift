/*
 * 面试题54：二叉搜索树的第k大节点
 * 链接：https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
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
// 中序遍历二叉树所有的结点并使用辅助数组存储。
// 时间复杂度O(N) 空间复杂度O(N)
func traverse(_ root: TreeNode?, _ nums: inout [Int]) {
	if (root != nil) {
		traverse(root?.left, &nums)
		nums.insert(root!.val, at: 0)
		traverse(root?.right, &nums)
	}
}

func kthLargest(_ root: TreeNode?, _ k: Int) -> Int {
	var nums = [Int]()
	traverse(root, &nums)
	
	return nums[k-1]
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
	
	// 计算第k大的结点
	let k = 2
	let num = kthLargest(root, k)
	print(num)
}

main()
