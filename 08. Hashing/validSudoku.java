/**  Problem Statement
 *   Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
        1. Each row must contain the digits 1-9 without repetition.
        2. Each column must contain the digits 1-9 without repetition.
        3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 *   Example 1:
        Input:
        [
          ["5","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],
          ["8",".",".",".","6",".",".",".","3"],
          ["4",".",".","8",".","3",".",".","1"],
          ["7",".",".",".","2",".",".",".","6"],
          [".","6",".",".",".",".","2","8","."],
          [".",".",".","4","1","9",".",".","5"],
          [".",".",".",".","8",".",".","7","9"]
        ]
        Output: true
     
     Example 2:
        Input:
        [
          ["8","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],
          ["8",".",".",".","6",".",".",".","3"],
          ["4",".",".","8",".","3",".",".","1"],
          ["7",".",".",".","2",".",".",".","6"],
          [".","6",".",".",".",".","2","8","."],
          [".",".",".","4","1","9",".",".","5"],
          [".",".",".",".","8",".",".","7","9"]
        ]
        Output: false
        Explanation: Same as Example 1, except with the 5 in the top left corner being 
        modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * 
 * 
 * */    
import java.util.*;
class Solution {
    public boolean isValidSudoku(char[][] board) {
        Set<String> set=new HashSet<>();
        String s="";
        for(int i=0;i<board.length;i++){    
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='.') continue;
                s=board[i][j]+"_R_"+i;
                if(set.contains(s)) return false;
                else set.add(s);
                s=board[i][j]+"_C_"+j;
                if(set.contains(s)) return false;
                else set.add(s);
                s=board[i][j]+"_B_"+i/3+"_"+j/3;
                if(set.contains(s)) return false;
                else set.add(s);
            }
        }
        return true;
    }
}
