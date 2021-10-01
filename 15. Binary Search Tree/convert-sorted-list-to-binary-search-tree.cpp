/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* a) 
    {
        if(!a) return NULL;
        vector<int> v;
        while(a!=NULL)
        {
            v.push_back(a->val);
            a=a->next;
        }
        return converted(v,0,v.size()-1);
    }
    TreeNode* converted(vector<int>&v,int st,int end)
    {
        if(st>end) return NULL;
        int mid=st+(end-st)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=converted(v,st,mid-1);
        
        root->right=converted(v,mid+1,end);
        return root;
    }
};
