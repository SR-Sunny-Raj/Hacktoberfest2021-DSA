class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board,0,0);
        
    }
    
    bool solve(vector<vector<char>>& board,int i,int j)
    {
        if(i==9)//reached beyond the last row of the board
            return true;
        
        if(j==9)//reached beyond the last column of the board
            return solve(board,i+1,0);
        
        
        if(board[i][j]!='.')//recur for next valid cell if the current cell is already filled
           return solve(board,i,j+1);
        
        else
        {
            for(char val = '1';val<='9';val++)
            {
                if(isValid(i,j,val,board))
                {
                    board[i][j] = val;
                    if(solve(board,i,j+1))//recur for next valid cell
                        return true;// returns true when the board is completely filled with all valid values
                    board[i][j] = '.';//board is restored to its original state when the current val in
                                      //cell (i,j) does not provides the final answer
                }
            }
        }
    // returns false when the we are unable to assign any val to an empty cell in the 
    // current state of the board
    return false;
    }
    
    
    bool isValid(int x,int y,char val,vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)//checking row
        {
            if(board[i][y]==val)
                return false;
        }
        
        for(int j=0;j<board[0].size();j++)//checking column
        {
            if(board[x][j]==val)
                return false;
        }
        
        int si = x/3 * 3;//staring row index of the sub square in which valis present 
        int sj = y/3 * 3;//staring column index of the sub square in which valis present 
        
        for(int i=0;i<3;i++)//checking sub square
        {
            for(int j=0;j<3;j++)
            {
                if(board[si+i][sj+j]==val)
                    return false;
            }
        }
        return true;
    }
};