class Solution {
       
    public:
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        void fixbst(TreeNode* root)
        {
            if(root==NULL)
                return;
            fixbst(root->left);
            if(prev!=NULL && prev->val>root->val)
            {
                if(first==NULL)
                {
                    first=prev;
                }
                second=root;
            }
            prev=root;
            fixbst(root->right);
        }
        void recoverTree(TreeNode* root) {
            fixbst(root);
            swap(first->val,second->val);
        }
};
