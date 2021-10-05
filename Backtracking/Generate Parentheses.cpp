class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        int open = n; //number of remaining open parenthesis
        int close = n; //number of remaining close parenthesis
        string temp = "";//initial state
        vector<string> res;
        
        generate(n,n,temp,res);
        
        return res;
        
    }
    
    void generate(int open,int close,string &temp,vector<string>& res)
    {
        if(!open&&!close)
        {
            res.push_back(temp);
            return;
        }
        
        if(open>0)
        {
            string temp1 = temp + "(";
            generate(open-1,close,temp1,res);
        }
        
        if(open<close)
        {
            string temp2 = temp + ")";//push ) only if more open parenthesis are utilized in making a solution
            generate(open,close-1,temp2,res);
        }
        
        
    }
};