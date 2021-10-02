// problem link - https://leetcode.com/problems/n-queens/


class Solution {
public:

    char mat[10][10];

    vector<vector<string>> res;

    bool canPlace(int row, int column, int n) {

        int r = row - 1;

        while (r > -1) {
            if (mat[r][column] == 'Q') {
                return false;
            }
            r--;
        }

        r = row - 1; int c = column - 1;

        while (r > -1 && c > -1) {
            if (mat[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }

        r = row - 1, c = column + 1;

        while (r > -1 && c < n) {
            if (mat[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }

        return true;
    }

    void rec(int row, int n, vector<string> cur) {

        if (row == n) {
            res.push_back(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (canPlace(row, i, n)) {
                mat[row][i] = 'Q';
                string x = string(n, '.');
                x[i] = 'Q';
                cur.push_back(x);
                rec(row + 1, n, cur);
                mat[row][i] = '.';
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        memset(mat, '.', sizeof(mat));

        rec(0, n, vector<string>());

        return res;
    }
};