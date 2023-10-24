class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
     vector<int> vec;
     inOrderTraversal(root,vec);
     return valid(vec);
    }
    void inOrderTraversal(TreeNode* root, vector<int> &v)
    {
        if(root==NULL)
        return;
        inOrderTraversal(root->left,v);
        v.push_back(root->val);
        inOrderTraversal(root->right,v);
    }
    bool valid(vector<int> v)
    {
    for(int i=1;i<v.size();i++)
    {
    if(v[i-1]>=v[i])
    return false;
    }
    return true;
    }
};
#Leetcode 98. Validate Binary Search Tree
