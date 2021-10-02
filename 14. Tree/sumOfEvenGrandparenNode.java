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
    static int sum;
    public int sumEvenGrandparent(TreeNode root) {
         sum=0;
        solve(root);
        return sum;
    }
    static void solve(TreeNode root){
        if(root==null) return;
       
        if(root.val%2==0){
            if(root.left!=null && root.left.left!=null){
                sum+=root.left.left.val;
            }
             if(root.left!=null && root.left.right!=null){
                sum+=root.left.right.val;
            }
             if(root.right!=null && root.right.left!=null){
                sum+=root.right.left.val;
            }
              if(root.right!=null && root.right.right!=null){
                sum+=root.right.right.val;
            }
        }
        solve(root.left);
        solve(root.right);
    }
}
