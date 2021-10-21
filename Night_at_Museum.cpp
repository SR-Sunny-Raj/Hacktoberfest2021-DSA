//Ques Link --> https://codeforces.com/contest/731/problem/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    int ans = 0;
    for (int i = 0; i < input.size() - 1; i++)
    {
        int a = (int)(input[i + 1]) - (int)(input[i]);

        if (a < 0)
        {
            int y = (-1) * (a);
            int b = 26 - y;
            int o = min(y, b);
            ans = ans + o;
        }
        else
        {
            int b = 26 - a;
            int k = min(a, b);
            ans = ans + k;
        }
    }
    int x = ((int)(input[0]) - (int)('a'));
    int w = 26- x;
    ans = ans + min(x,w);
    cout << ans;
}