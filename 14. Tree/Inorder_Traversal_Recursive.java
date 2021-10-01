// Binary Tree Inorder Solution 
// Recursively

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer>list=new ArrayList<>();
        return inOrderTraversal(root,list);
    }
    
    public List<Integer> inOrderTraversal(TreeNode root, List<Integer>list){
        if(root!=null){
            inOrderTraversal(root.left,list);
            list.add(root.val);
            inOrderTraversal(root.right,list);
        }
        return list;
    }
}