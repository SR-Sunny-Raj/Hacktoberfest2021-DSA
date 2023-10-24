#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int val;
    Node* left, *right;
};


void recur(Node*root, int targetSum, int currentSum, vector<int>& currentPath, vector<vector<int>>& paths){
    if(root==NULL){
        return;
    }
    else{
        currentSum+=root->val;
        currentPath.push_back(root->val);
        if(!root->left and !root->right){
            if(currentSum==targetSum){
                paths.push_back(currentPath);
            }
        }
        else{
            recur(root->left, targetSum, currentSum, currentPath, paths);
            recur(root->right, targetSum, currentSum, currentPath, paths);
        }
        currentPath.pop_back();
    }

}
vector<vector<int>> pathSum(Node* root, int targetSum){
    vector<vector<int>> res;
    vector<int> v;
    recur(root, targetSum, 0, v, res);
    return res;
}