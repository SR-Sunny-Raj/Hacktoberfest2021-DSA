/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
       if(!root)
       return NULL;
       if(root->val==p->val||root->val==q->val)
       return root;
       TreeNode* lt=lowestCommonAncestor(root->left,p,q);
       TreeNode* rt=lowestCommonAncestor(root->right,p,q);
       if(lt&&rt)
       return root;
       if(lt)
       return lt;
       if(rt)
       return rt;
       return NULL;
    }
};
