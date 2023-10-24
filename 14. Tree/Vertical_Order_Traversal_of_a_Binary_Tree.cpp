class Solution {
public:
    void dfs(TreeNode* root,int wide,int level,map<int,map<int,multiset<int>>>& mp)
    {
        mp[wide][level].insert(root->val);   
        if(root->left)
            dfs(root->left,wide-1,level+1,mp);
        if(root->right)
            dfs(root->right,wide+1,level+1,mp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        vector<vector<int>> ans;
        if(root==nullptr)
            return ans;
        int level=0;
        int wide=0;
        dfs(root,wide,level,mp);
        
        for(auto x: mp)
        {
            vector<int> temp;
            for(auto i:x.second)
                for(auto y: i.second)
                    temp.push_back(y);
            ans.push_back(temp);
        }
        return ans;
    }
};