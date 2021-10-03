Problem Statement:
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them.
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any path.

 
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
 
Solution:
We use recursive solution to find the maximum path the includes current node 
find maximum sum of left sub tree find maximum sum of right subtree
The we compare which of the three is maximum leftPath sum or rightPath sum or left to right Path sum via current node
However the node values are not necessarily positive hence we need extra checks if either of leftpath sum or right path sum is negative we do not consider it because 0 path sum will be greater than negative path sum
  
class Solution {
    private int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        maxSum(root);
        return max;
    }
    private int maxSum(TreeNode node){
        if(node == null)
            return 0;
        int lSum = Math.max(0,maxSum(node.left));     //we calculate left path sum and take maximum with 0
        int rSum = Math.max(0,maxSum(node.right));    // we calculate right path sum and take maximum with 0
        max = Math.max(max,lSum + rSum + node.val);   // we check if left to right path via this node is maximum or not left to right path sum = leftSum + rightSum + node.val
        return Math.max(lSum,rSum) + node.val;        // but we only return maximum of left path sum or right path sum + node.val
                                                   
    }
}
