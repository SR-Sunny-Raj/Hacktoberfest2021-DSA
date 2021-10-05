class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> dict = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.size();
        string temp = "";
        vector<string> res;
        if(n==0)
            return res;
      
        
        solve(digits,dict,temp,res,n,0);
        
        return res;
    }
    
    void solve(string digits,vector<string> dict,string &temp,vector<string> &res,int n,
int start)
    {
        if(start>n)
            return;
        
        if(start==n&&temp.size()==n)
        {
            res.push_back(temp);
            return;
        }
        
        for(int i=start;i<n;i++) 
        {
            int idx = digits[i]-'0';
            
            for(int j=0;j<dict[idx].size();j++)
            {
                temp.push_back(dict[idx][j]);
                solve(digits,dict,temp,res,n,i+1);
                temp.pop_back();
            }
        }
    }
};