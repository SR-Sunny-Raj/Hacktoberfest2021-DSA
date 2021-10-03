#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, d;
    // cin >> t;
    cin >> n;
    long long a, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        ans += abs(a);
    }

    cout << ans << endl;
}