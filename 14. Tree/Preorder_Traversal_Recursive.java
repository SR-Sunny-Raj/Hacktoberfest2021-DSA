// Binary Tree Preorder Traversal 
// Recursively

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer>list=new ArrayList<>();
        return preOrderTraversal(root,list);
    }
    
    public List<Integer> preOrderTraversal(TreeNode root, List<Integer>list){
        if(root!=null){
            list.add(root.val);
            preOrderTraversal(root.left,list);
            preOrderTraversal(root.right,list);
        }
        return list;
    }
}