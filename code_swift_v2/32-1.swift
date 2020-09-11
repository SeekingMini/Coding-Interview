/*
 * 面试题32-I：从上到下打印二叉树
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
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
// 队列法层序遍历
func levelOrder(_ root: TreeNode?) -> [Int] {
	var nums: [Int] = []
	if root == nil {
		return nums
	}
	
	var queue: [TreeNode] = []  // 队列
	queue.append(root!)
	
	while queue.count != 0 {
		let top = queue[0]
		queue.removeFirst()
		nums.append(top.val)
		if top.left != nil {
			queue.append(top.left!)
		}
		if top.right != nil {
			queue.append(top.right!)
		}
	}
	return nums
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
	let nums = levelOrder(root)
	print(nums)
}

main()
