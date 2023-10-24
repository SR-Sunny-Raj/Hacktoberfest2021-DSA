#include <bits/stdc++.h>
using namespace std;

vector<int> x{1, -1, 0, 0};
vector<int> y{0, 0, -1, 1};
vector<char> c{'D', 'U', 'L', 'R'};
int check(int i, int j, int n)
{
    if (i == -1 || j == -1 || i == n || j == n)
    {
        return 0;
    }
    return 1;
}

#define pi pair<int, int>

void dfs(vector<vector<int>> &m, vector<vector<int>> &visited, int i, int j, string &a,
         vector<string> &ans)
{
    int n = m.size();
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(a);
        return;
    }
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int p = i + x[k];
        int q = j + y[k];
        if (check(p, q, n) && visited[p][q] == 0 && m[p][q] == 1)
        {
            a.push_back(c[k]);
            dfs(m, visited, p, q, a, ans);
            a.pop_back();
        }
    }
    visited[i][j] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{

    vector<vector<int>> visited(n + 1, vector<int>(n + 1, 0));
    vector<string> ans;
    if (m[0][0] == 0)
    {
        return ans;
    }
    string a = "";
    dfs(m, visited, 0, 0, a, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}