/** 
 * You are given an array containing n positive integers.

Your task is to divide the array into k subarrays so that the maximum sum in a 
subarray is as small as possible.

Input

The first input line contains two integers n and k: 
the size of the array and the number of subarrays in the division.

The next line contains n integers x1,x2,…,xn: the contents of the array.

Output

Print one integer: the maximum sum in a subarray in the optimal division.

Constraints
1≤ n ≤2⋅10^5
1≤ k ≤n
1≤ x ≤ 10^9

Example--

Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the 
subarrays are 6,7,8. The largest sum is the last sum 8.
**/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define fast_io()                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    auto works = [&](ll mid)
    {
        ll sum = 0;
        int grp = 0;
        for (int i = 0; i < n; i++)
        {
            if (ar[i] > mid)
                return false;
            if (sum + ar[i] > mid)
                sum = 0, grp++;
            sum += ar[i];
        }

        if (sum > 0)
            grp++;
        return grp <= k;
    };

    ll l = 0, r = 1e18, ans = 0;
    while (l <= r)
    {
        ll mid = l + (r - l) / 2;

        if (works(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;
}

int main()
{
    fast_io();
    int t = 1;
    // cin >> t;

    clock_t p;
    p = clock();
    while (t--)
    {
        solve();
    }

    return 0;
}