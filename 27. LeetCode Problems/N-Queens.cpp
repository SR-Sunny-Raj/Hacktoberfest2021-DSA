class Solution {
public:
    bool isSafe(int rows, int col, vector<string>& board, int n){
        //upper let diagonal
        int dup_row = rows;
        int dup_col = col;
        
        while(dup_row >= 0 && dup_col >= 0){
            if(board[dup_row][dup_col] == 'Q') return false;
            dup_row--;
            dup_col--;
        }
        //left
        dup_row = rows;
        dup_col = col;
        
        while(dup_col >= 0){
            if(board[dup_row][dup_col] == 'Q') return false;
            dup_col--;
        }
        
        //lower left diagonal
        dup_row = rows;
        dup_col = col;
        
        while(dup_row < n && dup_col >= 0){
            if(board[dup_row][dup_col] == 'Q') return false;
            dup_row++;
            dup_col--;
        }
        return true;
    }
    void recur(int col, vector<string>& board, int n, vector<vector<string>>& ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int rows = 0; rows < n; rows++){
            if(isSafe(rows, col, board, n)){
                board[rows][col] = 'Q';
                recur(col + 1, board, n, ans);
                board[rows][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)
            board[i] = s;
        recur(0, board, n, ans);
        return ans;
    }
};
