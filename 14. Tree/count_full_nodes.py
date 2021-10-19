# Python program to count full nodes in a Binary Tree
# <Iterative approach>

# Node structure
class Node:
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

def count_full_nodes(root):

	# If tree rooted with 'root' is empty
	if root is None:
		return 0

	# Queue for level order traversal of tree
	queue = []

	# Enqueue Root
	queue.append(root)

    # Initialize count for full nodes
	count = 0

	while (len(queue) > 0):

		node = queue.pop(0)

		# If it is full node then increment count
		if node.left is not None and node.right is not None:
			count = count+1

		# Enqueue left child
		if node.left is not None:
			queue.append(node.left)

		# Enqueue right child
		if node.right is not None:
			queue.append(node.right)

	return count

root = Node(21)
root.left = Node(7)
root.right = Node(14)
root.left.left = Node(42)
root.left.right = Node(70)
root.left.right.left = Node(49)
root.left.right.right = Node(35)
root.right.right = Node(28)
root.right.left = Node(56)
root.right.right.left = Node(63)

print "%d" %(count_full_nodes(root))
