Problem Statement:
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

  
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
    private int min = Integer.MAX_VALUE;
    private Integer prev = null;
    public int minDiffInBST(TreeNode root) {
        if(root.left!=null)
            minDiffInBST(root.left);
        if(prev!=null)
            min = Math.min(min,Math.abs(root.val-prev));
        prev=root.val;
        if(root.right!=null) 
            minDiffInBST(root.right);
        return min;
    }
}
