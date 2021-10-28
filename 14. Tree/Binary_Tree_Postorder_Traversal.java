// Binary Tree Postorder Traversal
// Iterative

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if(root==null)
            return list;
        Deque<TreeNode> stack = new ArrayDeque<>();
        Deque<Integer> out = new ArrayDeque<>();
        TreeNode temp = root;
        stack.push(temp);
        while(!stack.isEmpty()){
            TreeNode curr = stack.pop();
            out.push(curr.val);
            if(curr.left!=null)
                stack.push(curr.left);
            if(curr.right!=null)
                stack.push(curr.right);
        }

        while(!out.isEmpty()){
            list.add(out.pop());
        }
        return list;
    }

    class BinaryTreeNode<T> {
		T data;
		BinaryTreeNode<T> left;
		BinaryTreeNode<T> right;

		public BinaryTreeNode(T data) {
			this.data = data;
			this.left = null;
			this.right = null;
		}
	}

  // Binarytree
 	class BinaryTreeNode<T> {
 		T data;
 		BinaryTreeNode<T> left;
 		BinaryTreeNode<T> right;

 		public BinaryTreeNode(T data) {
 			this.data = data;
 			this.left = null;
 			this.right = null;
 		}
 	}


public class BTPostorder {

	public static void postOrder(BinaryTreeNode<Integer> root) {

	if(root==null){
        return;
    }
        postOrder(root.left);
    postOrder(root.right);

        System.out.print(root.data +" ");

}
}
class QueueUsingLL<T> {

	class Node<T> {
		T data;
		Node<T> next;
		Node(T data){
			this.data = data;
		}
	}

	private Node<T> head;
	private Node<T> tail;
	private int size = 0;

	public int size(){
		return size;
	}

	public boolean isEmpty(){
		if(size == 0){
			return true;
		}
		return false;
	}

	public T front() throws QueueEmptyException{
		if(size == 0){
			QueueEmptyException e = new QueueEmptyException();
			throw e;
		}

		return head.data;
	}


	public void enqueue(T element){
		Node<T> newNode = new Node<T>(element);

		if(head == null){
			head = newNode;
			tail = newNode;
		}
		else{
			tail.next = newNode;
			tail = newNode;
		}

		size++;
	}

	public T dequeue() throws QueueEmptyException{
		if(head == null){
			QueueEmptyException e = new QueueEmptyException();
			throw e;
		}
		if(head == tail){
			tail = null;
		}
		T temp = head.data;
		head = head.next;
		size--;
		return temp;
	}
}

}
