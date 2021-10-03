Problem Statement: 
You are given a Binary Tree of integers. You are supposed to return the top view of the given binary tree. 
The Top view of the binary tree is the set of nodes that are visible when we see the tree from the top.


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

import java.util.*;

public class Solution {
  
    public static class Pair{         //Use a special class to associate column number with each tree node, one can also use the in-built pair data structure
        int column;
        TreeNode node;
        public Pair(int column, TreeNode node){
            this.column = column;
            this.node = node;
        }
    }
  
	public static ArrayList<Integer> getTopView(TreeNode root) {
		
    ArrayList<Integer> ans = new ArrayList<>();
    
		Map<Integer, Integer> map = new TreeMap<>();  //Use treeMap for sorted keys else use a HashMap and then perform sort
		
    if (root == null)
			return ans;
		
    Queue<Pair> q = new LinkedList<>();         //Use a simple level order traversal but keep track of each column using a hashMap
		q.add(new Pair(0,root));
		while(!q.isEmpty()){
            Pair pair = q.poll();
            int column = pair.column;
            TreeNode node = pair.node;
      
            map.putIfAbsent(column,node);     //Add only first node on each column because all other nodes in that column will be blocked by top node
      
            if(node.left != null)
                q.offer(new Pair(column - 1, node.left));       //when going to left sub tree we reduce column number by 1
            if(node.right != null)      
                q.offer(new Pair(column + 1, node.right));      //when going to right sub tree we increase the column number by 1
        }
    
		for (int i : map.values())                  // traverse the TreeMap and store all the values in list to return 
			ans.add(i);                              //the values should be sorted by the column number to get right view from left to right direction
		
    return ans;
	}
}
