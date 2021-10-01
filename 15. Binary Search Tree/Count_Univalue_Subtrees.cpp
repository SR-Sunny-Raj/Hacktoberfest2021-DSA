/**
 Leetcode Problem : Count Univalue Subtrees
 Difficulty: Normal
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int countUnivalSubtrees(TreeNode * root) {
        // write your code here

        int count = 0;

        countUnivHelper(root, count);
        return count;
    }

    bool countUnivHelper(TreeNode *root, int &count){
       if(root == NULL){
           return true;
       }

       bool left = countUnivHelper(root->left, count);  //recursion
       bool right = countUnivHelper(root->right, count); //recursion

       if(left == false || right == false){
           return false;
       }

       if(root->left && root->val != root->left->val){
           return false;
       }

       if(root->right && root->val != root->right->val){
           return false;
       }

       count++;
       return true;
    }
};
