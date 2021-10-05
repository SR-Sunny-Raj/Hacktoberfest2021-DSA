#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        vector<vector<int>> ans;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == word[0] && isword(i, j, word, grid))
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
        // Code here
    }
    bool isword(int i, int j, string word, vector<vector<char>> grid)
    {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        int n = grid.size();
        int m = grid[0].size();
        for (auto dir : dirs)
        {
            int mini = i, minj = j;
            int c = 0;
            while (mini >= 0 && minj >= 0 && mini < n && minj < m && c < word.length() && grid[mini][minj] == word[c])
            {
                mini = mini + dir[0];
                minj = minj + dir[1];
                c++;
            }
            if (c == word.length())
            {
                return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
} // } Driver Code Ends