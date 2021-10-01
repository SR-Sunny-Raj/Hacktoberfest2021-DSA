class Solution {
public:
    bool isLeaf(TreeNode* root)
    {
        return root->left==nullptr && root->right==nullptr;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long leftMin,rightMin;
        unsigned long long diff;
        unsigned long long maxDif=0;
        if(isLeaf(root))
            return 1;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                pair<TreeNode*,unsigned long long> curNode=q.front();
                q.pop();
                if(i==0)
                    leftMin=curNode.second;
                if(i==n-1)
                    rightMin=curNode.second;
                if(curNode.first->left)
                    q.push({curNode.first->left,2*curNode.second});
                if(curNode.first->right)
                    q.push({curNode.first->right,2*curNode.second+1});
            }
            diff=rightMin-leftMin+1;
            maxDif=max(maxDif,diff);
        }
        return (int)maxDif;
    }
};