/*
 * 面试题32-III：从上到下打印二叉树 III
 * 链接：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
func levelOrder(_ root: TreeNode?) -> [[Int]] {
	var nums: [[Int]] = []
	if root == nil {
		return nums
	}
	
	var level = 0
	var queue: [TreeNode] = []  // 队列
	var oneLevelNums: [Int]  // 用来存储一层的结点
	queue.append(root!)
	
	while queue.count != 0 {
		level += 1
		oneLevelNums = []
		let currentSize = queue.count // 当前层的结点数
		
		// 遍历当前层的所有结点
		if level % 2 == 1{
			for _ in 0 ..< currentSize {
				let top = queue.removeFirst()
				oneLevelNums.append(top.val)
				if top.left != nil {
					queue.append(top.left!)
				}
				if top.right != nil {
					queue.append(top.right!)
				}
			}
		} else {
			for _ in 0 ..< currentSize {
				let top = queue.removeFirst()
				oneLevelNums.insert(top.val, at: 0)
				if top.left != nil {
					queue.append(top.left!)
				}
				if top.right != nil {
					queue.append(top.right!)
				}
			}
		}
		
		nums.append(oneLevelNums)
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
