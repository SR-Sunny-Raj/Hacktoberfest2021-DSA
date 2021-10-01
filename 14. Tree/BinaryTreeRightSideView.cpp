/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
    if(!root)
    return v;
    queue<TreeNode*>q;
    bool isFirst=true;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        TreeNode* temp=q.front();
        q.pop();
        if(!temp)
        {
           if(q.size()==0)
           break;
           q.push(NULL);
           isFirst=true;
        }
        else
        {
           if(isFirst)
           {
               v.push_back(temp->val);
               isFirst=false;
           }
        if(temp->right)
        q.push(temp->right);
        if(temp->left)
        q.push(temp->left);
        }
    }
    return v;
    }
};
