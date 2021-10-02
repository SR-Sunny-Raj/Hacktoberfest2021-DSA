// Problem Statement: Given a binary tree, print the bottom view from left to right. A node is included in bottom view if it can be seen when we look at the tree from bottom.
//Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
//Solution is given below:

class Solution {
  public:
    map<int, vector<int>>mp;
    void func(Node* root, int i, int d)
    {
        if(root==NULL)
        return;
        
        if(mp.find(i)==mp.end())
        {
            vector<int>c = {root->data, d};
            mp[i]=c;
        // mp[i][1]=d;
        }
        else if(mp[i][1]<=d)
        {
            vector<int>c = {root->data, d};
            mp[i]=c;
        }
        
        func(root->left, i-1, d+1);
        func(root->right, i+1, d+1);
    }
    
//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
        vector<int>v;
        mp.clear();
        if(root==NULL)
        return v;
        
        func(root, 0, 0);
        
        for(auto i : mp)
        {
            vector<int>c = i.second;
            v.push_back(c[0]);
        }
        return v;
}
};
