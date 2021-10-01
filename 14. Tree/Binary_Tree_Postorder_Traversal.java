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
}