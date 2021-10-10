#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    vector<int>a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    while (k--)
    {
        int value;
        cin >> value;
        int l = -1;
        int r = n;
        while (r > l + 1)
        {
            int mi = l + (r - l) / 2;
            if (value > a[mi])
                l = mi;
            else
                r = mi;
        }
        cout << r + 1 << endl;
    }



    return 0;
}
