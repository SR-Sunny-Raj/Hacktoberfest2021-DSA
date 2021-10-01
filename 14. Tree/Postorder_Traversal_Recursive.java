// Binary Tree Postorder Traversal
// Recursilvely

class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer>list=new ArrayList<>();
        return postOrderTraversal(root,list);
    }
    
    public List<Integer> postOrderTraversal(TreeNode root, List<Integer>list){
        if(root!=null){
            postOrderTraversal(root.left,list);
            postOrderTraversal(root.right,list);
            list.add(root.val);
        }
        return list;
    }
}