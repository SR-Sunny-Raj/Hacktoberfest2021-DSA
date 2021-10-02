//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//Points to be kept in mind:
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        unordered_set<string> st;
        
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] != '.') 
                { 
                string row = "r"+ to_string(i)+string(1,board[i][j]);
                string col = "c"+ to_string(j)+string(1,board[i][j]);
                string box = "b"+to_string(i/3)+ to_string(j/3)+string(1,board[i][j]);
                if(st.find(row)!=st.end() ||
                    st.find(col)!=st.end()||
                    st.find(box)!=st.end())
                return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
            }
        }
        
        return true;
    }
};

