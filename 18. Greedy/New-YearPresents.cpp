// Link problem : https://www.e-olymp.com/en/problems/26

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int> present1, vector<int> present2)
{
    return min(present1[0], present2[1]) < min(present2[0], present1[1]);
}

int main()
{
    int n;

    cin >> n;
    int time, ans = 0, temp = 0;

    vector<vector<int>> presents;

    for (int i = 0; i < n; i++)
    {
        vector<int> inp = {0, 0};
        presents.push_back(inp);
    }

    for (int i = 0; i < n * 2; i++)
    {
        cin >> time;
        presents[i % n][i / n] = time;
    }

    sort(presents.begin(), presents.end(), cmp);

    for (int i = 0; i < presents.size(); i++)
    {
        temp = temp + presents[i][0];
        ans = max(ans, temp) + presents[i][1];
    }

    cout << ans;

    return 0;
}