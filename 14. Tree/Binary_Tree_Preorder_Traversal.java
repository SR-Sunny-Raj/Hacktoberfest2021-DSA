// Binary Tree Preorder Traversal
// Iterative

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if(root==null)
            return list;
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode temp = root;
        stack.push(temp);
        while(!stack.isEmpty()){
            temp=stack.pop();
            while(temp!=null){
                list.add(temp.val);
                if(temp.right!=null)
                    stack.push(temp.right);
                temp=temp.left;
            }
        }
        return list;
    }
}