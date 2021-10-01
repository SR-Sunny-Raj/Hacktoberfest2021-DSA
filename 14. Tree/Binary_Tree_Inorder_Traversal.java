// Binary Tree Inorder Traversal
// Iterative

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        if(root == null)
            return list;
        Deque<TreeNode> stack = new ArrayDeque<>();
        TreeNode temp = root;
        do{
            while(temp!=null){
                stack.push(temp);
                temp=temp.left;
            }
            temp = stack.pop();
            
            while(temp!=null){
                list.add(temp.val);
                if(temp.right!=null){
                    temp=temp.right;
                    break;
                }
                if(!stack.isEmpty())
                    temp=stack.pop();
                else
                    return list;
            }
        }while(temp!=null);
        return list;
    }
}
