#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll i, n, j, k, d, x, r;
    cin >> n >> x;
    ll a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (i = 0; i < n - 2; i++)
    {
        j = i + 1;
        k = n - 1;
        while (j < k)
        {
            d = a[i] + a[j] + a[k];
            if (d >= x)
                k--;
            else
            {
                r += (k - j);
                j++;
            }
        }
    }
    cout << r;
    return 0;
}