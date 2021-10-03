//Problem Link -: https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudokuHelper(int i, int j, vector<vector<char>>board) {
        int grp_num = 3 * (i / 3) + (j / 3);
        for (int k = 0; k < 9; k++) {
            if (board[i][j] == board[i][k] and j != k) {
                return false;
            }
        }
        for (int k = 0; k < 9; k++) {
            if (board[i][j] == board[k][j] and i != k) {
                return false;
            }
        }
        int new_i = 3 * (i / 3), new_j = 3 * (j / 3);
        for (int k = new_i; k < new_i + 3; k++) {
            for (int l = new_j; l < new_j + 3; l++) {
                if (k != i and l != j and board[k][l] == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.')
                    if (isValidSudokuHelper(i, j, board) == false)
                        return false;
            }
        }
        return true;
    }
};