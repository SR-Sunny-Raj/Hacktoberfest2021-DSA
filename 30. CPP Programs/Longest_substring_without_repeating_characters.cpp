#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

int main()
{
    string s;
    cin >> s;

    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;

    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];

        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }

    cout << maxLen << endl;
    return 0;
}