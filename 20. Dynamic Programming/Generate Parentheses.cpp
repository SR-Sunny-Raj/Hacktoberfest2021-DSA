// ## Question : https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/?category[]=Recursion&category[]=Recursion&page=1&query=category[]Recursionpage1category[]Recursion#

// ### Solution Video : https://www.youtube.com/watch?v=eyCj_u3PoJE

// SOLUTION : (RECURSIVE AND ACCEPTED) 

// ```
class Solution
{
    vector<string> v;
    void solve(int open,int close,string op){
    if(open == 0 && close == 0){
        v.push_back(op);
        return;
    }
    
    if(open!=0){
        string op1=op;
        op1.push_back('(');
        solve(open-1,close,op1);
    }
    
    if(close>open){
        string op2=op;
        op2.push_back(')');
        solve(open,close-1,op2);
    }
}
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        int open=n;
        int close=n;
        string op ="";
        solve(open,close,op);
        return v;
    }
};
