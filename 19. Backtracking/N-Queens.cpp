#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, vector<string> Board, int n)
    {
        int rowcopy = row;
        int colcopy = col;

        while (row >= 0 && col >= 0)
        {
            if (Board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }
        row = rowcopy;
        col = colcopy;
        while (col >= 0)
        {
            if (Board[row][col] == 'Q')
                return false;
            col--;
        }
        row = rowcopy;
        col = colcopy;
        while (row < n && col >= 0)
        {
            if (Board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int col, int n, vector<string> &Board, vector<vector<string>> &ans)
    {
        if (col == n)
        {
            ans.push_back(Board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, Board, n))
            {
                Board[row][col] = 'Q';
                solve(col + 1, n, Board, ans);
                Board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> Board(n);
        for (int i = 0; i < n; i++)
            Board[i] = s;
        solve(0, n, Board, ans);
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution ob;
    vector<vector<string>> ans = ob.solveNQueens(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << ans[i][j] << "\n";
        }
        cout << "\n";
    }
}