/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isValidBST(TreeNode root) {
        
        return check(root,Long.MIN_VALUE,Long.MAX_VALUE);
        
    }
    static boolean check(TreeNode r,long min,long max){
        if(r==null) return true;
        
        if(r.val>=max || r.val <=min) return false;
            
            if(check(r.left,min,r.val) && check(r.right,r.val,max)) return true;
        return false;
    }
    
}
