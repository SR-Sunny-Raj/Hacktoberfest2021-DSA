#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll i, n, imax, imin, maxp;
    cin >> n;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    imax = a[0], imin = a[0];
    maxp = a[0];
    for (i = 1; i < n; i++)
    {
        if (a[i] < 0)
            swap(imax, imin);
        imax = max(a[i], imax * a[i]);
        imin = min(a[i], imin * a[i]);
        if (maxp < imax)
            maxp = imax;
    }
    cout<< maxp;
    return 0;
}