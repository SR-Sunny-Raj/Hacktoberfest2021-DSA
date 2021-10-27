/*
  Problem: There is a binary tree rooted at 0 consisting of n nodes. 
  The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing 
  the tree, where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.

  Each node has a score. To find the score of a node, consider if the node and the edges connected 
  to it were removed. The tree would become one or more non-empty subtrees. 
  The size of a subtree is the number of the nodes in it. 
  The score of the node is the product of the sizes of all those subtrees.

  Return the number of nodes that have the highest score.

  Example 1:
  Input: parents = [-1,2,0,2,0]
  Output: 3

  Input: parents = [-1,2,0]
  Output: 2
*/

class Solution {

    class Node {
        Node left;
        Node right;
        int value;
        
        Node(int value) {
            this.value = value;
        }
    }
    
    public int computeSize(int nodei, Node[] nodes, int[] size) {
        size[nodei] = 1;
        if(nodes[nodei].left != null) {
            size[nodei] += computeSize(nodes[nodei].left.value, nodes, size);
            
        }
        if(nodes[nodei].right != null) {
            size[nodei] += computeSize(nodes[nodei].right.value, nodes, size);
            
        }
        return size[nodei];
    }
    
    public int countHighestScoreNodes(int[] parents) {
        int n = parents.length;
        Node[] nodes = new Node[n];
        for(int i=0; i<n; i++) {
            nodes[i] = new Node(i);
        }
        
        for(int i=0; i<parents.length; i++) {
            if(parents[i] != -1) {
                int pnode = parents[i];
                if(nodes[pnode].left == null) {
                    nodes[pnode].left = nodes[i];
                } else {
                    nodes[pnode].right = nodes[i];
                }
            }
        }
        
        int[] size = new int[n];
        size[0] = computeSize(0, nodes, size);
        System.out.println(Arrays.toString(size));
        
        HashMap<Long, Integer> fre = new HashMap<>();
        long maxSize = 0L;
        
        for(int i=0; i<n; i++) {
            int node = i;
            int parent = parents[i];
            long csize = 1L;
            
            int sizeLeft = 0;
            int sizeRight = 0;
            
            if(nodes[node].left != null) {
                sizeLeft = size[nodes[node].left.value];
                csize = csize * (long)sizeLeft;
            }
            if(nodes[node].right != null) {
                sizeRight = size[nodes[node].right.value];
                csize = csize * (long)sizeRight;
            }
            if(parent != -1) {
                int sizeParent = n - 1 - sizeLeft - sizeRight;
                csize = csize * (long)sizeParent;
            }
            
            if(csize > maxSize) {
                maxSize = csize;
            }
            fre.put(csize, fre.getOrDefault(csize, 0) + 1);
            //System.out.println(node +" "+sizeLeft+" "+sizeRight+" "+csize);
        }
        
        
        return fre.get(maxSize);
    }
}