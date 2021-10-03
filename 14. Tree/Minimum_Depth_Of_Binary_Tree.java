Problem Statement:
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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

*BFS is better and DFS soluton because in dfs we have to travel all paths and return the minimum one's depth
But in level order traversal as soon as we get the first leaf node we return the depth upto it

//Recursive solution - Depth First Search
class Solution {
    public int minDepth(TreeNode root) {
        return traverse(root);
    }
    private int traverse(TreeNode root){
        if(root == null)
            return 0;
        if(root.left == null)
            return traverse(root.right)+1;          //important catch is that if any of the subtree is null we return
        if(root.right == null)                      // the depth of the non-null tree and not the minimum of both i.e 0
            return traverse(root.left)+1;           //hence these null checks are required
        return(Math.min(traverse(root.left),traverse(root.right))+1);
    }
}

//Recursive solution - Depth First Search - without helper function
class Solution {
    public int minDepth(TreeNode root) {
        if(root == null)
            return 0;
        if(root.left == null)
            return minDepth(root.right)+1;
        if(root.right == null)
            return minDepth(root.left)+1;
        return 1 + Math.min(minDepth(root.left),minDepth(root.right));
    }
}


//Iterative solution - Level Order Traversal/BFS using Queue
class Solution {
    public int minDepth(TreeNode root) {
        if(root==null)
            return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        int depth = 1;
        while(!q.isEmpty()){                  //classic bfs traversal with level tracking to keep track of depth
            int size = q.size();
            while(size-->0){
                TreeNode node = q.poll();
                if(node.left!=null)
                    q.offer(node.left);
                if(node.right!=null)
                    q.offer(node.right);
                if(node.left==null && node.right==null)   //if we get a leaf node we return the depth beacause that's the first leaf node 
                    return depth;                         //and since we are traversing level wise that the minimum depth
            }
            depth++;                  //after each level we increase the depth
        }
        return depth;
    }
}

//Iterative solution - Post Order Traversal using Stack
class Solution {
    public int minDepth(TreeNode root) {
        if(root==null)
            return 0;
        Deque<TreeNode> st = new ArrayDeque<>();
        Map<TreeNode, Integer> map = new HashMap<>();
        TreeNode prev = null, node = root;
        while(node != null || !st.isEmpty()){       
            while(node != null){
                st.push(node);
                node = node.left;
            }
            node = st.peek();                                 //classic post order traversal using extra node that keeps track of previous node
            if(node.right == null || node.right == prev){
                st.pop();
                prev = node;
                int h = 0;
                
                if(node.left == null)
                    h = map.getOrDefault(node.right,0) + 1;     //the only catch here is that we need to keep track of minimum depth of each node
                else if(node.right == null)                     //because its a dfs traversal hence we use a hashmap to store minimum depth of each node
                    h = map.getOrDefault(node.left,0) + 1;
                else h = Math.min(map.getOrDefault(node.left,0),                                                      
                
                map.getOrDefault(node.right,0)) + 1;
                map.put(prev,h);
                node = null;
            }
            else node = node.right;
        }
        return map.get(root); 
    }
}
