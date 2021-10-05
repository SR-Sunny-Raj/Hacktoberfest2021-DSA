class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n);
        
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i] = s;
        
        solve(ans,board,n,0);
        
        return ans;
        
    }
    void solve(vector<vector<string>> &ans,vector<string> &board,int n,int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        // Do not make nested for loops
				for(int row=0;row<n;row++)
        {
            if(isSafe(board,n,row,col))
            {
                board[row][col] = 'Q';
                solve(ans,board,n,col+1);
                board[row][col] = '.';
            }
        }
    }
    bool isSafe(vector<string> &board,int n,int row,int col)
    {
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row--;col--;
        }
        row = duprow;
        col = dupcol;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            col--;
        }
        row = duprow;
        col = dupcol;
        
        while(row<=n-1 and col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            
            row++;col--;
        }
        
        return true;
    }
};