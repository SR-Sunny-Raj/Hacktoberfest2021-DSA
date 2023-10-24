class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> temp;
        vector<vector<int>> res;
        int start = 1;
        
        solve(n,k,temp,res,start);
        
        return res;
        
    }
    
    void solve(int n,int k,vector<int> &temp,vector<vector<int>> &res,int start)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }
        
        if(temp.size()>k)
        {
            
            return;
        }
        
        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            solve(n,k,temp,res,i+1);
            temp.pop_back();
        }
        
        
    }
};