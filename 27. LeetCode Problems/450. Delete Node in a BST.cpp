/*

Problem Link - https://leetcode.com/problems/delete-node-in-a-bst/

Problem Statement - Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

* Search for a node to remove.
* If the node is found, delete the node.


Example

Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

*/


class Solution 
{
public:
    
    // To find the minimum value node in the right sub-tree
    TreeNode*  minValueNode(TreeNode* node)
    {
        TreeNode* cur=node->right;
        while(cur->left)
            cur=cur->left;
        
        return cur;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL)
            return NULL;
        
        //if key is greater, then check in right sub-tree
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        
         //if key is smaller, then check in left sub-tree
        else if(root->val>key)
            root->left=deleteNode(root->left,key);
        
        else
        {
            // if left or right sub-tree is not present, simply delete the node
            
            if(root->right==NULL)
            {
                TreeNode* temp=root->left;
                delete(root);
                return temp;
            }
             else if(root->left==NULL)
            {
                TreeNode* temp=root->right;
                delete(root);
                return temp;
            }
            
            // if both sub-trees are present then
            else
            {
                //find minimum value in right subtree and swap it with root
                TreeNode* temp=minValueNode(root);
                swap(temp->val,root->val);
                root->right=deleteNode(root->right,key);
            }
                
            
        }
             
            return root;
        
    }
    
};